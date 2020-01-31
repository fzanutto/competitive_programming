#include <bits/stdc++.h>

using namespace std;


int main(){

    int t,a,b,c;
    cin >> t;
    
    while(t--){
    
    
        cin >> a >> b >> c;
        
        int x = min(b, c/2);
        int res = x*3;
        
        b -= x;
        
        x = min(a, b/2);
        
        res += x*3;
        
        cout << res << endl;
    
    }

}
