/*
Just need to discover the number of connected components using only the 0-weighted vertices. 
If we have k connected components, then we need k-1 1-weight to make the MST
*/

#include <bits/stdc++.h>
 
using namespace std;
 
set<pair<int,int>> edges;
set<int> vertices;

void dfs(int v){

    vector<int> a;
    vertices.erase(v);
    
    for(int u: vertices){
            
        if(edges.count({v,u}) == 0){
            a.push_back(u);
        }
    }
    
    for(int u: a)
        vertices.erase(u);
    
    for(int u: a)
        dfs(u);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int x,y;
        
        cin >> x >> y;
        
        edges.insert({x,y});
        edges.insert({y,x});
    }
    
    for(int i=1; i<=n; i++)
        vertices.insert(i);

    int ans = 0;
    
    for(int i=1; i<=n; i++){
        if(vertices.count(i))
            ans++, dfs(i);   
    }
    
    cout << ans-1 << endl;
    
    return 0;
    
}

