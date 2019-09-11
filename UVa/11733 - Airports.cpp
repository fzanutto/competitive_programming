#include <bits/stdc++.h>
using namespace std;
#define long long int
int main(){
    int t;
    cin >> t;

    int n,m,a;
    int x,y,c;

    for(int caso=0; caso<t; caso++){

        int visitados[10001]= {};

        cin >> n >> m >> a;
        vector<pair<int, pair<int,int>>> arestas;

        for(int i=0; i<m; i++){
            cin >> x >> y >> c;
            if(c < a){
                arestas.push_back({c, {x,y}});
            }
        }

        sort(arestas.begin(), arestas.end());

        int num_comp = 0;
        int diferentes = n;
        int custo = 0;
        for(int x=0; x<arestas.size(); x++){
            pair<int, pair<int,int> > a = arestas[x];
            //cout << a.second.first << " - " << a.second.second << endl;

            //nenhum pertence a um componente
            if(visitados[a.second.first]==0 && visitados[a.second.second]==0){
                num_comp++;
                diferentes--;
                visitados[a.second.first] = num_comp;
                visitados[a.second.second] = num_comp;
                custo += a.first;
            }
            //um deles é 0, o outro nao
            else if (visitados[a.second.first]==0 && visitados[a.second.second] !=0){
                visitados[a.second.first] = visitados[a.second.second];
                custo += a.first;
                diferentes--;
            }
            //um deles é 0, o outro nao
            else if (visitados[a.second.second]==0 && visitados[a.second.first] !=0){
                visitados[a.second.second] = visitados[a.second.first];
                custo += a.first;
                diferentes--;
            }
            //ambos sao de comps diferentes
            else if (visitados[a.second.second] != visitados[a.second.first]) {

                int trocar = visitados[a.second.second];
                for(int i=0; i<n+1; i++){
                    if(visitados[i] == trocar){
                        visitados[i] = visitados[a.second.first];
                    }
                }
                custo += a.first;
                diferentes--;

            }
            // no caso de ambos serem do msm nao add aresta para nao criar ciclo
        }

        cout << "Case #" << (caso+1) << ": " << custo + diferentes*a << " " << diferentes << endl;
    }
}
