#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef struct m matriz;

struct m {

    int *valores[4];
    int r; //rows
    int c; //columns

    void start_matriz(int rows, int columns){
        r=rows;
        c=columns;

        for(int i=0; i<r; i++){
            valores[i] = (int*) malloc(sizeof(int) * c);
            for(int j=0; j<c; j++){
                valores[i][j] = 0;
            }
        }
    }

    matriz identity(int tamanho){
        matriz result;
        result.r = r;
        result.c = r;
        for(int i=0; i<tamanho; i++){
            result.valores[i][i] = 1;
        }

        return result;
    };

    matriz multiply(matriz a, matriz b){
        matriz mul;
        mul.start_matriz(a.r, b.c);

        for(int i=0; i<a.r; i++){
            for(int j=0; j<b.r; j++){
                for(int k=0; k < b.c; k++){
                    mul.valores[i][k] = ((long long)mul.valores[i][k] + a.valores[i][j] * (long long)b.valores[j][k]) % MOD;
                }
            }
        }
        return mul;

    }

    matriz exponenciacao(int n){
        if(n == 0){
            return identity(r);
        }
        if(n == 1){
            return *this;
        }

        matriz result = exponenciacao(n >> 1);
        result = multiply(result, result);
        if(n & 1){
            result = multiply(result, *this);
        }
        return result;
    };

    void print(){
        for(int i=0; i<r; i++){
            for(int j=0; j<c; j++){
                cout << valores[i][j] << " ";
            }
            cout << endl;
        }
    }


};

int main(){

    matriz a;
    a.start_matriz(4,4);

    a.valores[0][0] = 0;
    a.valores[0][1] = 1;
    a.valores[0][2] = 1;
    a.valores[0][3] = 1;
    a.valores[1][0] = 1;
    a.valores[1][1] = 0;
    a.valores[1][2] = 1;
    a.valores[1][3] = 1;
    a.valores[2][0] = 1;
    a.valores[2][1] = 1;
    a.valores[2][2] = 0;
    a.valores[2][3] = 1;
    a.valores[3][0] = 1;
    a.valores[3][1] = 1;
    a.valores[3][2] = 1;
    a.valores[3][3] = 0;

    int n;
    cin >> n;
    a = a.exponenciacao(n);
    cout << a.valores[3][3] << endl;;


}
