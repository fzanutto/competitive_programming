#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int dist2[401][401][401];
int dist[401][401][401];

int n,m;
int u,v,k;
int temperaturas[401];

void fw(int cont){
    
    for(int h=1; h<=cont; h++){ // passando pelos h mais frios
        for(int k=0; k<n; k++){
            //cout << "nodo: " << k << endl;
            //cout << temperaturas[k];
            if(temperaturas[k] == h){ // se o planeta intermediario estiver entre os h mais frios
                //cout << "  passou para h = " << h << endl;
                for(int j=0; j<n; j++){
                    for(int i=0; i<n; i++){
                        int a = min(dist[h][i][k], dist[h-1][i][k]);
                        int b = min(dist[h][k][j], dist[h-1][k][j]);
                        int temp = min(dist[h-1][i][j], a+b);
                        int temp2 = min(dist[h][i][j], dist[h][i][k] + dist[h][j][k]);
                        
                        dist[h][i][j] = min(temp, temp2); 
                    }
                }
            }
        }
    }
}

void fw2(int cont){
   
    for(int h=1; h<=cont; h++){ //passando pelos h mais quentes
        for(int k=0; k<n; k++){
            //cout << "nodo: " << k << "   temp: " << cont+1-temperaturas[k] << endl;
            if(cont + 1 - temperaturas[k] == h){
                //cout << "  passou para h = " << h << endl;
                for(int j=0; j<n; j++){
                    for(int i=0; i<n; i++){
                    
                        int a = min(dist2[h][i][k], dist2[h-1][i][k]);
                        int b = min(dist2[h][k][j], dist2[h-1][k][j]);
                        int temp = min(dist2[h-1][i][j], a+b);
                        int temp2 = min(dist2[h][i][j], dist2[h][i][k] + dist2[h][j][k]);
                        
                        dist2[h][i][j] = min(temp, temp2);
                    }
                }
            }
        }
    }
}


int main(){
    
    scanf("%d%d", &n, &m);
    
    memset(dist2, INF, sizeof(dist2));    
    memset(dist, INF, sizeof(dist));

    vector<pair<int,int>> v_temp(n);
    
    int t;
    for(int i=0; i<n;i++){
        scanf("%d", &t);
        v_temp[i] = {t, i};
    }
    sort(v_temp.begin(), v_temp.end());
    
    int temp = v_temp[0].first;
    int cont = 1;
    
    for(int i=0; i<n; i++){
        if(v_temp[i].first != temp){
            cont++;
            temp = v_temp[i].first;
        }
        
        temperaturas[v_temp[i].second] = cont;
    }
    /*
    for(int i =0; i<n; i++)
        cout << temperaturas[i] << " - ";
        
    cout << endl;
    */
    while(m--){
        scanf("%d%d%d", &u, &v, &k);
        u--;v--;
        
        dist[0][u][v] = dist[0][v][u] = dist2[0][u][v] = dist2[0][v][u] = k;
    }
    
    fw(cont);
    fw2(cont);
    
    int q;
    scanf("%d", &q);
    
    while(q--){
        
        scanf("%d %d %d %d", &u, &v, &k, &t);
        k = min(k, cont);
        
        u--; v--;
        int res;
        
        if(t == 0)
            res = dist[k][u][v];
        else
            res = dist2[k][u][v];
       
        if (res == INF)
            printf("-1\n");
        else
            printf("%d\n", res);
    }

    return 0;
}
