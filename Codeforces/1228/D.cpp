#include <bits/stdc++.h>

#define MAX 100005

using namespace std;

int cor[MAX];
int n,m;
int visited[MAX];


void bfs(vector<vector<int>> grafo, int i){

    queue<int> fila;
    
    fila.push(i);
    
    visited[i] = 1;
    
    while(!fila.empty()){
    
        int u = fila.front();
        fila.pop();
        //cout << "cor de nodo " << u << ": " << cor[u] << endl;
        for (int v : grafo[u]){
            // se esta conectado, ver se tem cor diferente
            if(cor[u] == cor[v]){
                cor[v]++;
            }
            if(!visited[v]){
                fila.push(v);
                visited[v] = 1;    
            }
        }
    }
}


int main(){

    cin >> n >> m;
    memset(cor, 0, sizeof(cor));
    
    vector<vector<int>> grafo(n);

    for(int x=0; x<m; x++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }

    bfs(grafo, 0);
    int cores[3] = {};
    for(int i=0; i<n; i++){
        //cout << cor[i] << endl;
        if(cor[i] == 0)
            cores[0]++;
        else if(cor[i]==1)
            cores[1]++;
        else if (cor[i]==2)
            cores[2]++;
    }
    
    if(cores[0] == 0 || cores[1] == 0 || cores[2] == 0){
        cout << "-1" <<endl;
        return 0;
    }
    
    int soma = cores[0]*cores[1]+cores[0]*cores[2]+cores[1]*cores[2];
    if(soma != m){
        cout << "-1" << endl;
        return 0;
    }
    
    for(int i=0; i<n-1; i++){
        cout << cor[i]+1 << " ";
    }
    cout << cor[n-1]+1 << endl;
    
    return 0;
}
