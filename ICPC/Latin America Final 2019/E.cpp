#include <bits/stdc++.h>

using namespace std;

string bolo;
int tamanho;

int getPos(int x){
    if (x < 0)
        return tamanho + x;
    return x;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    
    cin >> bolo >> n;
    tamanho = bolo.size();
    
    int ans = 0;
    
    for(int i=0; i<tamanho; i++){
        if(bolo[i] == 'E'){
            int soma = 0;
            for(int j=i-(n-1); j<i; j++){
                if(bolo[getPos(j)] == 'E')
                    break;
                soma++;
            
            }
            
            ans += min(n-1, soma);
        
        }
    
    }

}





