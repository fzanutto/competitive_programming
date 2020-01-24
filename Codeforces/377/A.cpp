#include <bits/stdc++.h>

using namespace std;


int total, visitados;
char mapa[505][505];
int n,m,k;


void bfs(pair<int,int> inicio){

    queue<pair<int,int>> fila;
    fila.push(inicio);
    int visitados = 0;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    visitados++;
    mapa[inicio.first][inicio.second] = '1';
    while(k < (total - visitados)){
        pair<int, int> atual = fila.front();
        fila.pop();
        int i = atual.first;
        int j = atual.second;

        for(int x=0; x<4; x++){
            if(k == total - visitados){
                return;
            }
            if(mapa[i+dx[x]][j+dy[x]] == '.'){
                mapa[i+dx[x]][j+dy[x]] = '1';
                fila.push({i+dx[x], j+dy[x]});
                visitados++;
            }
        }
    }
}



int main(){
    cin >> n >> m >> k;

    memset(mapa, 'x', sizeof(char) * 505 * 505 );

    char temp;

    pair<int,int> inicio;
    for(int i=1; i<=n; i++){
        for(int j=1; j<= m; j++){
            cin >> temp;
            mapa[i][j] = temp;
            if(temp == '.'){
                inicio = {i,j};
                total++;
            }
        }
    }


    bfs(inicio);

    for(int i=1; i<=n; i++){
        for(int j=1; j<= m; j++){
            if(mapa[i][j] == '.'){
                cout << 'X';
            } else if(mapa[i][j] == '1'){
                cout << '.';
            } else {
                cout << mapa[i][j];
            }

        }
        cout << endl;
    }


}
