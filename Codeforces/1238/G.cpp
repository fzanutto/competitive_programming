#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int testes;
    
    cin >> testes;
    
    while(testes--){
        map<int, int> agua;
        map<int, vector<pair<int,int>>> amigos;
       
        int n,m,c,c0;
       
        cin >> n >> m >> c >> c0;
        //c = max capacity
        //c0 = initial value
       
        int total = c0;
        
        long long valor = 0;
        int anterior = 0;
        int falta;
        
        for(int i=0; i < n; i++){
            int t,a,b;
            cin >> t >> a >> b;
            amigos[t].push_back({a,b});
        }
        
        for(auto x = amigos.begin(); x!=amigos.end(); x++){
            int t,a,b;
            
            t = x->first;
            
            c0 -= (t - anterior);
            total -= (t-anterior);
            
            for(pair<int,int> amigo : x->second){
                a = amigo.first;
                b = amigo.second;
                
                agua[b] += a;

                total += a; // total armazenado no map;
                
                while(total > c){
                    
                    auto maior = agua.end();
                    maior--;
                    
                    if(maior->second <= total-c){
                        total -= maior->second;
                        agua.erase(maior);
                    }
                    else {
                        maior->second -= total-c;
                        total = c;
                    }
                }
            }
            
            if(c0 < 0){
                valor = -1;
                break;
            }
            
            int prox = m-t;
            x++;
            if(x != amigos.end()){
                prox = x->first - t;
            }
            x--;
            
            falta = min(m-t-c0, prox-c0);        
            
            while(falta > 0 && !agua.empty()){
                auto menor = agua.begin();
                if(menor->second <= falta){
                    c0 += menor->second;
                    falta -= menor->second;
                    valor += (long long)menor->first * menor->second;
                    agua.erase(menor);
                } else {
                    c0 += falta;
                    menor->second -= falta;
                    valor += (long long)menor->first * falta;
                    falta = 0;
                }
            }

            anterior = t;
        }
        
        c0 -= (m - anterior);
        if(c0 < 0)
            valor = -1;
        
        cout << valor << endl;
    }
}
