#include <bits/stdc++.h> 

using namespace std;
  
vector<long long> primes;
pair<long long,long long> ans = {10000000000000, 10000000000000};
long long n;

long long gcd(long long a, long long b){ 
    if (a == 0) 
        return b;  
    return gcd(b % a, a);  
 } 
  
   
// Function to return LCM of two numbers  
long long lcm(long long a, long long b)  
 {  
    return (a*b)/gcd(a, b);  
 } 
 
 
void primeFactors(long long n){

    // Print the number of 2s that divide n  
    while (n % 2 == 0){
        primes.push_back(2);
        n = n/2;   
    }  
  
    for (int i = 3; i <= sqrt(n); i = i + 2){

        while (n % i == 0){
            primes.push_back(i);
            n = n/i;  
        }  
    }
    
    if(n > 2)
        primes.push_back(n);
        
} 
  

long long calc(int i, long long a, long long b){
    //cout << "aa: " <<  a << " " << b << endl;
    if(i >= primes.size()){
    
        if(lcm(a,b) == n){
            //cout << i << " " << a << " " << b << endl;
            long long m1 = ans.first > ans.second ? ans.first : ans.second;
            long long m2 = max(a,b);
            
            if(m1 > m2)
                ans = {a,b};
            
            return max(a,b);
        } else
            return 0x3f3f3f3f;
    }
    long long r1 = calc(i+1, a*primes[i], b);
    long long r2 = calc(i+1, a, b*primes[i]);
    
    if(r1 < r2){
        return r1;
    } else {
        return r2;
    }
    

}


int main(){
    
    cin >> n;
    if(n == 1){
        cout << "1 1" << endl;
        return 0;
    }
    
    primeFactors(n);
    
    //cout << "size: " << primes.size() << endl;
    
    calc(1, primes[0], 1);

    cout << ans.first << " " << ans.second << endl;
    return 0;
}  
  
