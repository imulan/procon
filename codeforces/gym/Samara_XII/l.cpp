#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

/* 基本要素 */
typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
const double EPS = 1e-9; // 許容誤差^2
const double INF = 1e9;
#define X real()
#define Y imag()
#define LE(n,m) ((n) - (m) < EPS)
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

bool inner(Point a, double ar, Point b, double br){
    return LE(abs(a-b)+br, ar);
}

int main(){
    Point p[2];
    double r[2];
    rep(i,2){
        double x,y;
        scanf(" %lf %lf %lf", &x, &y, &r[i]);
        p[i] = {x,y};
    }

    auto isOut = [&](int idx, Point c){
        double d = abs(c - p[idx]);
        return GE(d, r[idx]);
    };

    auto getPt = [&](double t){
        return (1-t)*p[0] + t*p[1];
    };

    auto calcRad = [&](Point c){
        rep(i,2)if(isOut(i,c)) return -1.0;

        double ok = 0, ng = 1e5;
        rep(loop,100){
            double mid = (ok+ng)/2;
            bool f = true;
            rep(i,2)if(!inner(p[i],r[i],c,mid)) f = false;

            if(f) ok = mid;
            else ng = mid;
        }
        return ok;
    };

    double L=0, R=1;
    rep(loop,100){
        double m1 = (2*L+R)/3, m2 = (L+2*R)/3;
        Point c1 = getPt(m1), c2 = getPt(m2);

        if(isOut(0,c1)) R = m2;
        else if(isOut(1,c2)) L = m1;
        else{
            if(calcRad(c1) > calcRad(c2)) R = m2;
            else L = m1;
        }
    }

    Point c = getPt(L);
    printf("%.15f %.15f %.15f\n", c.X, c.Y, calcRad(c));

    return 0;
}
