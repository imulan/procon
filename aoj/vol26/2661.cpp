#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}


/* 基本要素 */
typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double PI = acos(-1);
const double EPS = 1e-7; // 許容誤差^2
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

Point READ(){
    int x,y;
    scanf(" %d %d", &x, &y);
    return Point(x,y);
}

int main(){
    int n[2];
    VP l[2];
    rep(i,2){
        scanf(" %d", &n[i]);

        l[i].pb(Point(0, i*1000));
        rep(j,n[i]) l[i].pb(READ());
        l[i].pb(Point(1000, i*1000));
        n[i] += 2;
    }

    double ans = 10101010;
    rep(i,2){
        rep(j,n[i]-1){
            Point p = l[i][j];
            rep(k,n[!i]-1){
                Point q1 = l[!i][k], q2 = l[!i][k+1];
                ans = min(ans, distSP(q1,q2,p));
            }
        }
    }
    printf("%.10f\n", ans);
    return 0;
}
