#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int n,c,t;
int pipocas[MAX];

bool check(long long seg){

    long long por_pessoa = seg * t;
    long long temp = 0;
    int i = 0;
    
    for(int x=0; x <c; x++){
    
        temp = 0;
        
        while(i < n){
            if(temp + pipocas[i] > por_pessoa) break;
            
            temp += pipocas[i];
            i++;
        }
    }
    
    return i == n;
}


int main(){


    cin >> n >> c >> t;
    for(int i=0; i<n; i++)
        cin >> pipocas[i];

    long long l=1LL;
    long long r = 10000000001;
    long long mid;
    
    while(l<r){
    
        mid = (l+r) / 2;
        
        if(check(mid))
            r = mid;
        else
            l = mid + 1;
    
    }


    cout << l << endl;

}
