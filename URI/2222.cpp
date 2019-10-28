#include <bits/stdc++.h>

using namespace std;

long long conjuntos[10005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t, n, q, tipo, x,y, tamanho;
    cin >> t;
    
    while(t--){
        
        cin >> n;
        
        for(int x=0; x<n; x++){
            conjuntos[x] = 0;
            cin >> tamanho;
            
            while(tamanho--){
                int numero;
                cin >> numero;

                conjuntos[x] |= (long long)(1LL << (numero-1));
            }
        }
        
        cin >> q;
        
        while(q--){
            cin >> tipo >> x >>  y;
            
            long long temp;
            
            if(tipo == 1)
                temp = conjuntos[x-1] & conjuntos[y-1];
            else
                temp = conjuntos[x-1] | conjuntos[y-1];

            cout << __builtin_popcountll(temp) << '\n';
        }
    }
}
