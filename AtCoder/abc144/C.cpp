#include <bits/stdc++.h>

using namespace std;

vector<long long> v;


void divisors(long long n){
    for (long long i=1; i<=sqrt(n); i++){ 
        if (n%i == 0) 
        {
            if (n/i == i) 
                v.push_back(i);
  
            else {
                v.push_back(i);
                v.push_back(n/i);
            }
        } 
    } 
} 

int main(){
    
    
    long long n;
    cin >> n;
    
    
    
    divisors(n);
    long long t1,t2;
    int a = v.size();
    sort(v.begin(), v.end());
    if (a%2 == 0){
        t1 = v[a/2];
        t2 = v[(a/2)-1];
    } else {
        t1 = t2 = v[a/2];
    }
    //cout << t1 << " " << t2 << endl;
    
    cout << t1+t2-2 << endl;
}




