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
const double EPS = 1e-9; // 許容誤差^2
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
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 直線と線分
bool isecLS(Point a1, Point a2, Point b1, Point b2) {
  return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;
}

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

int main(){
    int w,h,n;
    while(scanf(" %d %d %d", &w, &h, &n), w){
        VP p(2*n);
        rep(i,2*n){
            int x,y;
            scanf(" %d %d", &x, &y);
            p[i] = Point(x,y);
        }

        Point z1(0,0), z2(0,h);
        vector<double> zero_y;
        rep(i,2*n)rep(j,i){
            if(isecLS(p[i],p[j],z1,z2)){
                Point cp = crosspointLL(p[i],p[j],z1,z2);
                zero_y.pb(cp.Y);
            }
        }

        zero_y.pb(0);
        zero_y.pb(h);
        sort(all(zero_y));
        int sz = zero_y.size();
        dbg(sz);

        Point w1(w,0), w2(w,h);

        double ans = 0;
        rep(i,sz-1){
            double L = zero_y[i+1] - zero_y[i];

            Point b(0, (zero_y[i]+zero_y[i+1])/2);
            dbg(b);

            vector<pair<double,int>> v;
            rep(j,2*n){
                double rad = atan2(p[j].Y-b.Y, p[j].X-b.X);
                v.pb({rad,j});
            }
            sort(all(v));

            double l = crosspointLL(w1,w2,b,p[v[n-1].se]).Y;
            l = max(l,0.0);
            double r = crosspointLL(w1,w2,b,p[v[n].se]).Y;
            r = min(r,(double)h);

            ans += L/h * (r-l)/h;
        }

        printf("%.10f\n", ans);
    }
    return 0;


    return 0;
}
