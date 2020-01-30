#include <bits/stdc++.h>

using namespace std;


int calc(int i, vector<int> &x){    
    vector<int> l,r;
    
    if(i == -1 || x.size() == 0) return 0;
    
    for(int j=0; j<x.size(); j++){
        if((x[j] & (1<<i)) > 0){
            l.push_back(x[j]);
        } else{
            r.push_back(x[j]);
        }
    }

    if(l.size() == 0) return calc(i-1, r);
    if(r.size() == 0) return calc(i-1, l);

    return min(calc(i-1, l), calc(i-1, r)) + (1<<i);
}


int main(){

    int n;
    cin >> n;
    
    vector<int> lista(n);
    
    for(int i=0; i<n; i++){
        cin >> lista[i];
    }
    
    cout << calc(30, lista) << endl;

}
