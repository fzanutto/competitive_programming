#include <bits/stdc++.h>

using namespace std;

class FenwickTree {
public:
    vector <int> ft;
    
    FenwickTree(int n) { ft.assign(n+1, 0); }
    
    int rsq (int i) {
        int sum = 0;
        for(; i; i -= (i & -i))
            sum += ft[i];
        
        return sum;
    }
    
    int rsq(int i, int j){
        return rsq(j) - rsq(i-1);
    }
    
    void update(int i, int v){
        for(; i < ft.size(); i += (i & -i))
            ft[i] = v + ft[i];
    }
};


long long getInvCount(vector<pair<int,int>> &vetor){

    long long ans = 0;
    
    FenwickTree FT(vetor.size());

    for(int i=vetor.size() - 1; i>=0; i--){
        
        ans += FT.rsq(vetor[i].second - 1);
        
        FT.update(vetor[i].second, 1);
    }
    //cout << "inv: " << ans << endl;
    return ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int x,y;
    long long h,v;
    cin >> x >> y;
    cin >> h >> v;
    
    vector<pair<int,int>> horizontal(h), vertical(v);
    vector<int> h2(h),v2(v);
    
    map<int,int> hor, vert;
    int temp;
    
    for(int i=0; i<h; i++){
        cin >> horizontal[i].first >> horizontal[i].second;
        h2[i] = horizontal[i].second;
    }

    sort(horizontal.begin(), horizontal.end());
    sort(h2.begin(), h2.end());
    
    for(int i=0; i<h; i++){
        horizontal[i].second = lower_bound(h2.begin(), h2.end(), horizontal[i].second) - h2.begin() + 1;
    }
    
    /////////////////////////////////////////////////////
    for(int i=0; i < v; i++){
        cin >> vertical[i].first >> vertical[i].second;
        v2[i] = vertical[i].second;
    }

    sort(vertical.begin(), vertical.end());
    sort(v2.begin(), v2.end());
    
    for(int i=0; i<v; i++){
        vertical[i].second = lower_bound(v2.begin(), v2.end(), vertical[i].second) - v2.begin() + 1;
    }
    
    long long ans = (h+1) * (v+1);
    //cout << ans << endl;
    ans += getInvCount(horizontal) + getInvCount(vertical);
    
    cout << ans << endl;

}
