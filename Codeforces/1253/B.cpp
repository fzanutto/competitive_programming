#include <bits/stdc++.h>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int events = 0;
    int cur = 0;
    
    vector<int> ans;
    map<int, int> a;
    bitset<1000001> entrou, saiu;
    int temp;
    
    if(n%2==1){
        cout << -1 << endl;
        return 0;    
    }
    
    for(int i=0; i<n; i++){
        cin >> temp;
        
        if (temp > 0){
            if(entrou[temp]){
                cout << -1 << endl;
                return 0;
            }
            cur++;
            entrou[temp] = 1;
            
        } else {
            if(saiu[-temp] == 1 || entrou[-temp] == 0){
                cout << -1 << endl;
                return 0;
            }
            cur--;
            saiu[-temp] = 1;
        }
        
        events++;
        if(cur == 0){
            ans.push_back(events);
            events = 0;
            
            entrou.reset();
            saiu.reset();
        }
    }
    
    if(cur != 0){
        cout << -1 << endl;
        return 0;
    }

    cout << ans.size() << endl;
    
    for(auto x: ans)
        cout << x << " ";
    cout << endl;
    
    return 0;

}
