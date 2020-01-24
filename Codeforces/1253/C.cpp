#include <bits/stdc++.h>

using namespace std;
long long ans[200005];
int a[200005];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,m;
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    sort(a, a+n);
    long long sum = 0;


    // if we have to eat n <= m candies, we eat all of them on 1st day
    // if we eat more than m candies, then the most expensive ones are eaten on this day
    // and the rest must be eaten a day after they were eaten before
    // so the answer for the current step is 
    // the sum of all candies until now + the cost of candies from step k-m
    for(int i=0; i<n; i++){
        sum += a[i];
        
        ans[i] = sum;
        
        if(i >= m){
            ans[i] += ans[i-m];
        }
        
        cout << ans[i] << ((i==n-1) ? "\n" : " ");
    }

    
    return 0;

}
