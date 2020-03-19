#include <bits/stdc++.h>

#define ll long long
#define INF 9223372036854775800
using namespace std;

int inicio[10];
int grafo[10][100];
ll dist[100];
ll tam_ciclo[100];
int visitado[100];
int ciclo[100];

long long GCD(long long a, long long b) { return (b == 0) ? a : GCD(b, a % b); }
inline long long LCM(long long a, long long b) { return a / GCD(a, b) * b; }
inline long long normalize(long long x, long long mod) { x %= mod; if (x < 0) x += mod; return x; }

ll extGcd(ll a, ll b, ll &x, ll &y){
    if(b == 0){
        x = 1; y = 0; return a;
    }
    
    else {
        ll g = extGcd(b, a%b, y, x);
        y -= a / b * x; 
        return g;
    }
}


ll crt(ll rem[], ll mod[], int n){
    if(n == 0) return 0;
    
    ll ans = rem[0];
    ll lcm = mod[0];
    
    for(int i=1; i<n; i++){
        
        ll x,y;
        ll g = extGcd(lcm, mod[i], x, y);
        
        if((rem[i] - ans)%g != 0) return INF;
        
        ans = normalize(ans + x * (rem[i] - ans) / g % (mod[i] / g) * lcm, lcm * mod[i] / g);
        lcm = LCM(lcm, mod[i]);
    }
    
    return ans;
}

void detectcycle(int u, int b){
    ciclo[u] = 1;
    
    if(visitado[u])
        detectcycle(grafo[b][u], b);
}

pair<int, bool> dfs(int u, int t, int c, int b){ //retorna <tamanho ciclo, se chega em t a partir de u>

    visitado[u] = c;
    
    if(!visitado[grafo[b][u]]){
        return dfs(grafo[b][u], t, c+1, b);
    } else {
        if(visitado[t] != 0){
            pair<int, bool> ans = {c+1 - visitado[grafo[b][u]], true};
            int temp = visitado[u];
            visitado[u] = 0;
            detectcycle(grafo[b][u], b);
            visitado[u] = temp;
            return ans;
        }
        else
            return {0, false};
    }
}



int main(){

    int b,z;
    cin >> b >> z;
    int temp;
    for(int i=0; i<b; i++){
        cin >> temp;
        inicio[i] = temp-1;
        for(int j=0; j<z; j++){
            cin >> temp;
            grafo[i][j] = temp - 1;
        }
    }
    
    ll ans = INF;
    int zoo = -1;
    
    for(int i=0; i<z; i++){

        int tempo = 0;
        int ok = 1;
        
        
        for(int j=0; j<b; j++){
            memset(visitado, 0, sizeof visitado);
            memset(ciclo, 0, sizeof ciclo);
            
            auto temp = dfs(inicio[j], i, 1, j);
            
            if(temp.second && ciclo[i]){
                dist[j] = visitado[i] - 1;
                tam_ciclo[j] = temp.first;
            } else if (ciclo[i] == 0){
                ok = 2;
                tempo = visitado[i] - 1;
            } else{
                ok = 0;
                break;
            }
        }
       
        if( ok == 2){
           
            for(int j=0; j<b; j++){
            
                int cur = inicio[j];
                
                for(int k=0; k<tempo; k++)
                    cur = grafo[j][cur];
                if(cur != i){
                    ok = 0;
                    break;
                }
            }
            
            if(ok){
                zoo = i+1;
                ans = tempo;
            }      
        }
        
        if(ok == 1){
            auto temp = min(ans, crt(dist, tam_ciclo, b));
            if(temp < ans){
                ans = temp;
                zoo = i+1;
            }
        }
    }
    
    if(zoo == -1)
        cout << '*' << endl;
    else
        cout << zoo << " " << ans << endl;

}
