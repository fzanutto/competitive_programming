#include <bits/stdc++.h>

using namespace std;

int val[100005][3];
int n, k;

int dp[100005][3];

int solve(int i, int a){

    if (i == n) return 0;
    
    if(dp[i][a] != -1){
        return dp[i][a];
    }
    
    int ans = 0;

    for(int x=0; x<3; x++){
        if(x != a)
            ans = max(ans, solve(i+1, x) + val[i][a]);
    }
    
    return dp[i][a] = ans;

}


int main(){
    
    cin >> n;
    
    memset(dp, -1, sizeof(dp));
    
    for(int i=0; i<n;i++){
        cin >> val[i][0] >> val[i][1] >> val[i][2];
    }
        
    cout << max(max(solve(0,0), solve(0,1)), solve(0,2)) << endl;

}
