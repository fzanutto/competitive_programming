#include <bits/stdc++.h>
using namespace std;

vector<int> pre,mid,suf;

int LongestIncreasingSubsequenceLength(std::vector<int>& v) {

    if (v.size() == 0) 
        return 0; 
  
    std::vector<int> tail(v.size(), 0); 
    int length = 1;
  
    tail[0] = v[0]; 
    for (size_t i = 1; i < v.size(); i++) { 
  
        if (v[i] < tail[0]) 
            tail[0] = v[i]; 

        else if (v[i] > tail[length - 1]) 
            tail[length++] = v[i]; 
        else {
            auto a = std::lower_bound(tail.begin(), tail.begin()+length, v[i]);
            *a = v[i];
        }
    }
     
    return length; 
} 


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k1,k2,k3;
    
    cin >> k1 >> k2 >> k3;
    
    int temp;
    for(int i=0; i<k1; i++){
        cin >> temp;
        pre.push_back(temp);
    }
    for(int i=0; i<k2; i++){
        cin >> temp;
        mid.push_back(temp);
    }
    for(int i=0; i<k3; i++){
        cin >> temp;
        suf.push_back(temp);
    }
        
    sort(pre.begin(), pre.end());
    sort(mid.begin(), mid.end());
    sort(suf.begin(), suf.end());

    vector<int> fim(k1+k2+k3);
    
    for(int i=0; i<k1; i++)
        fim[i] = pre[i];
    for(int i=0; i<k2; i++)
        fim[k1+i] = mid[i];
    for(int i=0; i<k3; i++)
        fim[k1+k2+i] = suf[i];
        
        
    cout << k1+k2+k3 - LongestIncreasingSubsequenceLength(fim) << endl;
        
}
