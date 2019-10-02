#include <bits/stdc++.h>


using namespace std;


int main(){

    int a,n;
    
    cin >> a >> n;
    
    while(n <= 0){
        cin >> n;
    }
    
    int res=0;
    for(int i=0; i < n; i++){
        res += a+i;
    }
    cout << res << endl;


}
