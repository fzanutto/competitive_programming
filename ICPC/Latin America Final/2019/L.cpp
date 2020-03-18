#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mapa2;
int n,m;

bool check(int x){
	int cont = 0;
	
	for(int i=x-1; i<m; i++){
		cont = 0;
		for(int j=0; j<n; j++){
			if(mapa2[j][i] >= x){
				cont++;
			} else {
				cont = 0;
			}
			
			if(cont >= x){
				return true;
			}
		}
	}
	
	return false;
}

int main(){
	
	cin >> n >> m;
	
	vector<vector<char>> mapa(n, vector<char>(m));
	
	mapa2.assign(n, vector<int>(m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mapa[i][j];
		}
	}

	int cont = 0;
	
	for(int i=0; i<n; i++){
		char ant = mapa[i][0];
		cont = 0;
		for(int j=0; j<m; j++){
			if(ant == mapa[i][j])
				cont++;
			else
				cont = 1;
			ant = mapa[i][j];
			mapa2[i][j]=cont;
		}
	}
	/*
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cout << mapa2[i][j];
		cout << endl;
	}
	*/
	
	int l=0;
	int r = m;
	
	while(l < r){
		int mid = (r+l+1)/2;
		
		//cout << "checking: " << mid << endl;
		if(check(mid)){
			
			l = mid;
		} else {
			
			r = mid-1;
		}
		
	}
	
	cout << l*l << endl;
	
}
