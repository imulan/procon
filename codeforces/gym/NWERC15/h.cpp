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
const double EPS = 1e-7; // 許容誤差^2
const double INF = 1e7;
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

// 線分と線分
bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
}

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

// 点pの直線aへの反射点を返す
Point reflection(Point a1, Point a2, Point p) {
  return 2.0*proj(a1, a2, p) - p;
}

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

int n;
Point hole;
vector<Line> bar;

// 順番に衝突させる
bool check(const vector<int> &x){
    int SZ = x.size();

    vector<Point> t(SZ+1);
    t[SZ] = hole;
    for(int i=SZ-1; i>=0; --i) t[i] = reflection(bar[x[i]].fi, bar[x[i]].se, t[i+1]);

    Point now(0,0);
    vector<bool> rem(n,true);

    rep(i,SZ){
        if(abs(now-t[i]) < EPS) return false;

        int nx = x[i];
        double min_d = INF;
        int idx = -1;
        rep(j,n)if(rem[j]){
            if(isecSS(now, t[i], bar[j].fi, bar[j].se)){
                Point cc = crosspointLL(now, t[i], bar[j].fi, bar[j].se);
                if(ccw(now,t[i],cc)==2) continue;

                double dist = abs(now-cc);
                if(min_d>dist){
                    min_d = dist;
                    idx = j;
                }
            }
        }

        if(nx != idx) return false;

        now = crosspointLL(now, t[i], bar[nx].fi, bar[nx].se);
        rem[nx] = false;
    }

    rep(j,n)if(rem[j]){
        if(isecSS(now, hole, bar[j].fi, bar[j].se)) return false;
    }
    // dbg(x);
    return true;
}

int main(){
    cin >>n;

    int sx,sy;
    cin >>sx >>sy;
    hole = Point(sx,sy);

    bar = vector<Line>(n);
    rep(i,n){
        int x1,y1,x2,y2;
        cin >>x1 >>y1 >>x2 >>y2;
        bar[i] = {Point(x1,y1), Point(x2,y2)};
    }

    vector<int> p(n);
    iota(all(p),0);

    int ans = -1;
    if(check(vector<int>({}))) ans = 0;

    do{
        vector<int> idx;
        rep(i,n){
            idx.pb(p[i]);
            if(ans>=i+1) continue;
            if(check(idx)) ans = max(ans,i+1);
        }
    }while(next_permutation(all(p)));

    if(ans == -1) cout << "impossible" << endl;
    else cout << ans << endl;
    return 0;
}
