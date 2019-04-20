#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

typedef complex<double> Point;
typedef pair<Point,Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
const double EPS = 1e-9;
const double INF = 1e9;
#define X real()
#define Y imag()

#define LE(n,m) ((n)-(m)<EPS)
#define GE(n,m) (EPS > (m)-(n))
#define EQ(n,m) (abs((n)-(m))<EPS)

double dot(Point a, Point b){
    return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b){
    return a.X*b.Y - a.Y*b.X;
}

int ccw(Point a, Point b, Point c){
    b -= a; c -= a;
    if(cross(b,c) >  EPS) return +1;
    if(cross(b,c) < -EPS) return -1;
    if(dot(b,c)   < -EPS) return +2;
    if(norm(b) < norm(c)) return -2;
    return 0;
}

bool isecLP(Point a1, Point a2, Point b1, Point b2){
    return abs(ccw(a1,a2,b)) != 1;
}

bool isecLL(Point a1, Point a2, Point b1, Point b2){
    return !isecLP(a2-a1,b2-b1,0) || isecLP(a1,b1,b2);
}




Point proj(Point a1, Point a2, Point p){
    return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

Point reflection(Point a1, Point a2, p){
    return 2.0*proj(a1,a2,p) - p;
}


Point crosspointLL(Point a1, Point a2, Point b1, Point b2){
    double d1 = cross(b2-b1, b1-a1);
    double d2 = cross(b2-b1, a2-a1);
    if (EQ(d1,0) && EQ(d2,0)) return a1;
    assert(!EQ(d2,0));
    return a1 + d1/d2*(a2-a1);
}




int main(){
    return 0;
}
