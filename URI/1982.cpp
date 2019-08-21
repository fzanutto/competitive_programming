#include <bits/stdc++.h>
using namespace std;

typedef struct point_i point;

struct vec {
    double x, y; // representação
    vec(double _x, double _y) : x(_x), y(_y) {}
};


struct point_i {
    int x,y;
    point_i() {
        x=0, y = 0;
    }
    point_i(int _x, int _y) : x(_x), y(_y) {}

    bool operator < (point b) const {
        if (x - b.x != 0){
            return x < b.x;
        }
        return y < b.y;
    }
};

vec toVec(point a, point b) { // converter dois pontos para um vetor a->b
    return vec(b.x - a.x, b.y - a.y);
}

double dist(point p1, point p2) { // std::hypot(dx, dy) retorna sqrt(dx * dx+ dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}
double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}

double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool cw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) < 0;
}

double angle(point a, point o, point b) {
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}


double perimeter(const vector<point> &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size()-1; i++)
        result += dist(P[i], P[i+1]); // P[0] = P[P.size()-1]
    return result;
}

bool mais_perto_y(point a, point b){
    return a < b;
}


int main() {

    int qtd;

    while(1) {
        cin >> qtd;
        if(qtd == 0){
            break;
        }

        vector<point> pontos;
        for(int i=0; i< qtd; i++) {
            int x,y;

            cin >> x >> y;

            point p = point(x, y);
            pontos.push_back(p);
        }

        //ordenar pontos
        sort(pontos.begin(), pontos.end(), mais_perto_y);
        //ordenou certinho

        vector<point> pilha;
        pilha.push_back(pontos[0]);
        pilha.push_back(pontos[1]);

        //cima para baixo
        int c = 2;
        while (c < pontos.size()) {
            if(ccw(pilha[pilha.size() - 2], pilha[pilha.size() - 1], pontos[c])) {
                //cout << " tirar da pilha " << pilha.back().x << " " << pilha.back().y;
                pilha.pop_back();
            } else {
                pilha.push_back(pontos[c]);
                c++;
            }
            if(pilha.size() < 2){
                pilha.push_back(pontos[c]);
                c++;
            }

        }

        //baixo para cima
        reverse(pontos.begin(), pontos.end());
        vector<point> pilha2;
        pilha2.push_back(pontos[0]);
        pilha2.push_back(pontos[1]);
        c = 2;
         while (c < pontos.size()) {

            //cout << "tentando com " << pontos[c].x << " " << pontos[c].y << endl;

            if(ccw(pilha2[pilha2.size() - 2], pilha2[pilha2.size() - 1], pontos[c])) {
               // cout << " tirar da pilha2 " << pilha2.back().x << " " << pilha2.back().y;
                pilha2.pop_back();
            } else {
                pilha2.push_back(pontos[c]);
                c++;
            }

            if(pilha2.size() < 2){
                pilha2.push_back(pontos[c]);
                c++;
            }

        }


        for(int i=1; i< pilha2.size(); i++) {
            pilha.push_back(pilha2[i]);
        }
        float tot = 0;
        for(int i=0; i< pilha.size() - 1; i++) {
            tot += dist(pilha[i], pilha[i+1]);
        }

        cout << fixed << setprecision(2);
        cout << "Tera que comprar uma fita de tamanho " << tot << "." << endl;

    }

    return 0;

}
