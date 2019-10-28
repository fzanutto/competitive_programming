#include <bits/stdc++.h>


using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int t;
    cin >> t;
    int shows[1000005] = {};
    int a[200005];
    
    while(t--){
    
        int n,k,d;
        cin >> n >> k >> d;
        
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        
        
        memset(shows, 0, sizeof(shows));
        
        int cont = 0;
        int fim = 0;
        
        for(int i=0; i<n; i++){
            if (i >= d){
                if(shows[a[i-d]] > 1)
                    cont--;
                shows[a[i-d]]--;
            }
            
            shows[a[i]]++;
            
            if (shows[a[i]] > 1)
                cont++;
                
            fim = max(fim, cont);
        
        }
        
        cout << d-fim << endl;
        
    }

}
        
