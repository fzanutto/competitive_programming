#include <bits/stdc++.h>

using namespace std;

#define MAXN 1000000
#define MOD 998244353 
long long fat[MAXN];

void preprocessfat(long long m){
    fat[0] = 1;
    for(long long i=1; i<MAXN; i++){
        fat[i] = (i * fat[i-1]) % m;
    }
    
}

long long extGcd(long long a, long long b, long long &x, long long &y){
    if(b == 0){
        x = 1, y = 0; 
        return a;
    }
    else {
        long long g = extGcd(b, a%b, y, x);
        y -= a / b * x; 
        return g;
    }
}


long long modInv(long long a, long long m){
    long long x,y;
    extGcd(a,m,x,y);
    return (x % m + m) % m;
}

long long modDiv(long long a, long long b, long long m){
    return ((a % m) * (long long)modInv(b,m)) % m;
}

long long choose(long long a, long long b){
    return modDiv(fat[a], (fat[b] * fat[a-b]) % MOD, MOD);
}

long long expo(long long a, long long b){
    if(b == 0) return 1;
    
    long long ans = expo(a, b/2);
    ans = (ans * ans) % MOD;
    
    if(b%2 == 1) ans = (ans * a) % MOD;
    
    return ans;
}

int main(){
    
    long long n,m;
    
    cin >> n >> m;
    
    preprocessfat(MOD);
    
    long long ans;
    
    if(n >= 3){
        ans = (((choose(m, n-1) * (n-2)) % MOD) * expo(2, n-3)) % MOD;
    } else    
        ans = 0;
        
    cout << ans << endl;
    
    

}
