#include <bits/stdc++.h>
#define ii pair<int,int>
#define ll long long

using namespace std;


class UnionFind{

public:
    vector<int> parent, rank;
    
    UnionFind(int N){
        rank.assign(N+1, 0);
        parent.assign(N+1, 0);
        
        for(int i=0; i<=N; i++)
            parent[i] = i;
    }
    
    int find(int i){
        while(i != parent[i])
            i = parent[i];
        return i;
    }
    
    bool isSameSet(int i, int j){
        return find(i) == find(j);
    }
    
    void unionSet(int i, int j){
        if(isSameSet(i,j)) return;
        
        int x = find(i);
        int y = find(j);
        if(rank[x] > rank[y]) 
            parent[y] = x;
        else{
        
            parent[x] = y;
            if(rank[x] == rank[y]) rank[y]++;
        }
    
    }
};

int N, M;
vector<pair<ll,ii>> edgeList;

ll kruskal(int reverse){
    ll cost = 0;
    UnionFind UF(N);
    
    pair<int, ii> edge;
    if(!reverse)
        sort(edgeList.begin(), edgeList.begin()+M);
    else
        sort(edgeList.begin(), edgeList.begin()+M, greater<pair<int, ii>>());
        
        
    for(int i=0; i<M;i++){
        edge = edgeList[i];
        
        if(!UF.isSameSet(edge.second.first, edge.second.second)){
            cost += edge.first;
            UF.unionSet(edge.second.first, edge.second.second);
        }
    
    }
    return cost;
}



int main(){

    while(true){
        cin >> N >> M;
        edgeList.resize(M);
        if (N == 0) return 0;
        
        for(int i=0; i<M; i++){
            int x,y,c;
            cin >> x >> y >> c;
            
            edgeList[i] = {c, {x,y}};
        }
        
        
        cout << kruskal(1) - kruskal(0) << endl;
    }
}
