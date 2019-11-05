#include <bits/stdc++.h>
using namespace std;

int calc(int n){
    int cont = 1;
    
    while(n!= 1){
        cont++;
        if(n%2==0)
            n/=2;
        else
            n = 3*n + 1;
    }
    
    return cont;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int a,b;
    
    while(cin >> a >> b){
        int m = 0;
        for(int i=min(a,b); i<=max(a,b); i++){
            m = max(m, calc(i));
        
        }
        cout << a << " " << b << " " << m << endl;
    }

}
