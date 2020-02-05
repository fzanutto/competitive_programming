#include <bits/stdc++.h>
 
using namespace std;
 
struct trab {
    int indice;
    int dias;
    int prox;
    
    trab() {indice = 0; dias = 0; prox = 0; }
    
    trab(int i, int d, int p){indice = i; dias = d; prox = p; }
 
 
};
 
 
bool operator <(const trab &a, const trab &b){
    if(a.dias < b.dias){
        return true;
    }
    
    if(a.prox < b.prox){
        return true;
    }
    return a.indice < b.indice;
    
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m,w,h;
    
    cin >> m >> n >> w >> h;
    
    vector<int> trabalhadores(m), necessario_por_dia(n);
    
    set<pair<int, pair<int, int>>> fila; //  {dias que trabalha, {indice, prox dia que vai estar disponivel}}
    queue<pair<int, pair<int, int>>> parado;
    
    for(int i=0; i<m; i++){
        cin >> trabalhadores[i];
        fila.insert({-trabalhadores[i], {i, 0}});
 
    }
    
    for(int i=0; i<n; i++){
        cin >> necessario_por_dia[i];
    }
    
    vector<int> vai_sair(n+1, 0);
    vector<vector<int>> ans(m);
    int trabalhando = 0;
 
    for(int i=0; i<n; i++){ //dia atual
        //cout << "-----------" << endl << "dia: " << i << endl;
        while(parado.size() && parado.front().second.second <= i){
            fila.insert(parado.front());
            parado.pop();
        }
        //cout << "vai sair: " << vai_sair[i] << endl;
        trabalhando -= vai_sair[i];
        //cout << "trabalhando: " << trabalhando << endl;
        //cout << "necessario por dia: " << necessario_por_dia[i] << endl;
        for(int j=0; j<necessario_por_dia[i] - trabalhando; j++){ // pegando trabalhadores
 
            auto t = fila.begin();
            
            if(t == fila.end()){
                cout << "-1" << endl;
                return 0;
            }
                
            
            int dias_restando = -t->first;
            int indice = t->second.first;
            int prox_dia = t->second.second;
           // cout << "rest:" << dias_restando << " " << " indice: " << indice << " prox: " << prox_dia << endl;
            fila.erase(t); 
            
            if(dias_restando == 0 || prox_dia > i){
                cout << "-1" << endl;
                return 0;
            }
            
            parado.push({-(dias_restando-w), {indice, i+w+h}});
            ans[indice].push_back(i+1);
 
            vai_sair[i+w] += 1;
            
        }
        trabalhando = necessario_por_dia[i];
    }
 
 
    if(fila.begin()->first > 0){
        cout << "-1" << endl;
        return 0;
    }
    
    
    cout << 1 << endl;
    
    for(int i=0; i<m; i++){
        int j=0;
        for(j=0; j<ans[i].size()-1; j++){
            cout << ans[i][j] << " ";
        }
        cout << ans[i][j] << endl;
    }
    
    
 
}
