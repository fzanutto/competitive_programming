#include <bits/stdc++.h>

using namespace std;

#define MAXN 2001
const int MOD = 1e9+7;

vector<int> adjList[MAXN];
int visitado[MAXN];
int ans;
int soma[MAXN];

void dfs(int u){
    visitado[u] = 1;
    
    if(adjList[u].size()){
        for(int i=0; i<(int)adjList[u].size(); i++){
            if(!visitado[adjList[u][i]])
                dfs(adjList[u][i]);
            soma[u] = (soma[u] + soma[adjList[u][i]]) % MOD;
        }
    } else {
        ans = (ans + 1) % MOD;
        soma[u] = 1;
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,l;
    cin >> n >> l;
    
    for(int i=0; i<l; i++){
        int m;
        cin >> m;
        
        for(int j=0; j<m; j++){
            int u;
            cin >> u;
            
            adjList[i].push_back(u-1);
        }
    
    }
    ans = 0;
    dfs(0);
    cout << soma[0] << " " << ans << endl;

}





