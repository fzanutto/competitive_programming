#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define MAXN 2001
#define ii pair<int,int>
 
vector<pair<ll, ii>> edgeList;
 
int N,M;

int aero;

class UnionFind {
 
public:
    vector<int> parent, rank;
    
    UnionFind(int N){}
    
    void init(int N){
        rank.assign(N+1, 0);
        parent.assign(N+1, 0);
        for(int i=0; i<= N; i++) parent[i] = i;
    }
    
    int find(int i){
        while(i != parent[i]){
            i = parent[i];
        }
        return i;
    }
    
    bool isSameSet(int i, int j){
        return find(i) == find(j);
    }
    
    void unionSet(int i, int j){
        if(isSameSet(i,j)) return;
        
        int x = find(i), y = find(j);
        
        if(rank[x] > rank[y]) parent[y] = x;
        else {
            parent[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    }
};
 
 
UnionFind UF(0);
 
ll kruskal(){
 
    ll cost = 0;
    UF.init(N);
    pair<ll, ii> edge;
    sort(edgeList.begin(), edgeList.end());
    
    for(int i=0; i < M; i++){
        edge = edgeList[i];
        //cout << "testando aresta " << edge.second.first << endl;
        int x = UF.find(edge.second.first), y = UF.find(edge.second.second);
        
        if(x != y){
    
            cost += edge.first;
            //cout << "custo: " << edge.first << " conectando: " << edge.second.first << " - " << edge.second.second << endl;
            
            if(edge.second.first == 0){
                aero++;
                //cout << "aero: " << edge.second.first << endl;
            }
            
            UF.unionSet(edge.second.first, edge.second.second);
        }
    }
    
    return cost;
}
 
 
int main(){

    int T, a;
    
    cin >> T;
    
    for(int t=1; t<=T; t++){
        edgeList.clear();
        aero = 0;
        cin >> N >> M >> a;
        
        for(int i=1; i<N+1; i++){
            edgeList.push_back({a, {0,i}});
        }
        
        for(int i=0; i<M; i++){
            int x,y,c;
            cin >> x >> y >> c;
            edgeList.push_back({c, {x,y}});
        }
        M+=N;
        ll res = kruskal();
        
        cout << "Case #" << t << ": " << res << " " << aero << endl;
        
    }
}
