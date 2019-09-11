#include <bits/stdc++.h>

#define MOD 1000000007

using namespace std;
typedef struct m matriz;

struct m {

    long long *valores[2];
    int r; //rows
    int c; //columns

    void start_matriz(int rows, int columns){
        r=rows;
        c=columns;

        for(int i=0; i<r; i++){
            valores[i] = (long long*) malloc(sizeof(long long) * c);
            for(int j=0; j<c; j++){
                valores[i][j] = 0LL;
            }
        }
    }

    matriz identity(int tamanho){
        matriz result;
        result.start_matriz(tamanho, tamanho);

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
                    mul.valores[i][k] = (mul.valores[i][k] + ((a.valores[i][j] * b.valores[j][k]) % MOD)) % MOD;
                }
            }
        }
        return mul;

    }

    matriz exponenciacao(long long n){
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

    matriz A, B;
    A.start_matriz(2,2);
    B.start_matriz(2,1);

    long long a,b,n,x;

    cin >> a >> b >> n >> x;

    A.valores[0][0] = a;
    A.valores[0][1] = b;
    A.valores[1][0] = 0;
    A.valores[1][1] = 1;

    B.valores[0][0] = x;
    B.valores[1][0] = 1;

    A = A.exponenciacao(n);

    matriz c = A.multiply(A, B);

    cout << c.valores[0][0] << endl;


}
