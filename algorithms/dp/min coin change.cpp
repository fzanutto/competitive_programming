#include<bits/stdc++.h>

using namespace std;

int dp[1000005];
int value[30];
int N,V;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        cin >> N >> V;
        
        memset(dp, 0x3f3f3f3f, sizeof dp);
        
        for(int i=0; i<N; i++){
            cin >> value[i];
        }
        
        dp[0] = 0;
        
        for(int i=1; i<=V; i++){
            for(int j=0; j<N; j++){
                if(i >= value[j]){
                    dp[i] = min(dp[i], dp[i-value[j]] + 1);
                }
            }
        }
        cout << dp[V] << endl;
    }
    
    
    return 0;

}
