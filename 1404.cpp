#include <bits/stdc++.h>

using namespace std;

int movi[4] = {2,2,-2,-2};
int movj[4] = {2,-2,2,-2};

int tabuleiro[21][21];
int n;
int m;

int busca(int i, int j){
    int res = 0;
    for(int k=0; k<4; k++){

        int ii = i + movi[k];
        int jj = j + movj[k];
        int iii = i + movi[k]/2;
        int jjj = j + movj[k]/2;

        if (ii<0 || ii>=n || jj<0 || jj>=m || iii<0 || iii>=n || jjj<0 || jjj>=m){
            continue;
        }

        if(tabuleiro[ii][jj] == 0 && tabuleiro[iii][jjj] == 2){
            tabuleiro[iii][jjj] = 0;
            res = max(res, 1+busca(ii, jj));
            tabuleiro[iii][jjj] = 2;
        }
    }
    return res;
}



int main(){

    while(1){

        cin >> n >> m;
        if (n == 0 && m == 0) break;

        for(int i =0; i<n; i++){
            for(int j=0;j<m;j++){
                tabuleiro[i][j] = 0;
            }
        }
        int a;
        for(int i = 0; i < n; i++){
            int j = i%2==0 ? 0 : 1;
            for(; j<m; j+=2){
                cin >> a;
                tabuleiro[i][j] = a;
            }
        }

        int res = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if (tabuleiro[i][j] == 1){
                    tabuleiro[i][j] = 0;
                    res = max(res, busca(i,j));
                    tabuleiro[i][j] = 1;
                }
            }
        }
        cout << res << endl;
    }
}
