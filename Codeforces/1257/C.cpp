#include <bits/stdc++.h>
using namespace std;

int lista[200005];
int cont[200005];
int pos[200005];

int main(){

    int t;
    cin >> t;
    
    int n;
    
    while(t--){
        memset(cont, 0, sizeof cont);
        memset(pos, -1, sizeof pos);
        cin >> n;
       
        for(int i=0; i<n; i++)
            cin >> lista[i];
        
        if(n < 2)
            cout << -1 << endl;
            
        else{
            int m = n;
            bool ok = false;
            for(int i=0; i<n; i++){
                int num = lista[i];
                if (cont[num] > 0){
                    ok = true;
                    m = min(m, i-pos[num]+1);
                }
                pos[num] = i;
                cont[num]++;
            }
            if(ok)
                cout << m << endl;
            else
                cout << -1 << endl;
        
        }
    }
}
