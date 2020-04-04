#include <bits/stdc++.h>
using namespace std;

vector<int> inicio[20005];
int fim[20005];

int main(){

    int n;
    
    cin >> n;
    
    vector<int> ans;
    
    for(int i=0; i<n;i++){
        int a,b;
        cin >> a >> b;
        
        inicio[min(a,b)+10000].push_back(max(a,b)+10000);
        fim[max(a,b)+10000]++;
    
    }
    
    queue<int> fila;
    int cont = 0;
    
    for(int i=0; i<20001; i++){

        for(int a: inicio[i]){
            cont++;
            fila.push(a);
        }        
        
        if(fim[i] > 0){
            ans.push_back(i-10000);
            while(fila.size()){
                fim[fila.front()]--; 
                fila.pop();
            }
        
        }
    }
    
    cout << ans.size() << endl;
    for(int i=0; i<ans.size()-1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1] << endl;

}
