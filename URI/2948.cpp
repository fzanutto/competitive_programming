#include <bits/stdc++.h>

#define EPS 1e-9

using namespace std;

struct point{

    double x, y;
    point() {x=y=0.0;}
    point(double _x, double _y) : x(_x), y(_y) {}
    
    point operator *(double k) const{
        return  point(x*k, y*k);
    }
    
    point operator +(point other) const{
        return point(x+other.x, y+other.y);
    }
    point operator -(point other) const{
        return point(x-other.x, y-other.y);
    }

};

double dist(point p1, point p2){
    return hypot(p1.x-p2.x, p1.y-p2.y);

}
double cross(point p1, point p2){
    return p1.x*p2.y - p1.y*p2.x;
}

point rotate(point p, double rad){
    return point(p.x * cos(rad) - p.y * sin(rad),
    p.x*sin(rad) + p.y * cos(rad));

}

struct circle {
    point c;
    double r;
    circle() {c = point(); r = 0;}
    circle(point _c, double _r) : c(_c), r(_r){}
    double area(){return acos(-1.0)*r*r;}
    double chord(double rad) {return 2*r*sin(rad/2.0); }
    
    double sector(double rad) { return 0.5*rad*area()/acos(-1.0); }
    
    double intersects(circle other){
        return dist(c, other.c) < r + other.r;
    }
    
    bool contains(point p ) { return dist(c,p) <= r+EPS; }
};


circle circumcircle(point a, point b, point c){
    circle ans;
    point u = point((b-a).y, -(b-a).x);
    point v = point((c-a).y, -(c-a).x);
    point n = (c-b)*0.5;
    double t = cross(u,n)/cross(v,u);
    ans.c = ((a+c)*0.5) + (v*t);
    ans.r = dist(ans.c, a);
    
    return ans;
}


circle minimunCircle(vector<point> p ){
    random_shuffle(p.begin(), p.end());
    circle C = circle(p[0], 0.0);
    for(int i=0; i < (int)p.size(); i++){
        if(C.contains(p[i])) continue;
        C = circle(p[i], 0.0);
        for(int j=0; j<i; j++){
            if(C.contains(p[j])) continue;
            C = circle((p[j] + p[i])*0.5, 0.5 * dist(p[j], p[i]));
            
            for(int k=0; k<j; k++){
                if(C.contains(p[k])) continue;
                C = circumcircle(p[j], p[i], p[k]);
            
            }
        }
    }

    return C;
}


int main(){
    int n;
    
    scanf("%d", &n);
    
    vector<point> pontos;
    
    for(int i=0; i < n; i++){

        double a,b;
        
        scanf("%lf %lf", &a, &b);

        pontos.push_back(point(a,b));
    }

    circle C = minimunCircle(pontos);
    
    printf("%.2f %.2f %.2f %.2f\n", C.c.x, C.c.y, C.r, 8*3.14*C.r);
    
}
