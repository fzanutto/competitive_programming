#include <bits/stdc++.h>

using namespace std;

bitset<1000001> prime;
vector<int> v;


void sieve(){
    long long n = 1000000;
    prime.set();

    prime[0] = prime[1] = 0;
    
    for (long long p=2; p<=n; p++){
        if (prime[p]){
            v.push_back(p);
            for (long long i=p*p; i<=n; i += p)
                prime[i] = 0;
        }
    } 
}

int main(){
    
    
    long long a,b;
    
    cin >> a >> b;
    long long x = __gcd(a,b);
    int res = 1;
    sieve();
    
    for(int p:v){
    
        if(x % p == 0){
            res++;
            while(x % p == 0) x = x/p;
        }
    
    
    }
    
    if(x != 1) res++;
    
    cout << res << endl;

}
