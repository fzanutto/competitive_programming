#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a,b;
    
    cin >> a >> b;
    
    if(a.size() != b.size()){
        cout << "NO" << endl;
        return 0;
    }
    
    int cond1 = 0;
    int cond2 = 0;

    for(int i=0; i<a.size(); i++){
        if(a[i] == '1')
            cond1 = 1;
        if(b[i] == '1')
            cond2 = 1;
    }
    
    if(cond1 != cond2)
        cout << "NO" << endl;
    else cout << "YES" << endl;

}
