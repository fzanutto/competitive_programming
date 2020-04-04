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
    
    
    long long a;
    
    cin >> a;
    long long b = a;
    int res = 0;
    sieve();
    
    vector<long long> div;
    
    for(int p:v){
        
        if(a % p == 0){
            res++;
            div.push_back(p);
            while(a % p == 0) a = a/p;
        }
    }
    
    if(a>1)
        div.push_back(b);
    
    if(div.size()==1)
        cout << div[0] << endl;
    else
        cout << 1 << endl;

}
