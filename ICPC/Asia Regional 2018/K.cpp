#include <bits/stdc++.h>

using namespace std;


vector<pair<int,int>> participantes[10001];

vector<int> adjlist[100005], adjlistT[100005];
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
    for (int u : adjlistT[v]) {
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
        if (comp[i] == comp[i + 1]){
            return false;
            
        }
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

int main(){
	
	cin >> N >> m;
	n = (N*2);
	
	for(int i=0; i<m; i++){
	
		for(int j=0; j<3; j++){
		
			int p;
			char t;
			cin >> p >> t;

            participantes[i].push_back({p-1, t});			
		}
	}

	for(int i=0; i<m; i++){

		pair<int, char> p,q,r;
		
		p = participantes[i][0];
		q = participantes[i][1];
		r = participantes[i][2];
		
		int p1 = p.first*2;
		int q1 = q.first*2;
		int r1 = r.first*2;
		
		char p2 = p.second;
		char r2 = r.second;
		char q2 = q.second;
        
        //cout << (p1 + (p2 == 'B' ? 1 : 0)) << " " << (q1 + (q2 == 'B' ? 1 : 0)) << " " << (r1 + (r2 == 'B' ? 1 : 0)) << endl;
        
        adjlist[p1 + (p2 == 'R' ? 1 : 0)].push_back(q1 + (q2 == 'B' ? 1 : 0));
        adjlistT[q1 + (q2 == 'B' ? 1 : 0)].push_back(p1 + (p2 == 'R' ? 1 : 0));
        
        adjlist[p1 + (p2 == 'R' ? 1 : 0)].push_back(r1 + (r2 == 'B' ? 1 : 0));
        adjlistT[r1 + (r2 == 'B' ? 1 : 0)].push_back(p1 + (p2 == 'R' ? 1 : 0));
        
        adjlist[q1 + (q2 == 'R' ? 1 : 0)].push_back(p1 + (p2 == 'B' ? 1 : 0));
        adjlistT[p1 + (p2 == 'B' ? 1 : 0)].push_back(q1 + (q2 == 'R' ? 1 : 0));
        
        adjlist[q1 + (q2 == 'R' ? 1 : 0)].push_back(r1 + (r2 == 'B' ? 1 : 0));
        adjlistT[r1 + (r2 == 'B' ? 1 : 0)].push_back(q1 + (q2 == 'R' ? 1 : 0));
        
        adjlist[r1 + (r2 == 'R' ? 1 : 0)].push_back(q1 + (q2 == 'B' ? 1 : 0));
        adjlistT[q1 + (q2 == 'B' ? 1 : 0)].push_back(r1 + (r2 == 'R' ? 1 : 0));
        
        adjlist[r1 + (r2 == 'R' ? 1 : 0)].push_back(p1 + (p2 == 'B' ? 1 : 0));
        adjlistT[p1 + (p2 == 'B' ? 1 : 0)].push_back(r1 + (r2 == 'R' ? 1 : 0));
	}
	
	if(solve()){
		for (int i = 0; i < n; i += 2) {
		    if(assignment[i/2]){
		        cout << "R";
		    } else 
		        cout << "B";
        }
        cout << endl;
	} else
		cout << "-1" << endl;

}
