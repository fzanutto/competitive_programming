#include <bits/stdc++.h>


using namespace std;


int grafo[505][505];
int idades[505];
int idade;
int n,m,I;
int visitados[505];
void dfs(int v){
    
    for(int u=1; u<=n; u++)
        if(visitados[u]==0 && grafo[v][u] == 1){
            visitados[u] = 1;
            //cout << "a: " << u << endl;
            idade = min(idade, idades[u]);
            dfs(u);
        }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    while(cin >> n >> m >> I){
        memset(idades, 0, sizeof idades);
        memset(grafo, 0, sizeof grafo);
        for(int i=0; i<n; i++)
            cin >> idades[i+1];
            
        for(int i=0; i<m; i++){
            int a,b;
            cin >> a >> b;
            grafo[b][a] = 1;
        }


        for(int i=0; i<I; i++){
            char t;
            cin >> t;
            
            int a,b;
            cin >> a;
            if(t == 'P'){
                idade = 0x3f3f3f3f;
                memset(visitados, 0, sizeof visitados);
                dfs(a);
                
                if (idade == 0x3f3f3f3f)
                    cout << "*" << endl;
                else cout << idade << endl;
            
            } else {
                
                cin >> b;
                
                for(int i=1; i<=n; i++)
                    swap(grafo[i][a], grafo[i][b]);
                for(int i=1; i<=n; i++)
                    swap(grafo[a][i], grafo[b][i]);
            }        
        }
    }
}
