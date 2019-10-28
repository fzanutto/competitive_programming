#include <bits/stdc++.h>

using namespace std;

int h[100005];
int n, k;

int dp[100005];

int solve(int i){

    if (i >= n-1) return 0;
    
    if(dp[i] != -1){
        return dp[i];
    }
    
    int ans = 1e9+7;

    for(int x=1; x<=k; x++){
        if(i < n-x)
            ans = min(ans, solve(i+x) + abs(h[i] - h[i+x]));
    }
    
    return dp[i] = ans;

}


int main(){
    
    cin >> n >> k;
    
    memset(dp, -1, sizeof(dp));
    
    for(int i=0; i<n;i++){
        cin >> h[i];
    }
        
    cout << solve(0) << endl;

}
