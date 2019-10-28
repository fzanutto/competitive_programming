#include <bits/stdc++.h>
using namespace std;
#define MAXN 100002
#define level 17
vector <int> tree[MAXN];
map<pair<int,int>, int> dist;

int depth[MAXN] = {};
int parent[MAXN][level];
long long distancias[MAXN][level];
int n;

void imp_pais() {
    for(int i = 1; i<n+1; i++) {
        for(int j =0; j <= ceil(log(n)); j++) {
            cout << parent[i][j]-1 << "\t";
        }
        cout << endl;
    }
    cout << "\n\n\n";
    for(int i = 1; i<n+1; i++) {
        for(int j =0; j <= ceil(log(n)); j++) {
            cout << distancias[i][j] << "\t";
        }
        cout << endl;
    }
}
// pre-compute the depth for each node and their
// first parent(2^0th parent)
// time complexity : O(n)
void dfs(int cur, int prev){
    stack<pair<int,int>> stack_dfs;
    stack_dfs.push({cur, prev});
    do {
        pair<int, int> temp = stack_dfs.top();
        cur = temp.first;
        prev = temp.second;
        stack_dfs.pop();

        depth[cur] = depth[prev] + 1;
        parent[cur][0] = prev;
        distancias[cur][0] = dist[{cur,prev}];

        for (int i=0; i<tree[cur].size(); i++) {
            if (tree[cur][i] != prev)
                stack_dfs.push({tree[cur][i], cur});
        }
    } while (!stack_dfs.empty());
}

// Dynamic Programming Sparse Matrix Approach
// populating 2^i parent for each node
// Time complexity : O(nlogn)
void precomputeSparseMatrix(int n) {
    for (int i=1; i<level; i++) {
        for (int node = 1; node <= n; node++) {
            if (parent[node][i-1] != -1){
                parent[node][i] = parent[parent[node][i-1]][i-1];
                distancias[node][i] = distancias[parent[node][i-1]][i-1] + distancias[node][i-1];
            }
        }
    }
}

// Returning the LCA of u and v
// Time complexity : O(log n)
pair<int, long long> lca(int u, int v) {
    if (depth[v] < depth[u]) {
        swap(u, v);
    }

    int diff = depth[v] - depth[u];
    long long soma = 0;
    //cout << "V: ";
    // Step 1 of the pseudocode
    for (int i=0; i<level; i++) {
        //cout << v << " - ";
        if ((diff>>i)&1) {
            soma += distancias[v][i];
            v = parent[v][i];
        }
    }
    //cout << endl;
    // at this point depth[u] == depth[v]

    if (u == v) {
        return {u, soma};
    }

    // Step 2 of the pseudocode
    for (int i=level-1; i>=0; i--) {
        if (parent[u][i] != parent[v][i]) {
            soma += distancias[u][i];
            soma += distancias[v][i];
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    soma += distancias[u][0] + distancias[v][0];
    return {parent[u][0], soma};
}

void addEdge(int u, int v, int d) {
    tree[u].push_back(v);
    tree[v].push_back(u);
    dist[{u,v}] = d;
    dist[{v,u}] = d;
}

// driver function
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    while(cin >> n, n) {

        for(int i=0; i<n+1; i++){
            tree[i].clear();
        }

        memset(parent, -1, sizeof(parent));
        memset(depth, 0, sizeof(depth));

        map<int, int> folhas;

        int a,b,v;
        for(a=1; a<n; a++) {
            cin >> b >> v;
            addEdge(a+1, b+1, v);
            folhas[a+1] += 1;
            folhas[b+1] += 1;
        }

        //precisa começar o dfs por uma folha
        int j;
        for(j=1; j<=n; j++){
            if(folhas[j] == 1){
                break;
            }
        }

        dfs(tree[j][0], j);
        //cout << "p" << endl;
        precomputeSparseMatrix(n);
        //cout << "fim" << endl;
        //imp_pais();

        int q;
        cin >> q;

        while(q--) {
            cin >> a >> b;

            pair<int, long long> res = lca(a+1,b+1);
            cout << res.second;
            if(q){
                cout << " ";
            }
        }
        cout << endl;
    }
}
