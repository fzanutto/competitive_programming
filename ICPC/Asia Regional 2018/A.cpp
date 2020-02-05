#include <bits/stdc++.h>

using namespace std;

const int N = 200005;

int t[4*N], lz[4*N];

int a[N];

void build(int i, int l, int r) {
	if (l == r) {
		t[i] = a[l];
	} else {
		int m = (l+r)/2;
		build(2*i, l, m);
		build(2*i+1, m+1, r);
		t[i] = max(t[2*i], t[2*i+1]);
	}
}

void push(int i, int l, int r) {
	if (lz[i]) {
		t[i] += lz[i];
		if (l != r) {
			lz[2*i] += lz[i];
			lz[2*i+1] += lz[i];
		}
		lz[i] = 0;
	}
}

int query(int i, int l, int r, int ql, int qr) {
	push(i, l, r);
	if (ql <= l && r <= qr) return t[i];
	if (qr < l || r < ql) return 0;
	int m = (l+r)/2;
	
	return max(query(2*i, l, m, ql, qr), query(2*i+1, m+1, r, ql, qr));
}

void update(int i, int l, int r, int ql, int qr, int x) {
	// nao esqueçam!!!
	push(i, l, r);
	if (qr < l || r < ql) return;
	if (ql <= l && r <= qr) {
		lz[i] += x;
		push(i, l, r);
	} else {
		int m = (l+r)/2;
		update(2*i, l, m, ql, qr, x);
		update(2*i+1, m+1, r, ql, qr, x);
		
		t[i] = max(t[2*i], t[2*i+1]);
	}
}

struct ponto {

    int ini, fim;
    bool inicio;
    
    ponto(int i, int f, bool b){
        ini = i;
        fim = f;
        inicio = b;
    }

};

bool operator<(const ponto &a, const ponto &b){
    
    if(a.ini != b.ini){
        return a.ini < b.ini;
    } else {
        return a.inicio > b.inicio;
    }
}

int main() {
	
	int n;
	
	cin >> n;
	
	vector<ponto> pontos;
	
	for(int i=0; i<n; i++){
	    int ux, uy, vx, vy;
	    
	    cin >> ux >> uy >> vx >> vy;
	    
	    pontos.push_back(ponto(uy,0,false)); // cood de cima
	    pontos.push_back(ponto(vy,uy,true)); // cood de baixo
	
	}
	
	sort(pontos.begin(), pontos.end());
	
	int ind = 0;
	int cont = 0;
	
	map<int,int> map_pontos, map_indice;

	
	for(int i=0; i<pontos.size(); i++){
	    
	    //cout << pontos[i].ini << " " << pontos[i].fim << " " << pontos[i].inicio << endl;
	    
	    if(map_pontos.find(pontos[i].ini) == map_pontos.end()){
	        map_pontos[pontos[i].ini] = ++ind;
	    }
	    
	    map_indice[i] = ind;
	    
	    if(pontos[i].inicio){
	        cont++;
	    }
	    
	    a[ind] = max(cont, a[ind]);
	    
	    if(pontos[i].inicio == false)
	        cont--;
	}
	
	build(1, 1, ind);
	/*
    for(int i=1; i<=ind; i++){
        cout << query(1, 1, ind, i, i) << " ";
    }
    cout << endl;
	
	cout << "max: " << query(1, 1, ind, 1, ind) << endl;
	*/
	// construir a seg tree, passar de novo pelo array de pontos, update no valor da segtree em -1 do range atual até o final do retangulo que eu to passando, ver se a soma do valor atual do vetor + o max da segtree é maior que a resposta salva
	int ans = 2;
	
	for(int i=0; i<pontos.size(); i++){ // nao precisa passar pelo ultimo pq o ultimo sempre vai ser o final de algum retangulo
	    
	    bool remove = false;
	    int cur = 0x3f3f3f3f;
	    do {
	        if(pontos[i].inicio){
                cur = pontos[i].ini;
                
                //cout << "retangulo " << pontos[i].ini << " ate " << pontos[i].fim << endl;
	            //cout << "-1 de " << map_pontos[pontos[i].ini] << " ate " << map_pontos[pontos[i].fim] << endl;
	            update(1, 1, ind, map_pontos[pontos[i].ini], map_pontos[pontos[i].fim], -1);
	            /*
	            for(int i=1; i<=ind; i++){
	                cout << query(1, 1, ind, i, i) << " ";
	            }
	            cout << endl;
	            */
	            i++;
	            remove = true;
	        }
	    } while(pontos[i].inicio && pontos[i].ini == cur);

	    if(remove) i--;
	    
	    //cout << query(1, 1, n+n, 1, n+n) << endl;
	    ans = max(ans, a[map_indice[i]] + query(1, 1, ind, map_indice[i], ind));
	}
	
	cout << ans << endl;
	/*
	for(int i=1; i<=n+n; i++){
	    cout << a[i] << " ";
	}
	cout << endl;
    
    */
    return 0;
}
