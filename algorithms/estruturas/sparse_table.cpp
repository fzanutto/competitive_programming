#include <bits/stdc++.h>

using namespace std;

#define MAXN int(1e6)
#define K 25 // 2^K needs to be greater than MAXN, 25 is nice if MAXN <= 1e7

int N;

int st[MAXN][K+1];

int LOG[MAXN+1]; //will store logs for use in RMQ

long long RSQ(int L, int R){
    long long sum = 0;
    
    for(int j=K; j>= 0; j--){
        if((1<<j) <= R-L + 1){
            sum += st[L][R];
            L += 1 << j;
        }
    }
    
    return sum;
}

long long RMQ(int L, int R){

    int j = LOG[R-L+1];
    int minimum = min(st[L][j], st[R-(1<<j)+1][j]);

}

void build_st(int array[]){

    for(int i=0; i<N; i++){
        st[i][0] = array[i];
    }
    /*
    // for RSQ
    for(int j=1; j<=K; j++){
        for(int i=0; i + (1<<j) <= N; i++){
            st[i][j] = st[i][j-1] + st[i + (1<<j-1)][j-1];
        }
    }
    ///////////////////////
    */
    // for RMQ
    for(int j=1; j<= K; j++){
        for(int i=0; i+ (1<<j) <= N; i++){
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }
    LOG[1] = 0;
    for(int i=2; i <= MAXN; i++)
        LOG[i] = LOG[i/2] + 1;
    /////////////////////////

}

int main(){

    N = 20;
    
    
    int a[] = {12,46,78,5,7,5,5,5,2,8,25,5,5,23,2,8,2,5,14,87,96};
    
    build_st(a);
    
    cout << RMQ(0,3) << endl;
    
    

}
