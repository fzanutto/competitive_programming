#include <bits/stdc++.h>

using namespace std;

#define EPS 1e-9
typedef struct point_i point_i;
typedef struct point point;

struct point_i {
    int x,y;
    point_i() {
        x=0, y = 0;
    }
    point_i(int _x, int _y) : x(_x), y(_y) {}

    bool operator < (point_i b) const {
        if (x - b.x != 0){
            return x < b.x;
        }
        return y < b.y;
    }

	bool operator == (point_i b) const {
		return x == b.x && y == b.y;
	}
};


struct point {
	double x, y;
	point() { x = y = 0; }
	point(double _x, double _y) : x(_x), y(_y) {}

	bool operator < (point b) const {
		if (fabs(x - b.x) > EPS)
			return x < b.x;
		return y < b.y;
	}

	bool operator == (point b) const {
		return (fabs(x - b.x) < EPS && (fabs(y - b.y) < EPS));
	}
};

double dist(point p1, point p2) { // std::hypot(dx, dy) retorna sqrt(dx * dx+ dy * dy)
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double DEG_to_RAD(double d) { return d * M_PI / 180.0; }


point rotate(point p, double theta) {
    double rad = DEG_to_RAD(theta);
    return point(p.x * cos(rad) - p.y * sin(rad), p.x * sin(rad) + p.y * cos(rad));
}

struct line { double a, b, c; };

// recebe dois pontos e retorna uma reta
void pointsToLine(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS) { // linha vertical
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    } else {
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0; // usa b = 1 para retas não verticais
        l.c = -(double)(l.a * p1.x) - p1.y;
    }
}

bool areParallel(line l1, line l2) { // verifica coeficientes a e b
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS);
}

bool areSame(line l1, line l2) { // verifica também o coeficiente c
    return areParallel(l1 ,l2) && (fabs(l1.c - l2.c) < EPS);
}


bool areIntersect(line l1, line l2, point &p) {
    if (areParallel(l1, l2)) return false; // se são paralelas não há interseção

    // resolver sistema de 2 equações lineares com 2 variáveis desconhecidas

    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);

    // caso especial: testar se a reta é vertical para evitar divisão por zero
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);

    return true;
}

struct vec {
    double x, y; // representação
    vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) { // converter dois pontos para um vetor a->b
    return vec(b.x - a.x, b.y - a.y);
}

vec scale(vec v, double s) { // mudar o tamanho/escala das magnitudes do vetor
    return vec(v.x * s, v.y * s);
} // <1 diminuir, 1 manter, >1 aumentar

point translate(point p, vec v) { // transladar um ponto a partir de um vetor
    return point(p.x + v.x , p.y + v.y);
}

//produto escalar de 2 vetores
double dot(vec a, vec b) {
    return (a.x * b.x + a.y * b.y);
}

double norm_sq(vec v) {
    return v.x * v.x + v.y * v.y;
}


double distToLine(point p, point a, point b) {
	//p é o ponto a calcular a distancia
	// a e b sao pontos da reta
    // formula: c = a + u * ab
	point c; //variavel auxiliar
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    c = translate(a, scale(ab, u)); // transladar a para c
    return dist(p, c);
} // Distância euclidiana entre p e c

double distToLineSegment(point p, point a, point b, point &c) {
    vec ap = toVec(a, p), ab = toVec(a, b);
    double u = dot(ap, ab) / norm_sq(ab);
    if (u < 0.0) { c = point(a.x, a.y); // caso 1: mais próximo do ponto a
        return dist(p, a); } // Distância euclidiana entre p e a
    if (u > 1.0) { c = point(b.x, b.y); // caso 2: mais próximo do ponto b
        return dist(p, b); } // Distância euclidiana entre p e b
    return distToLine(p, a, b, c);
} // caso 3: distância entre reta e p


double cross(vec a, vec b) {
    return a.x * b.y - a.y * b.x;
}

bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}

bool cw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) < 0;
}

bool collinear(point p, point q, point r) {
    return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}

double angle(point a, point o, point b) {
    vec oa = toVec(o, a), ob = toVec(o, b);
    return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}


