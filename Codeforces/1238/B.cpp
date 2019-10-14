#include <bits/stdc++.h>

using namespace std;

set<int> monstros;
int r;

int check(int tot, int n){
    //cout << "N: " << n << endl;
    int cont = 0;    
    for(int a: monstros){
        //cout << "m: " << a << " " << r*n << endl;
        if (cont == tot-n) 
            return true;
        
        if (a-r*n > 0)
            return false;
        cont += 1;
    }
    
    return true;
}

int main(){

    int testes, n;
    
    cin >> testes;
    
    while(testes--){
 
        cin >> n >> r;
        monstros.clear();
        
        for(int i=0; i<n; i++){
            int temp;
            cin >> temp;
            monstros.insert(temp);
        }        
        
        int l = 0;
        int r = monstros.size()+1;
        int mid;
        int res = monstros.size();
        
        while(l < r){
            mid = (l+r+1) / 2;
            if(check(monstros.size(), mid)){
                res = mid;
                r = mid-1;
            } else
                l = mid;
        
        }
        cout << res << endl;
                   
    }
}
    
    
