#include <bits/stdc++.h>

using namespace std;

int main(){

    int testes,h,n;
    
    cin >> testes;
    
    while(testes--){
 
        cin >> h >> n;

        vector<int> ativos(n+1);

        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            ativos[i] = temp;
        }
        

        int cont = 0;
        int temp = 1;
        bool inicio = true;
        
        for(int i=0; i<n; i++){
            //cout << ativos[i] << " - " << ativos[i+1] << endl;
            if(ativos[i] - ativos[i+1] == 1){
                temp++;
            } else {
                //cout << "temp: " << temp << " inicio: " << inicio << " " << ativos[i] << endl;
                if(temp % 2 == 1 && !inicio && ativos[i]!=1){
                    //cout << "cont++"<<endl;
                    cont++;
                }
                else if(temp%2 == 0 && inicio && ativos[i]!=1){
                    //cout << "aaaaa"<<endl;
                    cont++;   
                    
                }
                inicio = false;
                temp = 1;
            }
        }
        
        cout << cont << endl;
    }
}
    
    
