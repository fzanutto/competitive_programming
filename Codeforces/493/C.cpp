#include <bits/stdc++.h>

using namespace std;


int main(){

    int a,b;
    
    cin >> a;
    vector<int> pontosA(a);
    
    for(int i=0; i<a; i++)
        cin >> pontosA[i];
    
    cin >> b;
    vector<int> pontosB(b);
    for(int i=0; i<b; i++)
        cin >> pontosB[i];
        
        
    sort(pontosA.begin(), pontosA.end());
    sort(pontosB.begin(), pontosB.end());
    
    
    pair<int,int> m = {-0x3f3f3f3f,0};
    int d;
    
    for(int i=0; i<a; i++){
        d = pontosA[i];
        
        int x = (pontosA.end()-upper_bound(pontosA.begin(), pontosA.end(), d));
        int pa = x*3 + (a-x)*2;
        int y = (pontosB.end()-upper_bound(pontosB.begin(), pontosB.end(), d));
        int pb = y*3 + (b-y)*2;
        
        //cout << pa << " " << pb << " - " << d << " - " << x << endl;
        if(pa - pb > m.first - m.second)
            m = {pa, pb};
        else if(pa-pb == m.first - m.second && pa > m.first)
            m = {pa, pb};
    }
    
    for(int i=0; i<b; i++){
        d = pontosB[i];
        
        int x = (pontosA.end()-upper_bound(pontosA.begin(), pontosA.end(), d));
        int pa = x*3 + (a-x)*2;
        int y = (pontosB.end()-upper_bound(pontosB.begin(), pontosB.end(), d));
        int pb = y*3 + (b-y)*2;
        
        //cout << pa << " " << pb << " - " << d << " - " << x << endl;
        
        if(pa - pb > m.first - m.second)
            m = {pa, pb};
        else if(pa-pb == m.first - m.second && pa > m.first)
            m = {pa, pb};
    
    }
    
    d = 0;
    
    int x = (pontosA.end()-upper_bound(pontosA.begin(), pontosA.end(), d));
    int pa = x*3 + (a-x)*2;
    int y = (pontosB.end()-upper_bound(pontosB.begin(), pontosB.end(), d));
    int pb = y*3 + (b-y)*2;
    
    //cout << pa << " " << pb << " - " << d << " - " << x << endl;
    if(pa - pb > m.first - m.second)
        m = {pa, pb};
    else if(pa-pb == m.first - m.second && pa > m.first)
        m = {pa, pb};
   
    
    cout << m.first << ":" << m.second << endl;
    
}
