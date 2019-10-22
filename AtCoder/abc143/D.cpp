#include <bits/stdc++.h>

using namespace std;

vector<int> s;

int main(){
    
    int n;
    cin >> n;
    
    for(int i=0; i< n; i++){
        int temp;
        cin >> temp;
        s.push_back(temp);
    }
    
    sort(s.begin(), s.end());
    
    long long res = ((long long) n)*(n-1)*(n-2)/6;
    
    for(int i=0; i<n; i++){
        
        for(int j=i+1; j<n; j++){
            int a = s[i];
            int b = s[j];
            
            int l = j;
            int r = n;
            while(l < r){
                int mid = (l+r+1)/2;
                //cout << mid << endl;
                if(s[mid] < a+b){
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if(l < n && s[l] < a+b)
                l++;
                
            res -= n-l;
        }
    }
    
    cout << res << endl;

}
