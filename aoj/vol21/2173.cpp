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
const double EPS = 1e-8; // 許容誤差^2
const double INF = 1e8;
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

/*
  交差判定　直線・線分は縮退してはならない。
  接する場合は交差するとみなす。
  縮退している = 2つのものが区別付かない状態(?)
  isec = intersect
  L = Line
  P = Point
  S = Segment
*/

// 直線と点
bool isecLP(Point a1, Point a2, Point b) {
  return abs(ccw(a1, a2, b)) != 1;
  // return EQ(cross(a2-a1, b-a1), 0); と等価
}

// 直線と直線
bool isecLL(Point a1, Point a2, Point b1, Point b2) {
  return !isecLP(a2-a1, b2-b1, 0) || isecLP(a1, b1, b2);
}

// 直線と線分
bool isecLS(Point a1, Point a2, Point b1, Point b2) {
  return cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS;
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


/* 距離　各直線・線分は縮退してはならない */

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

// 点pの直線aへの反射点を返す
Point reflection(Point a1, Point a2, Point p) {
  return 2.0*proj(a1, a2, p) - p;
}

//点aと点bの距離は abs(a-b)
//#define distPP(p1,p2) abs(p1-p2)

double distLP(Point a1, Point a2, Point p) {
  return abs(proj(a1, a2, p) - p);
}

double distLL(Point a1, Point a2, Point b1, Point b2) {
  return isecLL(a1, a2, b1, b2) ? 0 : distLP(a1, a2, b1);
}

double distLS(Point a1, Point a2, Point b1, Point b2) {
  return isecLS(a1, a2, b1, b2) ? 0 : min(distLP(a1, a2, b1), distLP(a1, a2, b2));
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

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}


double distLPol(Point a1, Point a2, const VP &pol)
{
    double ret = INF;
    int SZ = pol.size();
    rep(i,SZ) ret = min(ret, distLS(a1,a2,pol[i],pol[(i+1)%SZ]));
    return ret;
}

double distPolPol(const VP &pol1, const VP &pol2)
{
    int A = pol1.size(), B = pol2.size();

    double ret = INF;
    rep(i,A)rep(j,B) ret = min(ret, distSS(pol1[i],pol1[(i+1)%A],pol2[j],pol2[(j+1)%B]));
    return ret;
}

int main()
{
    int w,n;
    while(scanf(" %d %d", &w, &n),w)
    {
        vector<VP> polygon(n);
        rep(i,n)
        {
            int m;
            scanf(" %d", &m);
            polygon[i] = VP(m);
            rep(j,m)
            {
                int x,y;
                scanf(" %d %d", &x, &y);
                polygon[i][j] = Point(x,y);
            }
        }

        vector<vector<double>> d(n+2,vector<double>(n+2,INF));
        rep(i,n+2) d[i][i] = 0;
        d[n][n+1] = d[n+1][n] = w;

        rep(i,n)
        {
            d[n][i] = d[i][n] = distLPol(Point(0,0),Point(0,1),polygon[i]);
            d[n+1][i] = d[i][n+1] = distLPol(Point(w,0),Point(w,1),polygon[i]);
        }

        rep(i,n)rep(j,i) d[i][j] = d[j][i] = distPolPol(polygon[i],polygon[j]);

        rep(k,n+2)rep(i,n+2)rep(j,n+2) d[i][j] = min(d[i][j],d[i][k]+d[k][j]);

        printf("%.10f\n", d[n][n+1]);
    }
    return 0;
}
