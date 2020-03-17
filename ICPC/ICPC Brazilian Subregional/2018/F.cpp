#include <bits/stdc++.h>

#define INF 0x3f3f3f3f

using namespace std;

int n;
int total;

struct show {

    int palco;
    int inicio;
    int fim;
    int valor;
    
    show() {palco=inicio=fim=valor = 0;}
    
    show(int p, int i, int f, int v): palco(p), inicio(i), fim(f), valor(v) {}
    
    bool operator <(const show &b) const {
        return (inicio == b.inicio) ? (fim < b.fim) : (inicio < b.inicio);
    }
    
    bool operator <(const int &b) const {
        return inicio < b;
    }
};




vector<show> shows;

int memo[1<<10][1001];

int calc(int bitmask, int i){
    
    if(i == total){
        if(bitmask == (1<<n) - 1)
            return 0;
        else
            return -INF;
    }
    
    if (memo[bitmask][i] != -1)
        return memo[bitmask][i];
        
    
    int ind = lower_bound(shows.begin(), shows.end(), shows[i].fim) - shows.begin();
    
    return memo[bitmask][i] = max(calc(bitmask | (1 << shows[i].palco), ind) + shows[i].valor, calc(bitmask, i+1));
}



int main(){
    
    cin >> n;
    
    int qtd;
    
    memset(memo, -1, sizeof memo);
    
    for(int i=0; i<n; i++){
        cin >> qtd;
        
        for(int j=0; j<qtd; j++){
            total++;
            show temp;
            cin >> temp.inicio;
            cin >> temp.fim;
            cin >> temp.valor;
            temp.palco = i;
            
            shows.push_back(temp);
            
        }
    }
    
    
    sort(shows.begin(), shows.end());
    
    int ans = calc(0,0);
    if(ans < 0)
        cout << -1;
    else
        cout << ans;
    
    cout << endl;
    

}
