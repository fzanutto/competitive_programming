#include <bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
    return b == 0 ? a : gcd(b, a%b);
}

int lcm(int a, int b){
    return a * (b / gcd(a, b));
}


int main(){

    int r,b,k;
    int t;
    cin >> t;
    while(t--){
        
        cin >> r >> b >> k;
        if (r>b)
            swap(r,b);
            
        if (ceil((double)lcm(b,r) / r) > k && ceil(b/(double)r) > k){
            cout << "REBEL"<<endl;
        } else {
            cout << "OBEY" << endl;
        }
    }
}
