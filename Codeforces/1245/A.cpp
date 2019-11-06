#include <bits/stdc++.h>
using namespace std;

int main(){

    int a,b,g,t;
    
    cin >> t;
    while(t--){
        cin >> a >> b;
        
        g = __gcd(a,b);
        
        if (g == 1){
            cout << "finite" << endl;
        } else {
            cout << "infinite" << endl;
        }
    }

}
