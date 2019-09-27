#include <bits/stdc++.h>


using namespace std;


#define MAX 100000


vector<vector<int>> arvore;

int profundidade[MAX];
int nxt[MAX];
int cortados[MAX];

priority_queue<pair<int,int>> pq;

int dfs(int i){
    
    int prof = 0;
    int temp = 0;
    
    for(int a : arvore[i]){
        temp = dfs(a);
        if (temp > prof){
            nxt[i] = a;
            prof = temp;
        }
    }
    prof++;
    
    pq.push({prof, i});
    //cout << "prof de ["<<i+1<<"]: " << prof << endl;
    
    return prof;

}


int main(){

    memset(nxt, -1, sizeof(nxt));    
    
    int n,k;
    
    cin >> n >> k;
    
    arvore.resize(n);
    
    int temp;
    
    for (int i=1; i<n;i++){
        cin >> temp;
        arvore[--temp].push_back(i);
    }
    
    
    dfs(0);
    
    int res = 0;
    while(!pq.empty() && k){

        int i = pq.top().second;
        int v = pq.top().first;
        pq.pop();
        //cout << "vendo nodo " << i+1 << endl;
        if(cortados[i]) continue;
        k--;
        res += v;
        //cout << "add " << v << " na res" << endl;
        while(i != -1){
            //cout << "cortando nodo " << i+1 << endl;
            cortados[i] = 1;
            i = nxt[i];

        }
        
        //cout << pq.size() << " " << k << endl;
    }
    
    cout << res << endl; 
    
    return 0;

}
