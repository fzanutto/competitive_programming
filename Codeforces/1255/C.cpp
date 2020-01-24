#include <bits/stdc++.h>

using namespace std;

vector<int> v[100000];
int count[100005];
vector<int> v2[100005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n-2; j++){
            int temp;
            cin >> temp;
            v[i].push_back(temp);
            count[temp]++;
            v2[temp].push_back(i);
        }
    
    }
    int m = 0x3f3f3f3f;
    for(int i=0; i<n; i++)
        if(count[m] == 1)
            m = i;
    
    queue<int> q;
    q.push(m);
    
    vector<int> ans;
    while(!q.empty()){
        int cur = q.top();
        q.pop();
        ans.push_back(cur);
        
        
        for(auto a: v2[cur]){
            //vetores que cur aparece
            if()
            
        
        }
        auto vetor = v[cur];
        
        if(count[vetor])
        
        
        
    
    }
    
    
    return 0;

}
