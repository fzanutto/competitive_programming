#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5;

int tickets[MAX];
int a[2];
int b[2];
long long k;

int check(int n){
    //cout << "testando com " << n << endl;
    long long soma = 0;
    int p1=0,p2=0,p3=0;
    
    for(int i=1; i<=n; i++){
        if (i % a[1] == 0 && i%b[1] == 0)
            p1++;
            
        else if (i%a[1] == 0)
            p2++;
            
        else if (i%b[1] == 0)
            p3++;
    }
    
    int i = 0;
    
    while(p1--){
        soma += (long long)tickets[i]*a[0]/100 + (long long)tickets[i]*b[0]/100;
        //cout << "soma1: " << soma << endl;
        i++;
        if(i == n) return soma >= k;
    
    }
    
    while(p2--){
        soma += (long long)tickets[i]*a[0]/100;
        //cout << "soma2: " << soma << endl;
        i++;
        if(i == n) return soma >= k;
    
    }   
    
    while(p3--){
        soma += (long long)tickets[i]*b[0]/100;
        //cout << "soma3: " << soma << endl;
        i++;
        if(i == n) return soma >= k;
    
    }
    
    return soma >= k;
}

int main(){

    int testes, t;
    
    cin >> testes;
    
    while(testes--){
 
        cin >> t;
        
        for(int i=0; i<t; i++){
            cin >> tickets[i];
        }
        
        sort(tickets, tickets+t, greater<int>());
           
        cin >> a[0] >> a[1] >> b[0] >> b[1];
        
        cin >> k; 
        
        if(b[0] > a[0])
            swap(a,b);
        
        
        
        int l=0;
        int r = t;
        int res = -1;
        int mid;
        
        while(l < r){
            mid = (l+r+1) / 2;
            if(check(mid)){
                res = mid;
                r = mid-1;
            } else
                l = mid;
        
        }
        cout << res << endl;
                   
    }
}
    
    
