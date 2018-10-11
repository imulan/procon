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
const double EPS = 1e-8; // 許容誤差^2
const double INF = 1e9;
#define X real()
#define Y imag()
// #define LE(n,m) ((n) < (m) + EPS)
#define LE(n,m) ((n) - (m) < EPS)
// #define GE(n,m) ((n) + EPS > (m))
#define GE(n,m) (EPS > (m) - (n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

// 頂点の順序（sortやmax_elementに必要）
namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}

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

// 線分と線分
bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 線分と点
bool isecSP(Point a1, Point a2, Point b) {
  return !ccw(a1, a2, b);
}

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

double distSP(Point a1, Point a2, Point p) {
  Point r = proj(a1, a2, p);
  if (isecSP(a1, a2, r)) return abs(r-p);
  //= !ccw(a1, a2, r)
  return min(abs(a1-p), abs(a2-p));
}

double distSS(Point a1, Point a2, Point b1, Point b2) {
  if (isecSS(a1, a2, b1, b2)) return 0;
  return min(min(distSP(a1, a2, b1), distSP(a1, a2, b2)),
   min(distSP(b1, b2, a1), distSP(b1, b2, a2)));
}

// 凸包
// 入力1個 -> 空
// 2個以上の全て同じ点 -> 同じもの2つ
VP convexHull(VP ps) {  // 元の点集合がソートされていいならVP&に
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;  // 余計な点も含むなら == -1 とする
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}

// 凸多角形の内部判定　O(n)
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inConvex(Point p, const VP& ps) {
  int n = ps.size();
  int dir = ccw(ps[0], ps[1], p);
  rep (i, n) {
    int ccwc = ccw(ps[i], ps[(i + 1) % n], p);
    if (!ccwc) return 2;  // 線分上に存在
    if (ccwc != dir) return 0;
  }
  return 1;
}


Point READ_P(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

double ang2rad(double x){
    return PI*x/180;
}

double distHH(VP ps, VP qs){
    int n = ps.size(), m = qs.size();
    double ret = INF;
    rep(i,n)rep(j,m){
        ret = min(ret, distSS(ps[i],ps[(i+1)%n],qs[j],qs[(j+1)%m]));
    }
    return ret;
}

double distPH(Point p, VP ps){
    if(inConvex(p,ps)) return 0;
    int n = ps.size();
    double ret = INF;
    rep(i,n){
        ret = min(ret, distSP(ps[i],ps[(i+1)%n],p));
    }
    return ret;
}

int main(){
    int n;
    while(cin >>n,n){
        vector<VP> building(n);
        vector<double> h(n);
        rep(i,n){
            int V;
            cin >>V >>h[i];
            rep(j,V) building[i].pb(READ_P());
        }

        double theta,phi;
        cin >>theta >>phi;
        theta = ang2rad(theta);
        phi = ang2rad(phi);

        Point start = READ_P(), goal = READ_P();

        int S = n, T = n+1;

        // make convex hull
        rep(i,n){
            VP shadow;
            for(Point p:building[i]){
                double L = h[i]/tan(phi);
                shadow.pb(p + polar(L, theta+PI));
            }

            for(Point p:shadow) building[i].pb(p);

            building[i] = convexHull(building[i]);
        }

        // Floyd-Warshall
        vector<vector<double>> d(n+2, vector<double>(n+2));
        rep(i,n)rep(j,i){
            d[i][j] = d[j][i] = distHH(building[i], building[j]);
        }
        rep(i,n){
            d[S][i] = d[i][S] = distPH(start, building[i]);
            d[T][i] = d[i][T] = distPH(goal, building[i]);
        }
        d[S][T] = d[T][S] = abs(start-goal);

        rep(k,n+2)rep(i,n+2)rep(j,n+2) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

        printf("%.10f\n", d[S][T]);
    }
    return 0;
}
