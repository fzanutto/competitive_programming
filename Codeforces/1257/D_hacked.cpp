#include <bits/stdc++.h>
using namespace std;

pair<int,int> heroes[200005];
int monsters[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    
    int n;
    int m,h;
    
    while(t--){
        cin >> m;
        for(int i=0; i<m; i++){
            cin >> monsters[i];
        }
        
        cin >> h;
        for(int i=0; i<h; i++){
            int x,y;
            cin >> x >> y;
            heroes[i] = {x,y};
        }
        
        int k = 0; //num killed monsters
        int dias = 0;
        
        while(k < m){

            ++dias;
            int maior = 0; //max monters i can kill this day
            int cont = 0;
            
            for(int i=0; i<h; i++){
                cont = 0;
                //cout << "força: " << heroes[i].first << " qtd: " << heroes[i].second << endl;
                for(int j=k; j<m; j++){
                    //cout << heroes[i].first << " " << heroes[i].second << endl;
                    if(monsters[j] <= heroes[i].first){
                        cont++;
                        maior = max(maior, cont);
                    } else {
                        break;
                    }
                    
                    if(cont == heroes[i].second){
                        break;
                    }
                }
            
            }
            //cout << k << " maior: " << maior << endl;
            if(maior == 0){
                dias = -1;
                break;
            }
            k += maior;
        
        }
        
        cout << dias << endl;
        
        
    }
}