int insideCircle(point_i p, point_i c, int r) { // versão com valores inteiros
    int dx = p.x - c.x, dy = p.y - c.y;
    int Euc = dx * dx + dy * dy, rSq = r * r;
    return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;
} // 0: dentro, 1: borda, 2: fora


bool circle2PtsRad(point p1, point p2, double r, point &c) {
    double d2 = (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
    double det = r * r / d2 - 0.25;
    if (det < 0.0)
        return false;
    double h = sqrt(det);
    c.x = (p1.x + p2.x) * 0.5 + (p1.y - p2.y) * h;
    c.y = (p1.y + p2.y) * 0.5 + (p2.x - p1.x) * h;
    return true;
} // para calcular o outro centro, basta inverter p1 e p2

/*
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
    r = rInCircle(p1, p2, p3); // raio do círculo inscrito
    if (fabs(r) < EPS) return 0; // não há círculo inscrito
    line l1, l2; // bissetrizes
    double ratio = dist(p1, p2) / dist(p1, p3);
    point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
    pointsToLine(p1, p, l1);
    ratio = dist(p2, p1) / dist(p2, p3);
    p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
    pointsToLine(p2, p, l2);
    areIntersect(l1, l2, ctr); // calcular o ponto de interseção
    return 1;
}
*/


double perimeter(const vector<point> &P) {
    double result = 0.0;
    for (int i = 0; i < (int)P.size()-1; i++)
        result += dist(P[i], P[i+1]); // P[0] = P[P.size()-1]
    return result;
}


double area(const vector<point> &P) {
    double result = 0.0, x1,x2,y1,y2;
    for (int i = 0; i < (int)P.size()-1; i++) {
        x1 = P[i].x; x2 = P[i+1].x;
        y1 = P[i].y; y2 = P[i+1].y;
        result += x1*y2 - x2*y1;
    }
    return fabs(result) / 2.0;
}

bool isConvex(const vector<point> &P) {
    int sz = (int)P.size();
    if (sz <= 3) return false; // ponto ou reta não é convexo
        bool isLeft = ccw(P[0], P[1], P[2]);
    for (int i = 1; i < sz-1; i++) {
        if (ccw(P[i], P[i+1], P[(i+2) == sz ? 1 : i+2]) != isLeft)
        return false;
    }
    return true;
}

bool inPolygon(point pt, const vector<point> &P) {
    if ((int)P.size() == 0) return false;
    double sum = 0.0;
    for (int i = 0; i < (int)P.size()-1; i++) {
        if (ccw(pt, P[i], P[i+1]))
            sum += angle(P[i], pt, P[i+1]); // CCW
        else
            sum -= angle(P[i], pt, P[i+1]); // CW
    }
    return fabs(fabs(sum) - 2*M_PI) < EPS;
}


// Intersecção do segmento p-q com reta A-B
point lineIntersectSeg(point p, point q, point A, point B) {
    double a = B.y - A.y;
    double b = A.x - B.x;
    double c = B.x * A.y - A.x * B.y;
    double u = fabs(a * p.x + b * p.y + c);
    double v = fabs(a * q.x + b * q.y + c);
    return point( (p.x * v + q.x * u) / (u+v),
    (p.y * v + q.y * u) / (u+v) );
}

// Corta o polígono Q ao longo da reta definida pelos pontos A e B
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
    vector<point> P;
    for (int i = 0; i < (int)Q.size(); i++) {
        double left1 = cross(toVec(a, b), toVec(a, Q[i]));
        double left2 = 0.0;
        if (i != (int)Q.size()-1)
            left2 = cross(toVec(a, b), toVec(a, Q[i+1]));
        if (left1 > -EPS) // Q[i] está à esquerda de ab
            P.push_back(Q[i]);
        if (left1 * left2 < -EPS) // lado (Q[i], Q[i+1]) cruza ab
            P.push_back(lineIntersectSeg(Q[i], Q[i+1], a, b));
    }
    if (!P.empty() && !(P.back() == P.front()))
        P.push_back(P.front()); // torna último ponto = primeiro ponto
    return P;
}

bool mais_perto_y(point a, point b){
    return a < b;
}


int main(){}
