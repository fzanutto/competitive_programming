#include <bits/stdc++.h>

#define ll long long
#define MAX int(3e5+10)

using namespace std;

int n;
int a[MAX];
int b[MAX];
ll dp[3][MAX];

ll calc(int add, int pos){

    if (pos == n) {
        dp[add][pos] = 0
        return dp[add][pos];
    }

    if (dp[add][pos] != -1){
        return dp[add][pos];
    }

    dp[add][pos] = (ll)1e18 + 100;

    for (int x = 0; x<3; x++){
        if (pos == 0 || a[pos] + x != a[pos-1] + add){
            dp[add][pos] = min(dp[add][pos], calc(x, pos+1) + x * b[pos]);

            
        }
    }
    return dp[add][pos];

}

int main(){
    int t;
    cin >> t;
    
    while(t--){
        cin >> n;
        for(int i=0; i < n; i++){
            cin >> a[i];
            cin >> b[i];
        }

        for(int i=0; i<= n; i++){
            dp[0][i] = dp[1][i] = dp[2][i] = -1;
        }
        cout << calc(0,0) << endl;
    }
    return 0;
}
