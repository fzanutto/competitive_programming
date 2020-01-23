#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

int n,c;

int valores[200001];
int memo[200001][2];

int calc(int i, int ativo){

    if(i == n){
        if(ativo) return -INF;
        return 0;
    }
    
    if(memo[i][ativo] != -1){
        return memo[i][ativo];
    }

    if(ativo){ //se pode vender
        return memo[i][ativo] = max(calc(i+1, 0) + valores[i], calc(i+1, 1));
    } else { //se pode comprar
        return memo[i][ativo] = max(calc(i+1, 1) - c - valores[i], calc(i+1, 0));
    }

}


int main(){
    cin >> n >> c;

    for(int i=0; i<n; i++){
        cin >> valores[i];
    }
    memset(memo, -1, sizeof memo);
    cout << calc(0,0) << endl;

}
