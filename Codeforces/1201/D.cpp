#include <bits/stdc++.h>

using namespace std;

int main(){
/*
n,m,k,q = [int(i) for i in input().split()]

#matriz = [['']*m for _ in range(n)]

treasure = []

for _ in range(k):
    treasure.append([int(i) for i in input().split()])
    
treasure.sort()

safe = [int(i) for i in input().split()]

print(treasure)
*/

    int n,m,k,q;
    cin >> n >> m >> k >> q;
    
    set<pair<int,int>> treasure;
    
    for (int i=0; i<k; i++){
        pair<int,int> t;
        cin >> t.first >> t.second;
        treasure.insert(t);
    }
    
    set<int> safe;
    
    for(int i=0; i<q; i++){
        int temp;
        cin >> temp;
        safe.insert(temp);
    }
    
    int res = 0;
    pair<int,int> atual = {0,1};
    int i = 0;
    while(atual.first != n-1){
        atual.first++;
        p = treasure[i];
        while(atual.first == p.first){
            
            res += p.second - atual.second;
            
            auto n = safe.lower_bound(atual.second);
            auto m = safe.lower_bound(atual.second);
            
            p = treasure[i+1];
            
            if( abs(p.second - *n) < abs(p.second - m) )
            atual.second = min(*n,*m);
            
        }
    
    }
    
    
    
    
    
}
