#include <bits/stdc++.h>

using namespace std;


int custo[1005];
pair<int,int> c[1005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    
    int t,n,m;
    
    cin >> t;
    while(t--){
        
        cin >> n >> m;
        
        for(int i=0; i<n; i++){
            cin >> custo[i];
            c[i].first = custo[i];
            c[i].second = i;
        }
        /*
        for(int i=0; i<n; i++){
            cout << c[i].first << endl;
        }
        */
        sort(c, c+n);
        
        vector<pair<int,int>> ans;
        int soma = 0;
        
        
        if (m < n||n==2){
            cout << -1 << endl;
            continue;
        }
        
        else if(m == n){
            
            int i;
            for(i=1; i<n; i++){
                ans.push_back({i-1, i});
                soma += custo[i-1] + custo[i];
            }
            ans.push_back({0, i-1});
            soma += custo[0] + custo[i-1];
        }
        
        cout << soma << endl;
        for(auto a: ans)
            cout << a.first+1 << " " << a.second+1 << endl;
    
    }
    
    
    return 0;

}
