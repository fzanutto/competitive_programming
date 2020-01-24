#include <bits/stdc++.h>

using namespace std;


struct point {
    int x,y;
    point() {x=0, y=0;}
    point(int _x, int _y){
        x = _x;
        y = _y;
    }
};


int main(){
    
    int n;
    
    cin >> n;
    
    
    vector<pair<point,point>> r1(n), r2(n), cp(n);
    
    for(int i=0; i<n; i++){
        int x1,y1,x2,y2;
        
        cin >> x1 >> y1 >> x2 >> y2;
        
        r1[i] = {point(x1,y1), point(x2,y2)};
    }
    
    cp = r2 = r1;
    
    int i;
    for(i=1; i<n; i++){
        pair<point,point> novo;
        
        novo.first = point(max(r1[i].first.x, r1[i-1].first.x), max(r1[i].first.y, r1[i-1].first.y));
        
        novo.second = point(min(r1[i].second.x, r1[i-1].second.x), min(r1[i].second.y, r1[i-1].second.y));
        
        //cout << novo.first.x << " " << novo.first.y << " - " << novo.second.x << " " << novo.second.y <<  endl;
        
        if(novo.first.x > novo.second.x || novo.first.y > novo.second.y){
            break;
        }
        
        r1[i] = novo;
    }
    
    int erro = i;
    
    for(i=n-2; i>=0; i--){
        pair<point,point> novo;
        
        novo.first = point(max(r2[i].first.x, r2[i+1].first.x), max(r2[i].first.y, r2[i+1].first.y));
        
        novo.second = point(min(r2[i].second.x, r2[i+1].second.x), min(r2[i].second.y, r2[i+1].second.y));
        
        //cout << novo.first.x << " " << novo.first.y << " - " << novo.second.x << " " << novo.second.y <<  endl;
        
        if(novo.first.x > novo.second.x || novo.first.y > novo.second.y){
            break;
        }
        
        r2[i] = novo;
    }
    
    int erro2 = i;
    
    r1=r2=cp;
    
    
    for(i=1; i<n; i++){
        if(i == erro)
            r1[i] = r1[i-1];
            
        pair<point,point> novo;
        
        novo.first = point(max(r1[i].first.x, r1[i-1].first.x), max(r1[i].first.y, r1[i-1].first.y));
        
        novo.second = point(min(r1[i].second.x, r1[i-1].second.x), min(r1[i].second.y, r1[i-1].second.y));
        
        //cout << novo.first.x << " " << novo.first.y << " - " << novo.second.x << " " << novo.second.y <<  endl;
        
        if(novo.first.x > novo.second.x || novo.first.y > novo.second.y){
            break;
        }
        
        r1[i] = novo;
    }
    
    if(i == n){
        cout << r1[n-1].first.x << " " << r1[n-1].first.y << endl;
        return 0;
    }
    
    for(i=n-2; i>=0; i--){
        if(i == erro2)
            r2[i] = r2[i+1];
        pair<point,point> novo;
        
        novo.first = point(max(r2[i].first.x, r2[i+1].first.x), max(r2[i].first.y, r2[i+1].first.y));
        
        novo.second = point(min(r2[i].second.x, r2[i+1].second.x), min(r2[i].second.y, r2[i+1].second.y));
        
        //cout << novo.first.x << " " << novo.first.y << " - " << novo.second.x << " " << novo.second.y <<  endl;
      
        r2[i] = novo;
    }
    
    cout << r2[0].first.x << " " << r2[0].first.y << endl;
}
