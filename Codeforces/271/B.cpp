#include <bits/stdc++.h>

#define MAXN 10000009

using namespace std;

int matriz[501][501];
vector<int> primes;
bitset<MAXN> bs;

void sieve(){
    int size = 1e6+1;
    bs.set();
    bs[0] = bs[1] = 0;
    
    for(long long i=2; i<=size; i++){
        if(bs[i]){
            for(long long j=i*i; j <= size; j+=i){
                bs[j] = 0;
            }
            primes.push_back(i);
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    sieve();

    int n,m;
    int ans = 0x3f3f3f3f, cont = 0;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            int temp;
            cin >> temp;
            
            auto maior = lower_bound(primes.begin(), primes.end(), temp);
            auto menor = upper_bound(primes.begin(), primes.end(), temp);
            
            matriz[i][j] = min(abs(*maior-temp), abs(*menor-temp));
            cont += matriz[i][j];
        }
        ans = min(ans, cont);
        cont = 0;
    }
    
    for(int j=0; j<m; j++){
        cont = 0;
        for(int i=0; i<n; i++){
            cont += matriz[i][j];
        }
        ans = min(ans, cont);
    }
    
    cout << ans << endl;
}
