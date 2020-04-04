#include <bits/stdc++.h>

using namespace std;

long long lcm(long long a, long long b){
    return (a*b) / __gcd(a,b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    
    cin >> n >> k;
    
    vector<int> lista(n);
    
    for(int i=0; i<n; i++){
        cin >> lista[i];
    }

    long long aux = __gcd(lista[0],k);
    
    for(int i=1; i<n; i++){
        aux = lcm(__gcd(lista[i], k), aux);
    }
    
    if(aux % k == 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    
    return 0;

}
