#include <bits/stdc++.h>

using namespace std;

int v[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    if(n == 1 && v[0] == 1){
        cout << -1 << endl;
        return 0;
    }
    
    int ans = 0;
    int dp[100005] = {};
    
    pair<int,int> = {-1,0};
    for(int i=0; i<n; i++){
        
        if(v[i] == 1){
            
        } else {
            dp[i] = dp[i-1];
        }
    }
    
    
    
    return 0;

}
