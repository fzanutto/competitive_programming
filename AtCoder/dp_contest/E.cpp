#include <bits/stdc++.h>
#define ll long long

using namespace std;

int val[101];
int weight[101];
int n, W;

int dp[105][100005];


int main(){
    
    cin >> n >> W;
    
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    
    for(int i=0; i<n;i++){
        cin >> weight[i] >> val[i];
    }
    
    dp[0][0] = 0;
    // we get min weigth possible to every possible value
    for(int i=1; i<=n; i++){
        dp[i][0] = 0;
        
        for(int v=1; v<100001; v++){
            // check if there is a combination of values that equal v            
            dp[i][v] = dp[i-1][v]; 
            
            if(v >= val[i-1]){

                dp[i][v] = min(dp[i][v], dp[i-1][v-val[i-1]] + weight[i-1]);
            }
        }
    }
        
    for(int v=100000; v>=0; v--){
    
        if(dp[n][v] <= W){
            cout << v << endl;
            return 0;
        }
    }

}
