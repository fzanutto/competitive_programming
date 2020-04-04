#include <bits/stdc++.h>

using namespace std;


vector<int> portas[100001];
int status[100001];

vector<int> adjlist[200005];
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

int N,m,n;

void dfs1(int v) {
    used[v] = true;
    for (int u : adjlist[v]) {
        if (!used[u])
            dfs1(u);
    }
    order.push_back(v);
}

void dfs2(int v, int cl) {
    comp[v] = cl;
    for (int u : adjlist[v]) {
        if (comp[u] == -1)
            dfs2(u, cl);
    }
}

bool solve() {
    used.assign(n+1, false);
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1])
            return false;
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

int main(){
	
	cin >> N >> m;
	n = (m*2)+2;
	
	for(int i=0; i<N; i++){
		cin >> status[i];
	}
	
	for(int i=0; i<m; i++){
		int q;
		cin >> q;
		
		for(int j=0; j<q; j++){
			int p;
			cin >> p;
			portas[p-1].push_back(i);
		}
	}
	
	int NOT = 1;
	for(int i=0; i<N; i++){
		
		int p = (portas[i][0]+1)*2;
		int q = (portas[i][1]+1)*2;
		
		if(status[i]){
			// not xor
			//cout << "~(" << p <<  " xor " << q << ")" << endl;
			//(not p or q) and (p or not q)
			adjlist[p].push_back(q);
			adjlist[q+NOT].push_back(p+NOT);
			adjlist[p+NOT].push_back(q+NOT);
			adjlist[q].push_back(p);
			
		} else {
			// xor
			//cout << "" << p <<  " xor " << q << "" << endl;
			//(p or q) and (not p or not q)
			
			adjlist[p+NOT].push_back(q);
			adjlist[q+NOT].push_back(p);
			adjlist[p].push_back(q+NOT);
			adjlist[q].push_back(p+NOT);
		}
	}
	if(solve())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

}