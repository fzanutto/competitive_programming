#include <bits/stdc++.h>

using namespace std;

vector<int> s;

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i< n; i++){
        int temp;
        cin >> temp;
        s.push_back(temp);
    }
    
    sort(s.begin(), s.end());
    
    long long res = ((long long) n)*(n-1)*(n-2)/6;
    
    for(int i=0; i<n; i++){
        
        for(int j=i+1; j<n; j++){
            int a = s[i];
            int b = s[j];

            // look for lowest index that does not satisfies c < a+b
            auto x = lower_bound(s.begin(), s.end(), a+b);
            
            res -= s.end()-x;
        }
    }
    
    cout << res << endl;

}
