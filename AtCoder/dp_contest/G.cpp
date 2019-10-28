#include <bits/stdc++.h>

#define MAX 100005
#define NINF INT_MIN
using namespace std;

bitset<MAX> inicios, visitado;

map<int, int> grafo[MAX];
stack<int> pilha;
int dist[MAX];

void toposort(int nodo){
    visitado[nodo] = 1;
    
    for(auto u: grafo[nodo]){
        if (visitado[u.first] == 0)
            toposort(u.first);
    
    }
    
    pilha.push(nodo);
}


int longestPath(int n){

    for(int v=1; v<=n; v++){
        if(visitado[v] == 0)
            toposort(v);
            
        if(inicios[v] == 1)
            dist[v] = 0;
    }
    
    while(!pilha.empty()){
        int u = pilha.top();
        pilha.pop();
        
        for(auto v: grafo[u]){
            dist[v.first] = max(dist[u] + grafo[u][v.first], dist[v.first]);
            
        }
    }
    
    int m = 0;
    for(int a: dist){
        m = max(m, a);
    }
    return m;
}


int main(){
    
    int n,m;
    
    inicios.set();
    visitado.reset();
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
        dist[i] = NINF;
    
    for (int i=0; i<m; i++){
        int a,b;
        cin >> a >> b;
        grafo[a][b] = 1;
        inicios[b] = 0;
    }
    
    cout << longestPath(n) << endl;

}
