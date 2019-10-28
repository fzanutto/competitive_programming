#include <bits/stdc++.h>

using namespace std;

int h[100005];
int n;

int dp[100005];

int solve(int i){

    if (i >= n-1) return 0;
    
    if(dp[i] != -1){
        return dp[i];
    }
    
    int a = 1e9+7;
    int b = 1e9+7;

    a = solve(i+1) + abs(h[i]-h[i+1]);

    if(i < n-2){
        b = solve(i+2) + abs(h[i]-h[i+2]);
    }
    
    return dp[i] = min(a,b);

}


int main(){
    
    cin >> n;
    
    memset(dp, -1, sizeof(dp));
    
    for(int i=0; i<n;i++){
        cin >> h[i];
    }
        
    cout << solve(0) << endl;

}
