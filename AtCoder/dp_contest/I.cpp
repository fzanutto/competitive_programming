#include <bits/stdc++.h>


using namespace std;


double dp[3000][3000];
double chance[3000];

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++)
        cin >> chance[i];
    
    dp[0][0] = 1.0;
    
    // throwing ith coin
    for(int i=1; i<=n; i++){
        dp[i][0] = dp[i-1][0] * (1-chance[i-1]);
        // chance of in ith throw, getting j heads
        for(int j=1; j<=i; j++){
            // 
            dp[i][j] = dp[i-1][j-1] * chance[i-1] + dp[i-1][j] * (1.0-chance[i-1]);
        }
    
    }
    
    double sum = 0;
    
    for(int j=(n+1)/2; j<=n; j++){
        sum += dp[n][j];
    }
    cout << setprecision(10);
    cout << sum << endl;

}
