#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int N,M;

int cost[1001]; //cost of each key
int key_treasure[1001]; // chests that each key open
int memo[1001][9000];
int total; // bits representing total number of chests

int dp(int key, int treasures){

    if (key == M){
        if(treasures == total) return 0;
        else return INF;
    }
    
    if(memo[key][treasures] != -1) return memo[key][treasures];

    int a = dp(key+1, treasures | key_treasure[key]) + cost[key];
    
    int b = dp(key+1, treasures);
    
    int ans = min(a,b);
    memo[key][treasures] = ans;
    
    return ans;
}


int main(){

    cin >> N >> M;
    memset(memo, -1, sizeof(memo));
    
    for(int i=0; i<N; i++){
        total |= 1 << i;
    }
    
    for(int i=0; i< M; i++){
        int key_cost, q;
        
        cin >> key_cost >> q;
        cost[i] = key_cost;

        int treasure;
        for(int x=0; x < q; x++){
            cin >> treasure;
            key_treasure[i] |= 1 << (treasure - 1);
        }
    
    }

    int ans = dp(0,0);
    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;

}
