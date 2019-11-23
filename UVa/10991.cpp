#include <bits/stdc++.h>
using namespace std;

#define EPS 1e-9

struct point{
    double x,y;
    point(double _x, double _y): x(_x), y(_y) {}
    double norm() {return hypot(x,y); }
    point normalized() {
        return point(x,y)*(1.0/norm());
    }
    
    bool operator < (point other) const {
        if (fabs(x-other.x) < EPS) return (fabs(y-other.y) < EPS);
        else return y<other.y;
    }
    
    point operator + (point other) const {
        return point(x+other.x, y+other.y);
    }
    
    point operator * (double k) const{
        return point(x*k, y*k);
    }
};

double dist(point p1, point p2){
    return hypot(p1.x-p2.x, p1.y-p2.y);
}


struct circle{

    point c;
    double r;
    circle(point _c, double _r): c(_c), r(_r) {}
    double area() {return acos(-1.0)*r*r; }
    double sector(double rad) { return 0.5*rad*area()/acos(-1.0); }
};


struct triangle{

    point a,b,c;
    triangle(point _a, point _b, point _c) : a(_a), b(_b), c(_c) {}
    
    double perimeter(){
        return dist(a,b) + dist(b,c) + dist(c,a);
    }
    
    double semiPerimeter(){
        return perimeter()/2.0;
    }
    
    double area(){
        double s = semiPerimeter(), ab = dist(a,b), bc=dist(b,c), ca=dist(c,a);
        return sqrt(s*(s-ab)*(s-bc)*(s-ca));
    }

};


double cosLaw(double a, double b, double c){
    // returns c's opposite angle
    return acos((c*c-a*a-b*b)/(-2.0*a*b));
}


int main(){



    int t;
    cin >> t;
    while(t--){
    
    
    double r1,r2,r3;
    cin >> r1 >> r2 >> r3;

    point A(0,0), B(r2+r3, 0);
    
    circle c2(A, r2), c3(B, r3);
    
    double alfa = cosLaw(r1+r2, r2+r3, r1+r3);
    double beta = cosLaw(r1+r2, r1+r3, r2+r3);
    double teta = cosLaw(r1+r3, r2+r3, r1+r2);
    
    point C((r1+r2)*cos(alfa), (r1+r2)*sin(alfa));
    
    circle c1(C, r1);
    
    triangle t(A,B,C);
    
    double areaT = t.area();
    
    double areaSection = c1.sector(beta) + c2.sector(alfa) + c3.sector(teta);
    
    
    //cout << "tri: "<<areaT << " sect: " << areaSection << endl;
    cout << setprecision(10);
    cout << areaT - areaSection << endl;
    
    }
}


