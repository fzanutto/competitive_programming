#include <bits/stdc++.h>
using namespace std;

int main(){

    int n,m,v;
    
    cin >> n >> m >> v;
    
    int max = n-1;
    
    for(int i=3; i<=n; i++)
        max += n-i;
    
    if(m > max || m < n-1){
        cout << -1 << endl;
        return 0;
    }
        
    int s = m;    
    for(int i=1; i<=n; i++){
        if(i == v)
            continue;
        cout << v << " " << i << endl;
        m--;
        if(!m)
            return 0;
    }
    

    int limite1 = n-1;
    
    for(int i=1; i < limite1; i++){
        if(i == v){
            limite1++;
            continue;
        }
        
        int limite2 = n-1;
        if(v < i+1) limite2++;    
        for(int j=i+1; j<limite2; j++){
            if(j == v){
                limite2++;
                continue;
            }
            cout << i << " " << j << endl;
            m--;
            if(!m) return 0;
        }
    
    }
}
