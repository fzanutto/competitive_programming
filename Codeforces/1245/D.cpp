#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define MAXN 2001
#define ii pair<int,int>
 
vector<pair<ll, ii>> edgeList;
 
int N,M;
 
ii coord[MAXN];
int costStation[MAXN];
int costRoad[MAXN];
vector<ii> arestas;
vector<int> station;

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
            
            if(edge.second.second == 0){
                station.push_back(edge.second.first);
                //cout << "planta: " << edge.second.first << endl;
            }else{
                arestas.push_back({edge.second.first, edge.second.second});
                //cout << "custo: " << edge.first << " conectando: " << edge.second.first << " - " << edge.second.second << endl;
            }
            
            
            UF.unionSet(edge.second.first, edge.second.second);
        }
    }
    
    return cost;
}
 
 
int main(){
    int n;
 
    cin >> n;
 
    N = n;
    
    for(int i=0; i<n;i++){
        int x,y;
        cin >> x >> y;
 
        coord[i+1] = {x,y};
    }
 
    for(int i=0; i<n;i++){
        int c;
        cin >> c;
        costStation[i+1] = c;
    }
 
    for(int i=0; i<n; i++){
        int c;
        cin >> c;
        costRoad[i+1] = c;
    }
 
    for(int i=1; i<=n; i++){
        edgeList.push_back(make_pair(costStation[i], make_pair(i,0)));
        M++;
        for(int j=i+1; j<=n; j++){
            
            ll custo = (ll)(abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second)) * (ll)(costRoad[i] + costRoad[j]);
                
            M++;      
            edgeList.push_back({custo, {i,j}});
        }
    }
 
    ll res = kruskal();
    
    cout << res << endl;
    cout << station.size() << endl;
    
    int i;
    if(station.size()){
        for(i=0; i<(int)station.size()-1; i++)
            cout << station[i] << " ";
        cout << station[i] << endl;
    }
    cout << arestas.size() << endl;
    for(auto a : arestas){
        cout << a.first << " " << a.second << endl;
    }
    
    
}
