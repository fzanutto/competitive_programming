#include <bits/stdc++.h>

using namespace std;

int v[100005];

int main(){

    int n, t;
    
    cin >> n >> t;
    
    
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    
    int l=0, r=0;
    int sum = 0;
    int m = 0;
    
    while(r < n){
        
        if(sum + v[r] <= t){
            sum += v[r];
            m = max(m, r-l+1);            
            r += 1;            
        } else {
            if(l < r)
                sum -= v[l];
            l+=1;
            r = max(r, l);
        }
    }
    
    cout << m << endl;
    
}
