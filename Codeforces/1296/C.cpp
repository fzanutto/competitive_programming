#include <bits/stdc++.h>


using namespace std;

void solve(){
    
    int n;
    cin >> n;
    
    map<pair<int,int>, int> coord;
    
    set<pair<int, pair<int,int>>> ans;
    
    //cout << "------------------- " << n <<  endl;
    char dir;
    
    pair<int,int> cur = {0,0};

    for(int i=1; i<=n; i++){
    
        coord[cur] = i;
    
        cin >> dir;
        
        if(dir == 'U'){
            cur.second++;
        
        } else if(dir == 'D'){
            cur.second--;
        } else if(dir == 'L'){
            cur.first -= 1;
        } else if(dir == 'R'){
            cur.first += 1;
        }
        
        //cout << cur.first << " - " << cur.second << " " << i << endl;
        
        if(coord.find(cur) != coord.end()){
            ans.insert({i-coord[cur], {coord[cur], i}});
            //cout << "add:" << coord[cur] << " " << i << endl;
        }
    }

    if(ans.size() == 0){
        cout << -1 << endl;
    } else {
        cout << ans.begin()->second.first << " " << ans.begin()->second.second << endl;
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    
    cin >> t;
    
    while(t--){
        solve();
    
    }

}
