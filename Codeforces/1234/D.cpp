#include  <bits/stdc++.h>
 
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
        
    vector<set<int>> conj(26);    
    
    int q,t;
    string a;
    cin >> a;
    
    for(int i=0; i<a.size(); i++)
        conj[a[i] - 'a'].insert(i+1);
        
    cin >> q;
    while(q--){

        cin >> t;
        
        if (t == 1){
            int pos;
            char c;
            
            cin >> pos >> c;
            conj[a[pos-1] - 'a'].erase(pos);
            a[pos-1] = c;
            conj[a[pos-1] - 'a'].insert(pos);

        } else {
            int l,r;
            cin >> l >> r;
            int res = 0;
            for(int i=0; i<26; i++){
            
                auto it = conj[i].lower_bound(l);
                
                if(it != conj[i].end() && *it <= r) res++; 
            }
            
            cout << res << endl;

        }
    }
    
}
