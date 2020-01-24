#include <bits/stdc++.h>
#define MAXN 200005

using namespace std;

vector<int> pre,mid,suf;
set<int> cont[3];
int dp[MAXN][3];
int n;

int solve(int i, int j){

    if(i == n)
        return 0;
    if(dp[i][j] != 0x3f3f3f3f)
        return dp[i][j];
        
    int ans = 0x3f3f3f3f;
    for(int x=j; x<3; x++){
        ans = min(ans, cont[x].count(i+1) ? solve(i+1, x) : solve(i+1, x) + 1);
    }
    
    return dp[i][j] = ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, 0x3f3f3f3f, sizeof dp);
    
    int k1,k2,k3;
    
    cin >> k1 >> k2 >> k3;
    n = k1+k2+k3;
    
    int temp;
    for(int i=0; i<k1; i++){
        cin >> temp;
        pre.push_back(temp);
    }
    for(int i=0; i<k2; i++){
        cin >> temp;
        mid.push_back(temp);
    }
    for(int i=0; i<k3; i++){
        cin >> temp;
        suf.push_back(temp);
    }
    
    sort(pre.begin(), pre.end());
    sort(mid.begin(), mid.end());
    sort(suf.begin(), suf.end());
    
    cont[0] = set<int>(pre.begin(), pre.end());
    cont[1] = set<int>(mid.begin(), mid.end());
    cont[2] = set<int>(suf.begin(), suf.end());
    
   
    cout << solve(0,0) << endl;
        
}
