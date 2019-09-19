#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef struct m matriz;

struct m {

    long long *valores[4];
    int r; //rows
    int c; //columns

    void start_matriz(int rows, int columns){
        r=rows;
        c=columns;

        for(int i=0; i<r; i++){
            valores[i] = (long long*) malloc(sizeof(long long) * c);
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
                    mul.valores[i][k] = (mul.valores[i][k] + a.valores[i][j] * b.valores[j][k]) % MOD;
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

    matriz a, b;
    a.start_matriz(3,3);
    b.start_matriz(3,1);

    a.valores[0][0] = 1;
    a.valores[0][1] = 4;
    a.valores[0][2] = 2;
    a.valores[1][0] = 1;
    a.valores[1][1] = 0;
    a.valores[1][2] = 0;
    a.valores[2][0] = 0;
    a.valores[2][1] = 1;
    a.valores[2][2] = 0;

    b.valores[0][0] = 5;
    b.valores[1][0] = 1;
    b.valores[2][0] = 1;

    long long n;
    cin >> n;


    if(n < 3){
        cout << b.valores[2-n][0] << endl;
    } else {
        a = a.exponenciacao(n-2);
        b = b.multiply(a, b);

        cout << b.valores[0][0] << endl;;
    }
}
