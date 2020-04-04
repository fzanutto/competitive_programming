#include <bits/stdc++.h>

using namespace std;

int main(){
    
    
    int t;
    cin >> t;
    
    for(int casos=1; casos<=t; casos++){
        
        
        int n;
        cin >> n;
        
        vector<pair<int,int>> inicio(n), fim(n);
        vector<char> done(n, '*');
        
        
        for(int i=0; i<n; i++){
            cin >> inicio[i].first >> fim[i].first;
            inicio[i].second = fim[i].second = i;
        }
        
        sort(inicio.begin(), inicio.end());
        
        int tempoC = 0, tempoJ = 0;
        
        for(int i=0; i<n; i++){
            if(tempoC <= inicio[i].first){
                tempoC = fim[inicio[i].second].first;
                done[inicio[i].second] = 'C';
                
            } else if (tempoJ <= inicio[i].first){
                tempoJ = fim[inicio[i].second].first;
                done[inicio[i].second] = 'J';
            }
        
        }
        
        string ans;
        for(int i=0; i<n; i++){
            if(done[i] == '*'){
                ans = "IMPOSSIBLE";
                break;
            } else {
                ans += done[i];
            }
        
        }
        
        
        cout << "Case #" << casos << ": "  << ans << endl;
    }
}
