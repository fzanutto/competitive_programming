#include <bits/stdc++.h>

using namespace std;
#define MAXN 50005
#define MAXLOGN 18

const int neutral = 0;

#define comp(a, b) ((a) + (b))

typedef pair<int, int> ii;
vector<ii> adjList[MAXN];
int level[MAXN], N;
int P[MAXN][MAXLOGN];
int D[MAXN][MAXLOGN];

void depthdfs(int u){
    for(int i=0; i<(int)adjList[u].size(); i++){
        int v = adjList[u][i].first;
        int w = adjList[u][i].second;
        if (v == P[u][0]) continue;
        P[v][0] = u;
        D[v][0] = w;
        
        level[v] = 1 + level[u];
        depthdfs(v);        
    }
}


void computeP(int root){
    level[root] = 0;
    P[root][0] = root;
    D[root][0] = neutral;
    depthdfs(root);
    for(int j=1; j<MAXLOGN; j++){
        for(int i=1; i<=N; i++){
            P[i][j] = P[P[i][j-1]][j-1];
            D[i][j] = comp(D[P[i][j-1]][j-1], D[i][j-1]);
        }
    
    }

}

ii LCA(int u, int v){
    if(level[u] > level[v]) swap(u,v);
    
    int d = level[v] - level[u];
    int ans = neutral;
    for(int i=0; i< MAXLOGN; i++){
        if(d & (1 << i)){
            ans = comp(ans, D[v][i]);
            v = P[v][i];
        }
    
    }
    if(u == v) return {u, ans};
    for(int i= MAXLOGN-1; i>=0; i--)
        while(P[u][i] != P[v][i]){
            ans = comp(ans, D[v][i]);
            ans = comp(ans, D[u][i]);
            u = P[u][i];
            v = P[v][i];
        }
    ans = comp(ans, D[v][0]);
    ans = comp(ans, D[u][0]);
    
    return {P[u][0], ans};
}


int main(){

    cin >> N;
    
    map<int, vector<int>> cartas;
    int folhas[N] = {};
    
    for(int i=0; i<N; i++){
        int a;
        cin >> a;
        cartas[a].push_back(i+1);
    }
    
    
    for(int i=0; i<N-1; i++){
        int a,b;
        cin >> a >> b;
        folhas[a]++;
        folhas[b]++;
        adjList[a].push_back({b,1});
        adjList[b].push_back({a,1});
    }

    int folha = 0;
    for(; folha<N; folha++){
        if(folhas[folha] == 1)
            break;
    }
    
    computeP(folha+1);
    
    int soma = 0;
    for(auto a: cartas){
    
        soma += LCA(a.second[0], a.second[1]).second;
    }

    cout << soma << endl;
}


