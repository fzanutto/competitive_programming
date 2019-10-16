#include <bits/stdc++.h>

#define ll long long
#define MAX int(3e5+10)

using namespace std;


int n;
int a[MAX];
int b[MAX];
ll dp[MAX][3];

ll calc(int pos, int add){
    
    ll &res = dp[pos][add];
    
    if (res != -1)
        return res;
        
    res = (ll)1e18 + 100;

    if(pos == n) 
        return res = 0;
        
    for(ll i=0; i<3; i++){
        // if we're at pos 0 or 
        // if current pos + what we are adding now is different from last pos + what we added to it
        if(pos == 0 || a[pos] + i != a[pos - 1] + add)
            // we pass to the next state the next position and the added value to the current position
            res = min(res, calc(pos + 1, i) + i * b[pos]);
    }

    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    
    while(t--){
        cin >> n;
        for(int i=0; i < n; i++){
            cin >> a[i];
            cin >> b[i];
        }

        for(int i=0; i <= n; i++){
            dp[i][0] = dp[i][1] = dp[i][2] = -1;
        }
        
        cout << calc(0,0) << "\n";
    }
    return 0;
}
