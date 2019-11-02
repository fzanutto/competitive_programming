#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int memo[100005];

int fact(int n){
    return (n <= 1 ) ? 1 : ((fact(n-1) * n) % MOD);
}

int calc(int n){
    //cout << "somatario, n="<< n << endl;
    int res = 0;
    
    for(int i=0; i <= n/2; i++){
        res += fact(n-i) / fact(n-(2*i)) / fact(i);
    }
    //cout << "res: " << res << endl;
    return res;

}

void precompute(){
    memo[0] = 0;
    memo[1] = 1;
    memo[2] = 2;
    
    for(int i=3; i<100005; i++){
        memo[i] = ((memo[i-1]%MOD) + (memo[i-2]%MOD))%MOD;
    }
}


int main(){
    precompute();
    string s;
    
    cin >> s;
    
    s += ' ';
    
    char c = s[0];
    
    int cont = (int)(s[0] == 'n' || s[0] == 'u');
    if(s[0] == 'm' || s[0] == 'w'){
        cout << 0 << endl;
        return 0;
    }    
     
    int f = 1;
    
    for(int i=1; i<(int)s.size(); i++){
        if(s[i] == 'm' || s[i] == 'w'){
            cout << 0 << endl;
            return 0;
        }
        
        if(s[i] != c){
            if(cont > 0){
                long long temp = (long long)f * memo[cont];
                f = temp % MOD;
            }
            cont = (int)(s[i] == 'n' || s[i] == 'u');
            c = s[i];
        } else if(s[i] == 'n' || s[i] == 'u') cont++;
    }
    
    cout << f << endl;
}
