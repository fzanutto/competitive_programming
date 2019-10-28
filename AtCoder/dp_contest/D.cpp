#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll val[100005];
ll weight[100005];
int n, W;

ll dp[105][100005];

ll solve(int i, int w){

    if (i == n || w == 0) return 0;
    
    if(dp[i][w] != -1){
        return dp[i][w];
    }
    
    if(weight[i] <= w)
        return dp[i][w] = max(solve(i+1, w - weight[i]) + val[i], solve(i+1, w));
    else
        return dp[i][w] = solve(i+1, w);
}


int main(){
    
    
    cin >> n >> W;
    
    memset(dp, -1, sizeof(dp));
    
    for(ll i=0; i<n;i++){
        cin >> weight[i] >> val[i];
    }
        
    cout << solve(0,W) << endl;

}
