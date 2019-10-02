#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;


int dist[105][105][105];
int n,m;
int u,v,k;

void fw(){
    
    for(int h=0; h<n; h++){
        for(int k=0; k<=h; k++){
            for(int j=0; j<n; j++){
                for(int i=0; i<n; i++){
                    dist[h][i][j] = min(dist[0][i][j], min(dist[h][i][j], dist[h][i][k] + dist[h][k][j]));
                }
            }
        }
    }
}

int main(){
    
    while(scanf("%d%d", &n, &m) != EOF){
    
        memset(dist, INF, sizeof(dist));
        
        while(m--){
            scanf("%d%d%d", &u, &v, &k);
            u--;v--;
            dist[0][u][v] = dist[0][v][u] = k;
            dist[0][u][u] = dist[0][v][v] = 0;
        }

        fw();

        int q;
        scanf("%d", &q);
        
        while(q--){
            
            scanf("%d%d%d", &u, &v, &k);
            
            u--; v--; k--;
            
            int res = dist[k][u][v];
            
            if(res == INF)
                printf("-1\n");
            else
                printf("%d\n", res);
        }
    
    }
    return 0;
}
