#include <bits/stdc++.h>

using namespace std;

const int M = (1 << 20);
int count[25][25];

int dp[1048576];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    string s;
    
    cin >> n >> m >> s;
    
    for(int i=1; i<n; i++){
        int x = s[i-1] - 'a';
        int y = s[i] - 'a';
        
        count[x][y]++;
        count[y][x]++;
    }
    
    memset(dp, 0x3f3f3f3f, sizeof dp);
    
    dp[0] = 0;
    
    for(int mask=1; mask<M; mask++){
        
    
    }
    
    
    
    
    
}
