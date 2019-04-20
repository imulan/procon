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

// 直線と点
bool isecLP(Point a1, Point a2, Point b) {
  return abs(ccw(a1, a2, b)) != 1;
  // return EQ(cross(a2-a1, b-a1), 0); と等価
}

// 直線と直線
bool isecLL(Point a1, Point a2, Point b1, Point b2) {
  return !isecLP(a2-a1, b2-b1, 0) || isecLP(a1, b1, b2);
}

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
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


// 頂点の順序（sortやmax_elementに必要）
namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}


using pi = pair<int,int>;
using NODE = pair<Point, pi>;

inline Point read_p(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

int main(){
    int n;
    ll K;
    Point start;
    cin >>n >>K;
    start = read_p();

    vector<string> s(n);
    vector<Line> l(n);
    rep(i,n){
        cin >>s[i];
        l[i].fi = read_p();
        l[i].se = read_p();
    }

    vector<NODE> cp;
    // 直線と直線の交点
    rep(i,n)rep(j,i){
        if(isecLL(l[i].fi, l[i].se, l[j].fi, l[j].se)){
            cp.pb({crosspointLL(l[i].fi, l[i].se, l[j].fi, l[j].se), {j,i}});
        }
    }
    dbg(cp);

    vector<vector<NODE>> on_line(n);
    for(NODE nd:cp){
        Point p = nd.fi;
        rep(i,n){
            if( LE(distLP(l[i].fi, l[i].se, p),0) ) on_line[i].pb(nd);
        }
    }

    rep(i,n) sort(all(on_line[i]));

    int now = -1;
    rep(i,n){
        if( LE(distLP(l[i].fi, l[i].se, start),0) ) now = i;
    }
    dbg(now);

    const pi dammy(191919,191919);

    Point cur = start;

    set<pi> vis;
    vector<pi> ord;

    while(1){

        int idx = lower_bound(all(on_line[now]), NODE(cur,dammy)) - on_line[now].begin();

        int sz = on_line[now].size();



        Point nx =


    }






    return 0;
}
