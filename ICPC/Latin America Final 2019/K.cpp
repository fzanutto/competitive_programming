#include <bits/stdc++.h>
 
using namespace std;
 
int main(){
    string c;
    cin >> c;
 
    char ant = c[0];
    int grau = 0;
    vector<long long> raizes;
    
    for(int i=1; i<c.size(); i++){
        if(c[i] != ant){
            grau++;
            raizes.push_back(i*2+1);
        }
        ant = c[i];
    }
    
    cout << grau << endl;
    
    vector<pair<long long,long long>> p(1,{0,1}), pp(1,{0,1});
    
    for(int i=0; i<raizes.size(); i++){
    
        pp = p;
        
        // multiply with x
        for(int j=0; j<p.size(); j++){
            p[j].first++;
            pp[j].second *= raizes[i];
        }
        p.push_back({0,0});
        
        for(int j=1; j<p.size(); j++){
            p[j] = {p[j].first - pp[j-1].first, p[j].second - pp[j-1].second};
        }
    }
    
    int primeiro = 1;
    
    if(grau%2 == 0){
        if(c[0] == 'A'){
            primeiro *= -1; 
        }
    } else {
        if(c[0] == 'H'){
            primeiro *= -1;
        }
    }
    
    
    bool certo = (primeiro == p[0].second);
    
    for(int i=0; i<p.size()-1; i++){
        if(!certo){
            p[i].second *= -1;
        }
        cout << p[i].second << " ";
    }
    if(!certo){
        p[p.size()-1].second *= -1;
    }
    cout << p[p.size()-1].second;
    
    cout << endl;
    
}
