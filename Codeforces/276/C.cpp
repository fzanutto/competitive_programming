#include <bits/stdc++.h>

using namespace std;


const int N = 2000005;

int t[4*N];

void update(int i, int l, int r, int ql, int qr, int x){

    if(ql <= l && r <= qr){
        t[i] += x;
        return;
    
    }
    
    if(qr <l || r < ql) return;
    
    int m = (l+r)/2;
    update(2*i, l, m, ql, qr, x);
    update(2*i+1, m+1, r, ql, qr, x);
}

int query(int i, int l, int r, int p){

    if (l==r) return t[i];
    int m = (l+r)/2;
    if (p<=m) return t[i] + query(2*i, l, m, p);
    else return t[i] + query(2*i+1, m+1, r, p);
}



int main(){

    int n,q;
    cin >> n >> q;
    
    vector<int> v,a;
    
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    
    sort(v.begin(), v.end());
    
    for(int i=0; i<q; i++){
        int l,r;
        cin >> l >> r;
        
        update(1, 1, n, l, r, 1);
    
    }
    
    for(int i=0; i<n; i++){
        a.push_back(query(1,1,n,i+1));
    }
    
    sort(a.begin(), a.end());
    
    long long ans = 0;
    
    for(int i=0; i<n; i++){
        ans += (long long)v[i] * a[i];
    }
    
    cout << ans << endl;
}
