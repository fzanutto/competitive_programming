#include <bits/stdc++.h>

using namespace std;

bitset<100001> prime;
vector<int> v;

int f(long long x, long long y){

    


}
void sieve(){
    long long n = 100000;
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
    
    long long x,n;
    
    cin >> x >> n;
    
    sieve();
    
    vector<int> fatores;
    
    for(int p : v){
    
        if(x % p == 0){
            fatores.push_back(p);
            while(x % p == 0){
                x = x/p;
            }
        }
    }
    
    long long res = 1;
    for(long long i : fatores){
        int expo = 1;
        long long temp = pow(i, expo);
        
        while(temp <= n){
            res *= f(x, temp);
            temp = pow(i, ++expo);
        }
    
    
    }
    
    
    
    
    
    if(x != 1) res++;
    
    cout << res << endl;

}
