#include <bits/stdc++.h>
using namespace std;


int main(){

    int t;
    cin >> t;
    
    int n,x,a,b;
    
    int dist;
    while(t--){
        cin >> n >> x >> a >> b;
        
        if (a>b)
            swap(a,b);
            
        dist = b-a;
        int novo = min(n-b, x);
        x -= novo;
        //cout << novo << endl;
        dist += novo;
        novo = min(a-1, x);
        //cout << novo << endl;
        dist += novo;
        
        cout << dist << endl;
    
    }
}
