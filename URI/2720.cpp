#include <bits/stdc++.h>

using namespace std;

class comparator{

public:
    comparator(){}
    
    // se o comparador retorna true, ele nao muda de lugar
    bool operator() (const pair<int,int> l, const pair<int,int> r) const {
        if(l.first == r.first)
            // se ambos tem o mesmo peso, coloca o menor id na frente
            return l.second > r.second;
        return l.first < r.first;
    }
};


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t,n,k;
    cin >> t;
    
    while(t--){
        priority_queue<pair<int,int>, vector<pair<int,int>>, comparator > pq;
        set<int> ids;
        cin >> n >> k;
        while(n--){
            int i,h,w,l;
            
            cin >> i >> h >> w >> l;
            pq.push({h*w*l, i});
        }
        
        while(k--){
            ids.insert(pq.top().second);
            pq.pop();
        }
        
        auto inicio = ids.begin();
        auto fim = ids.end();
        --fim;
        for(; inicio!=fim; inicio++){
            cout << *inicio << " ";
        }
        
        cout << *inicio <<  endl;
    }
}
