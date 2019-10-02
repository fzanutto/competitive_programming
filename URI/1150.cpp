#include <bits/stdc++.h>


using namespace std;


int main(){

    int a,x;
    
    cin >> a >> x;
    
    while(x <= a){
        cin >> x;
    }
    
    int res = 1;
    int cont = a;
    while(cont < x){
        a = a + 1;
        cont += a;
        res += 1;
    }
    
    cout << res << endl;

}
