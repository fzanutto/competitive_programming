#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int a,b,t;
    cin >> t;
    while(t--){
        cin >> a >> b;
        
        int res = 0;
        int v[] = {5,2,1};
        int dif = abs(b-a);
    
        if (dif >= 5)
            res += dif / 5;
        dif %= 5;
        if (dif >= 2)
            res += dif/2;
        dif %= 2;
        if(dif >= 1)
            res += dif/1;
        
        cout << res << endl;
        
        
        
    }
    return 0;

}
