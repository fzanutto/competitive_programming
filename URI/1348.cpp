#include <bits/stdc++.h>

using namespace std;

vector<int> adjlist[20002], adjlistT[20002]; //adjlist and transpose adjlist
vector<bool> used;
vector<int> order, comp;
vector<bool> assignment;

int n; // number of nodes
// 2i = true/false value of node
// 2i+1 = false/true value of node

void add(int v, int u){
    //cout << v << " - " << u << endl;
    adjlist[v].push_back(u);
    adjlistT[u].push_back(v);
}

// toposort
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
    order.clear();
    
    for (int i = 0; i < n; ++i) {
        if (!used[i])
            dfs1(i);
    }

    comp.assign(n, -1);
    for (int i = 0, j = 0; i < n; ++i) {
        int v = order[n - i - 1];
        // find out which component every node belongs to
        if (comp[v] == -1)
            dfs2(v, j++);
    }

    assignment.assign(n / 2, false);
    for (int i = 0; i < n; i += 2) {
        if (comp[i] == comp[i + 1]){
            // if the node and its 'not' form is in the same component, we can't satisfy the problem
            return false;
        }
        // as comp[v] <= comp[u] means whe can reach u from v, 
        // we say that if we can't reach the false from the true, the answer can be true
        assignment[i / 2] = comp[i] > comp[i + 1];
    }
    return true;
}

int main(){

    int c,p;
    
    while(1){
        // c = number of clients
        // p = number of products
        cin >> c >> p;
        
        if(c == 0) return 0;
        
        n = p*2 + 2;
        
        for(int i=0; i<10001; i++){
            adjlist[i].clear();
            adjlistT[i].clear();
        }
        
        for(int i=0; i<c; i++){
            int x,y,s,t;
            
            cin >> x >> y >> s >> t;
            
            if(x != 0 || y != 0){
                x*=2;
                y*=2;
            
                if(x == 0) x = y;
                if(y == 0) y = x;
                
                add(x+1, y);
                add(y+1, x);
            }
            
            if(s != 0 || t != 0){
                s*=2;
                t*=2;
                
                if(s == 0) s = t;
                if(t == 0) t = s;
                
                add(s, t+1);
                add(t, s+1);
            }
        }
    
        if(solve()){
            cout << "yes" << endl;
	    } else
		    cout << "no" << endl;
    
    
    }

}
