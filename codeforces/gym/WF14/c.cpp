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

// 多角形の符号付面積
double area(const VP& ps) {
  double a = 0;
  rep (i, ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
  return a / 2;
}

// 多角形の幾何学的重心
Point centroid(const VP& ps) {
  int n = ps.size();
  double aSum = 0;
  Point c;
  rep (i, n) {
    double a = cross(ps[i], ps[(i+1) % n]);
    aSum += a;
    c += (ps[i] + ps[(i+1) % n]) * a;
  }
  return 1 / aSum / 3 * c;
}

Point READ(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

void OUT(double l, double r){
    printf("%d", (int)floor(l));

    printf(" .. ");

    if(GE(r,INF)) printf("inf");
    else printf("%d", (int)ceil(r));

    printf("\n");
}

int main(){
    int n;
    cin >>n;

    VP p(n);
    double max_x = -INF, min_x = INF;
    rep(i,n){
        p[i] = READ();
        if(EQ(p[i].Y, 0)){
            max_x = max(max_x, p[i].X);
            min_x = min(min_x, p[i].X);
        }
    }

    double l=0, r=INF;
    int idx = 0;

    auto REV = [&](){
        rep(i,n){
            p[i] = Point(-p[i].X, p[i].Y);
        }
        reverse(all(p));
        idx = n-1;
    };

    for(double cx:{max_x, -min_x}){
        Point g = centroid(p);
        double S = abs(area(p));

        double d1x = cx - g.X;
        double d2x = cx - p[idx].X;

        // dbg(p);
        // dbg(cx);
        // dbg(d1x);
        // dbg(d2x);
        // dbg(g);

        if( GE(d1x*d2x,0) ){
            if( LE(g.X, cx) ){
                REV();
                // dbg("CONT");
                continue;
            }
            else{
                printf("unstable\n");
                return 0;
            }
        }
        else{
            double w = -d1x*S / d2x;
            // dbg(w);
            if( LE(g.X, cx) ) r = min(r,w);
            else l = max(l,w);
        }

        REV();
    }

    // dbg(l);
    // dbg(r);
    OUT(l,r);
    return 0;
}
