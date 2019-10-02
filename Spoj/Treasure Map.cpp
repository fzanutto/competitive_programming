#include <bits/stdc++.h>

using namespace std;

int bfs(int matriz[505][505], int n, int m, int t){

    int visitados[n+5][m+5];
    memset(visitados, 0, sizeof(int)*(n+5)*(m+5));

    queue<pair<pair<int,int>, int>> fila;
    fila.push({{1,1}, t});

    visitados[1][1] = 1;

    int dx[] = {1, -1, 0, 0} ;
    int dy[] = {0, 0, 1, -1} ;

    while (!fila.empty()){
        pair<pair<int,int>, int> a = fila.front();
        fila.pop();

        int i = a.first.first;
        int j = a.first.second;
        t = a.second;
        //cout << "atual: " << i << " " << j << "   t = " << t <<endl;

        if (i == n && j == m){
            return true;
        }

        if(matriz[i][j] - t < 1){
            continue;
        }

        for(int x=0; x<4; x++){

            if (!visitados[i+dx[x]][j+dy[x]] && (matriz[i+dx[x]][j+dy[x]] - (t+1) > 0)){
                //cout << "prox: " << i+dx[x] << " " << j+dy[x] << " - " << matriz[i+dx[x]][j+dy[x]] << "  t+1 = " << t+1 <<endl;
                fila.push({{i+dx[x], j+dy[x]}, t+1});
                visitados[i+dx[x]][j+dy[x]] = 1;
            }
        }

    }
    return false;
}

int main(){

    int n,m;
    int matriz[505][505];
    memset(matriz, 0, sizeof(int) * 505*505);
    cin >> n >> m;
    for(int i=1; i<= n; i++){
        for (int j=1; j<=m;j++){
            cin >> matriz[i][j];
        }
    }


    int l=0;
    int r = matriz[n][m];

    while(l < r){
        //cout << l << " " << r << endl;
        int mid = (l+r+1) / 2;
        if(bfs(matriz, n, m, mid)){
            l = mid;
        } else {
            r = mid - 1;
        }
    }
    //cout << "l = " << l << endl;
    if(bfs(matriz, n, m, l)){
        cout << l << endl;
    } else {
        cout << -1 << endl;
    }

}
