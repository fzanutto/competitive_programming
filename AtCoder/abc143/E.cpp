#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll grafo[305][305];

void fw(int n, ll g[305][305]){
    
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(g[i][k] == -1 || g[k][j] == -1)
                    continue;
                
                ll new_dist = g[i][k] + g[k][j];
                
                if(g[i][j] == -1 || new_dist < g[i][j]){ 
                    g[i][j] = new_dist;
                }
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll n,m,l;
    int a,b,c;
    
    cin >> n >> m >> l;

    memset(grafo, -1, sizeof(grafo));
    
    for(int i=0; i<n; i++)
        grafo[i][i] = 0;
        
    while(m--){
        
        cin >> a >> b >> c;
        a--;
        b--;
        
        if(c <= l){
            grafo[a][b] = grafo[b][a] = c;
        }
    }
    
    fw(n, grafo);
    
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++)
            if(grafo[i][j] != -1 && grafo[i][j] <= l)
                grafo[i][j] = grafo[j][i] = 1;
            else
                grafo[i][j] = grafo[j][i] = -1;
    }
    
    fw(n, grafo);
    
    int q,s,t;
    cin >> q;
    while(q--){
    
        cin >> s >> t;
        s--; t--;
        if(grafo[s][t] != -1)
            cout << grafo[s][t]-1 << endl;
        else
            cout << -1 << endl;
    
    }

}

