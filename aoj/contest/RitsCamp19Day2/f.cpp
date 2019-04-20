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
const double EPS = 1e-6; // 許容誤差^2
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

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

using Vector = Point;

Point READ(){
    double x,y;
    cin >>x >>y;
    return Point(x,y);
}

double calct(Point a, Point b, Point c, Vector u){
    Vector v = b-a;
    Point cp = crosspointLL(a,b,c,c+u);

    double t;
    if(EQ(v.X, 0)){
        if( EQ(v.Y, 0) ){
            while(1){}
        }

        t = (cp.Y - a.Y)/v.Y;
    }
    else{
        t = (cp.X - a.X)/v.X;
    }
    return t;
}

int main(){
    int n;
    cin >>n;

    VP p(n);
    rep(i,n) p[i] = READ();

    double ans = 1e12;
    int min_idx = 0, max_idx = 0;
    double mnt = INF, mxt = -INF;
    rep(i,n){
        Point a = p[0], b = p[1];
        Vector v = b-a;

        Vector mnv = v * polar((double)1.0, -2*PI/3);
        Vector mxv = v * polar((double)1.0, -PI/3);

        Point c = p[i];

        double tt = calct(a,b,c,mnv);
        if(tt < mnt){
            mnt = tt;
            min_idx = i;
        }

        tt = calct(a,b,c,mxv);
        if(tt > mxt){
            mxt = tt;
            max_idx = i;
        }
        ans = abs( (a+mnt*v) - (a+mxt*v) );
    }

    // dbg(ans);
    // printf(" 0 : min %d max %d\n", min_idx, max_idx);

    for(int i=1; i<n; ++i){
        Point a = p[i], b = p[(i+1)%n];
        Vector v = b-a;

        Vector mnv = v * polar((double)1.0, -2*PI/3);
        Vector mxv = v * polar((double)1.0, -PI/3);
        // dbg(v);
        // dbg(mnv);
        // dbg(mxv);

        rep(loop,n){
            double pt = calct(a,b,p[min_idx],mnv);
            double qt = calct(a,b,p[(min_idx+1)%n],mnv);

            if(qt > pt+EPS) break;
            min_idx = (min_idx+1)%n;
        }

        rep(loop,n){
            double pt = calct(a,b,p[max_idx],mxv);
            double qt = calct(a,b,p[(max_idx+1)%n],mxv);

            if(qt < pt-EPS) break;
            max_idx = (max_idx+1)%n;
        }

        // printf(" %d : min %d max %d\n", i,min_idx, max_idx);

        mnt = calct(a,b,p[min_idx],mnv);
        mxt = calct(a,b,p[max_idx],mxv);
        double dd = abs( (a+mnt*v) - (a+mxt*v) );
        ans = min(ans, dd);
    }

    printf("%.10Lf\n", ans);
    return 0;
}
