#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e6)
#define K 25 // 2^K needs to be greater than MAXN, 25 is nice if MAXN <= 1e7

int N;
int numbers[MAXN]; // used to build sparse table
int st[MAXN][K+1];

int LOG[MAXN+1]; //will store logs for use in RMQ

int RMQ(int L, int R){
    int j = LOG[R-L+1];
    int ans = max(st[L][j], st[R-(1<<j)+1][j]);
    return ans;
}

void build_st(){

    for(int i=0; i<N; i++){
        st[i][0] = numbers[i];
    }
 
    for(int j=1; j<= K; j++){
        for(int i=0; i+ (1<<j) <= N; i++){
            st[i][j] = max(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    LOG[1] = 0;
    for(int i=2; i <= MAXN; i++)
        LOG[i] = LOG[i/2] + 1;
}

int main(){
    int q;
    cin >> N >> q;
    for(int i=0; i<N;i++)
        cin >> numbers[i];
    
    build_st();
    
    int cont= 0;
    while(q--){
        int l,r;
        cin >> l >> r;
        l--; r--;
        int maior = RMQ(l,r-1);
        if (maior == numbers[l]){
            cont++;
        }
    }
    cout << cont << endl;
}
