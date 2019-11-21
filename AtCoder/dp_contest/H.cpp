#include <bits/stdc++.h>

const int MOD = 1e9+7;
using namespace std;

long long dp[10001][10001];

int main(){
    
    int n, m;
    cin >> n >> m;
    
    char temp;
    dp[0][1] = 1;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> temp;
            
            if(temp == '.')
                dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % MOD;
            else
                dp[i][j] = 0;
        }
    }
    
 
    cout << dp[n][m] << endl;

}
