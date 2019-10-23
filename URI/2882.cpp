#include <bits/stdc++.h>

using namespace std;

#define MAXN 103000
#define MAXM 900000
#define INF 0x3f3f3f3f

int ned, first[MAXN], work[MAXN];
int cap[MAXM], to[MAXM], nxt[MAXM], dist[MAXN];
int cap2[MAXM];
int tempo[MAXN];
int TEMPOM = 0;

void init(){
    memset(first, -1, sizeof(first));
    ned = 0;
}

void add(int u, int v, int f, int t){
    to[ned] = v;
    cap[ned] = f;
    tempo[ned] = t;
    
    nxt[ned] = first[u];
    first[u] = ned++;
    
    to[ned] = u;
    cap[ned] = 0;
    tempo[ned] = 0;
    
    nxt[ned] = first[v];
    first[v] = ned++;
}

int dfs(int u, int f, int s, int t){
    if(u == t) return f;
    int v, df;
    
    for(int &e = work[u]; e!=-1; e = nxt[e]){
        v = to[e];
        //cout << "tempo: " << tempo[e] << " " << (int)(tempo[e] <= TEMPOM) << endl;
        if(tempo[e] <= TEMPOM && dist[v] == dist[u] + 1 && cap[e] > 0){
            df = dfs(v, min(f, cap[e]), s, t);
            if(df > 0){
                cap[e] -= df;
                cap[e^1] += df;
                return df;
            }
        }
    }

    return 0;
}

bool bfs(int s, int t){

    int u, v;
    memset(&dist, -1, sizeof(dist));
    
    dist[s] = 0;
    
    queue<int> q;
    q.push(s);
    
    while(!q.empty()){
        u = q.front();
        q.pop();
        
        for(int e = first[u]; e != -1; e=nxt[e]){
            v = to[e];
            
            if(tempo[e] <= TEMPOM && dist[v] < 0 && cap[e] > 0){
            
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    
    return dist[t] >= 0;
}

int dinic(int s, int t){

    int result = 0;
    int f;
    while( bfs(s,t) ){
        memcpy(work, first, sizeof(work));
        
        while(f = dfs(s, INF, s, t)) 
            result += f;
    
    }
    //cout << result << endl;
    return result;
}


int main(){
    init();
    
    int p,r,c;
    cin >> p >> r >> c;
    
    int S = p+r;
    int T = p+r+1;
    
    // postos começam indexados em 0
    int total = 0;
    for(int i=0; i<p; i++){
        int necessidade;
        cin >> necessidade;
        total += necessidade;
        
        add(i, T, necessidade, 0);
        //add(T, i, necessidade, 0);
    }
    
    // refinarias começam indexadas em p
    for(int i=p; i<r+p; i++){
        int capacidade;
        cin >> capacidade;
        //add(i, S, capacidade, 0);
        add(S, i, capacidade, 0);
        
    }
    
    while(c--){
        int i,j,t;
        cin >> i >> j >> t;
        
        add(j+p-1, i-1, INF, t);
        //add(i-1, j+p-1, INF, t);
        
    }
    memcpy(cap2, cap, sizeof(cap2));
    
    int l=0;
    r=1000010;
    int res = -1;
    while(l < r){
        //cout << "l: " << l << " r: " << r << endl;
        memcpy(cap, cap2, sizeof(cap2));
        TEMPOM = (l+r+1)/2;
        //cout << "testando com " << TEMPOM << endl;
        if(dinic(S,T) == total){
            res = TEMPOM;
            r = TEMPOM - 1;        
        } else {
            l = TEMPOM;
        }
    
    }
    
    cout << res << endl;

    return 0;

}

