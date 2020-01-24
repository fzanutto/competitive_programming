#include <bits/stdc++.h>

using namespace std;

const int neutral = 0;
#define comp(a,b) ((a)+(b))

class FenwickTree {

public:
    vector<int> ft;
    FenwickTree(int n){
        ft.assign(n+1, 0);
    
    }
    
    int rsq(int i){
        int sum = neutral;
        for(; i; i-= (i & -i))
            sum = comp(sum, ft[i]);
        return sum;
    }
    
    void update(int i, int v){
        for(; i < (int) ft.size(); i += (i & -i))
            ft[i] = comp(v, ft[i]);
    }
};


pair<pair<int,int>, bool> seqs[1000001];


int main(){

    int n, q;
    
    cin >> n;
    
    FenwickTree menores(1000002);
    FenwickTree maiores(1000002);
    
    int ans = 0;
    
    for(int i=0; i<n; i++){
        cin >> q;
        int menor = 0x3f3f3f3f;
        int maior = 0;
        int temp = 0, ant = 0x3f3f3f3f;
        bool testar = true;
        for(int j=0; j<q; j++){
            cin >> temp;
            
            if(menor < temp && testar){
                testar = false;
            }
            
            menor = min(menor, temp);
            maior = max(maior, temp);            
            ant = temp;
        }

        seqs[i] = {{menor, maior}, !testar};

        menores.update(menor+1, 1);
        maiores.update(maior+1, 1);
        
        if(maior > menor) ans++; // ele junto com ele mesmo da certo
    }
    
    for(int i=0; i<n; i++){
        // quer dizer que pode com qualquer um, pois ele msm satisfaz a condição
        if(seqs[i].second){
            
            ans += n-1;
            cout << "aaaaa " << seqs[i].first.first << " " << n-1 << endl;
            
        } else {
            
            int num = seqs[i].first.first;
            int num2 = seqs[i].first.second;
            
            //cout << "n: " << num << " - " << maiores.rsq(num+1) << endl;
            
            int tempp = ((n - maiores.rsq(num+1)));

            if(num != num2)
                tempp--;
            ans += tempp;
                       
            cout << ans << " - " << tempp << " - " << num << endl;
        }
    }
    
    cout << ans << endl;
    
}
