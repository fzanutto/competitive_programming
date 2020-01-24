#include <bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin >> t;
    
    int a,b;
    
    while(t--){
        cin >> a >> b;
       
        if(a>3 || (a <= 3 && b <= a) || (a==2 && b == 3)){
            cout << "YES" << endl;
        }
        
        else{
            cout << "NO" << endl;
        }
    }
}
