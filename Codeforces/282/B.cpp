#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(false);
    cout.tie(false);

    int n;
    cin >> n;
    
    int sa=0,sg=0;
    string ans = "";
    
    while(n--){
        
        int a,g;
        cin >> a >> g;
        
        if(abs(sa+a - sg) < abs(sa-(sg+g))){
            sa += a;
            ans += "A";
        
        } else {
            sg += g;
            ans += "G";
        }
    }

    if(abs(sa-sg) <= 500){
        cout << ans;
    
    } else cout << -1;
    
    cout << endl;
}
