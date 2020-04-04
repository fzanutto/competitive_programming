#include<bits/stdc++.h>


using namespace std;

int visited[200001];
int adjlist[200001];
int componente[200001];
int folha[200001];
vector<int> ciclos;
int componentes = 0;
int ok[200001];

int dfs(int u){

    visited[u] = 1;
    
    if(visited[adjlist[u]] == 0){
        return componente[u] = dfs(adjlist[u]);
    }
    else {
        if(componente[adjlist[u]] != 0){
            return componente[u] = componente[adjlist[u]];
        }
        else{
            //cout << "nova componente: " << u+1 << " " << adjlist[u]+1 << endl;
            ciclos.push_back(adjlist[u]);
            return componente[u] = componente[adjlist[u]] = ++componentes;
        }
    }
}

int main(){
    int n;
    cin >> n;
    
    int temp;
    vector<pair<int,int>> ans;
    memset(folha, 1, sizeof folha);
    
    for(int i=0; i<n; i++){
        cin >> temp;
        adjlist[i] = temp-1;
        folha[temp-1] = 0;
    }
    
   
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    
    //cout << "ciclos: " << ciclos.size() << endl;
    
    for(int i=0; i<n; i++){
        if(folha[i]){
            int componente_folha = componente[i];
            
            //cout << "componente da folha: " << componente_folha << endl;
            
            if(componente_folha == 1){
                ans.push_back({ciclos[ciclos.size()-1]+1, i+1});
            } else {
                ans.push_back({ciclos[componente_folha-2]+1, i+1});
            }
            ok[componente_folha] = 1;
        }
    }
    //cout << "tot componentes: " << componentes << endl;
    for(int i=1; componentes>1 && i<=componentes; i++){
        if(ok[i] == 0){ // ok é que o compomente conexo de indice i ja foi conectado com o resto
            //cout << "comp " << i << endl;
            if(i == 1)
                ans.push_back({ciclos[ciclos.size()-1]+1, ciclos[i-1]+1});
            else
                ans.push_back({ciclos[i-2]+1, ciclos[i-1]+1});
        }
    }
    
    cout << ans.size() << endl;
    for(auto p: ans){
        cout << p.first << " " << p.second << endl;
    }

}
