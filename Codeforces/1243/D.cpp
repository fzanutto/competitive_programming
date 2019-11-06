#include <bits/stdc++.h>
 
using namespace std;
 
#define ll long long
#define MAXN 100002
#define ii pair<int,int>
 
vector<pair<int, ii>> edgeList;
int N,M;
map<int, map<int,int>> teste;
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
 
    int cost = 0;
    UF.init(N);
    
    for(int i=1; i<=N; i++)
        for(int j=i+1; j<=N; j++)
            if(teste[i][j] != 1){
                int x = UF.find(i), y = UF.find(j);
                if(x != y){
                    UF.unionSet(i, j);
                }
            }
    

    for(auto a: teste){
        for(auto edge: a.second){
            int p = a.first;
            int s = edge.first;
            //cout << "testando aresta " << edge.second.first << endl;
            int x = UF.find(p), y = UF.find(s);
            
            if(x != y){
                cost += 1;
                UF.unionSet(p, s);
            }
        }
    }
    return cost;
}
 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n, m;
 
    cin >> n >> m;
 
    N = n;
    M = m;
    
    for(int i=0; i<m;i++){
        int x,y;
        cin >> x >> y;
        
        if(x > y)
            swap(x,y);
            
        teste[x][y] = 1;
    }
 
    int res = kruskal();
    
    cout << res << endl;
    
}
