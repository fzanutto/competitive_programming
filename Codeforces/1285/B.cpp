#include <bits/stdc++.h>

using namespace std;


int main(){

    ios_base::sync_with_stdio(NULL);
    int t,n,temp;
    cin >> t;
    
    while(t--){
    
        vector<int> a;
        cin >> n;
        int total = 0;
        
        for(int i=0; i<n; i++){
            cin >> temp;
            a.push_back(temp);
            total += temp;
        }
        bool no = false;
        
        int soma_parcial = 0;
        for(int i=0; i<n; i++){
            if(a[i] < 0 && abs(a[i]) >= soma_parcial){
                no = true;
                break;
            }
            soma_parcial += a[i];
        }
        soma_parcial = 0;
        for(int i=n-1; i>=0; i--){
            if(a[i] < 0 && abs(a[i]) >= soma_parcial){
                no = true;
                break;
            }
            soma_parcial += a[i];
        }
        
        if(no){
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    
    }

    return 0; 
} 
