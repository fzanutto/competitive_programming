#include <bits/stdc++.h>

using namespace std;
const int MOD = 1e9+7;

long long exp(int ini, long long num, int n){

    if (n == 0) return 1;
    if (n == 1) return num;
    
    long long res = exp(ini, num, n>>1);
    res = (res * res) % MOD;
    
    if(n&1)
        res = (res * ini) % MOD;
        
    return res;
}

int main(){

    int n,m;
    
    cin >> n >> m;
    
    long long res = exp(2,2,m) - 1;

    res %= MOD;
    
    res = exp(res,res, n);
    
    cout << res << endl;

}
