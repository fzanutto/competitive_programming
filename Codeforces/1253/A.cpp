#include <bits/stdc++.h>

using namespace std;
int a[100005], b[100005];

int solve(){

    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> a[i];
    for(int i=0; i<n; i++)
        cin >> b[i];
        
    int i;
    int dif = 0;
    int flag = 0;
    
    for(i=0; i<n; i++){
        if(a[i] > b[i]){
            cout << "NO" << endl;
            return 0;
        }
        
        if(a[i] < b[i]){
            flag = 1;
            if(dif == 0)
                dif = a[i] - b[i];
            
            a[i] -= dif;
        
        } else {
            if(flag)
                break;
        }
    }
    
    for(i=0; i<n; i++){
        if(a[i] != b[i]){
            cout << "NO" << endl;   
            return 0;
        }
    }
    cout << "YES" << endl;


}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int t;
    
    cin >> t;
    
    while(t--){
    
        solve();
    }
    
    
    return 0;

}
