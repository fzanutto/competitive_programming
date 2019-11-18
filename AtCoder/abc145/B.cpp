#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    string s;
    
    cin >> n >> s;
    if(n%2 == 1){
        cout << "No" << endl;
        return 0;
    }
    
    string a = s.substr(0, n/2);
    string b = s.substr(n/2, n/2);
    
    //cout << a << " - " << b << endl;
    
    if(a == b)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
