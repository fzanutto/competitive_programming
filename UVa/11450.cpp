#include <bits/stdc++.h>
using namespace std;


#define INF 0x3f3f3f3f
int roupas[25][25];
int C, M;
int dp[25][205];


int solve(int r, int m){

    if(m > M)
        return -INF; // if used more money than we have, return a really low number
         
    if(r == C)
        return m; // return amount of money used
    int &ans = dp[r][m];
       
    if(ans != -1)
        return ans;
    
    ans = -INF;
    
    for(int i=0; i<roupas[r][0]; i++){
        ans = max(ans, solve(r+1, m+roupas[r][i+1])); // get max possible answer
    }
    
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    while(n--){
        memset(roupas, 0, sizeof roupas);
        memset(dp, -1, sizeof dp);
        
        cin >> M >> C;
        
        for(int i=0; i<C; i++){
            cin >> roupas[i][0];
            for(int x=0; x<roupas[i][0]; x++)
                cin >> roupas[i][x+1];
        }
        
        
        int res = solve(0,0);
        
        if(res < 0){
            cout << "no solution" << endl; 
        } else {
            cout << res << endl;
        }
    }

}
