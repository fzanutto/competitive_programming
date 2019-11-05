#include <bits/stdc++.h>

using namespace std;

long long fact(int n){

    if(n <= 1)
        return 1;
    return fact(n-1) * n;
}


int main(){
    
    int a,b;
    while(cin >> a >> b){
    
        cout << fact(a) + fact(b) << endl;
    }
    
    return 0;
}
