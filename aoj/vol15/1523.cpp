#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

#define double long double

/* 基本要素 */
typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
const double EPS = 1e-5; // 許容誤差^2
const double INF = 1e9;
#define X real()
#define Y imag()
// #define LE(n,m) ((n) < (m) + EPS)
#define LE(n,m) ((n) - (m) < EPS)
// #define GE(n,m) ((n) + EPS > (m))
#define GE(n,m) (EPS > (m) - (n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 内積　dot(a,b) = |a||b|cosθ
double dot(Point a, Point b) {
  return a.X*b.X + a.Y*b.Y;
}

// 外積　cross(a,b) = |a||b|sinθ
double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

// 点の進行方向
// !!! 誤差に注意 !!! (掛け算したものとかなり小さいものを比べているので)
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

double distLP(Point a1, Point a2, Point p) {
  return abs(proj(a1, a2, p) - p);
}

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}


struct P{
    double x,y,z;
    P(){}
    P(double _x, double _y, double _z){
        x = _x;
        y = _y;
        z = _z;
    }
};

P READ(){
    int x,y,z;
    cin >>x >>y >>z;
    return P(x,y,z);
}

int main(){
    P top,c,p;
    int r;

    top = READ();
    c = READ();
    cin >>r;
    p = READ();

    // 中心を(0,0,0)に移動
    top.x -= c.x;
    top.y -= c.y;
    top.z -= c.z;
    p.x -= c.x;
    p.y -= c.y;
    p.z -= c.z;
    c.x -= c.x;
    c.y -= c.y;
    c.z -= c.z;

    // topをx軸正方向に来るように回転
    if( !EQ(abs(Point(top.x,top.y)-Point(0,0)),0) ){
        double theta = acos(top.x/hypot(top.x,top.y));
        if(top.y<0) theta = theta + 2*(PI-theta);

        Point tmp = Point(p.x,p.y) * polar((double)1.0, -theta);
        p.x = tmp.X;
        p.y = tmp.Y;

        tmp = Point(top.x,top.y) * polar((double)1.0, -theta);
        top.x = tmp.X;
        top.y = tmp.Y;
    }
    if(top.z<0){
        top.z = -top.z;
        p.z = -p.z;
    }

    // y軸方向に回転させて、頂点をz軸上へ
    if( !EQ(top.x,0) ){
        double tz = PI/2 - acos(top.x/hypot(top.x,top.z));

        Point tmp = Point(p.x,p.z) * polar((double)1.0,tz);
        p.x = tmp.X;
        p.z = tmp.Y;

        tmp = Point(top.x,top.z) * polar((double)1.0,tz);
        top.x = tmp.X;
        top.z = tmp.Y;
    }

    // pをx軸上へ
    if( !EQ(p.y,0) ){
        double theta = acos(p.x/hypot(p.x,p.y));
        if(p.y<0) theta = theta + 2*(PI-theta);

        Point tmp = Point(p.x,p.y) * polar((double)1.0, -theta);
        p.x = tmp.X;
        p.y = tmp.Y;
    }

    // printf(" top %Lf %Lf %Lf\n", top.x,top.y,top.z);
    // printf("   c %Lf %Lf %Lf\n", c.x,c.y,c.z);
    // printf("   p %Lf %Lf %Lf\n", p.x,p.y,p.z);

    double V = PI*r*r*top.z/3;

    Point O(0,0), A(r,0), B(-r,0), T(0,top.z), P(p.x,p.z);
    Point AA = crosspointLL(A,P,B,T);
    Point BB = crosspointLL(B,P,A,T);

    Point M = (AA+BB)*(double)0.5;
    // dbg(M);

    double h = distLP(AA,BB,T);

    double a = abs(AA-M);
    double xx = r*(T.Y-M.Y)/T.Y;
    double b = sqrt(xx*xx - M.X*M.X);

    double U = PI*a*b*h/3;
    printf("%.10Lf %.10Lf\n", U, V-U);
    return 0;
}
