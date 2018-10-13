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

// 2直線の交点
Point crosspointLL(Point a1, Point a2, Point b1, Point b2) {
  double d1 = cross(b2-b1, b1-a1);
  double d2 = cross(b2-b1, a2-a1);
  if (EQ(d1, 0) && EQ(d2, 0)) return a1;  // same line
  assert(!EQ(d2, 0)); // 交点がない
  return a1 + d1/d2 * (a2-a1);
}

// 多角形の内部判定
// 点が領域内部なら1、境界上なら2、外部なら0を返す
int inPolygon(const VP& ps, Point p) {
  int n = ps.size();
  bool in = false;
  rep (i, n) {
    Point a = ps[i] - p;
    Point b = ps[(i + 1) % n] - p;
    if (EQ(cross(a,b), 0) && LE(dot(a,b), 0)) return 2;
    if (a.Y > b.Y) swap(a,b);
    if ((a.Y*b.Y < 0 || (a.Y*b.Y < EPS && b.Y > EPS)) && LE(cross(a, b), 0)) in = !in;
  }
  return in;
}

Point READ_P(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

int main(){
    int n,m;
    cin >>n >>m;

    vector<VP> obj(n);
    rep(i,n){
        int L;
        cin >>L;
        rep(j,L) obj[i].pb(READ_P());
    }

    VP tg(m);
    rep(i,m) tg[i] = READ_P();

    VP cand;
    rep(i,n)for(Point p:obj[i]) cand.pb(p);

    rep(i,n)rep(ii,obj[i].size())rep(j,n)rep(jj,obj[j].size()){
        if(i==j && ii==jj) continue;
        Point p = obj[i][ii], q = obj[j][jj];

        rep(a,m)rep(b,m)if(a != b){
            Point pp = tg[a], qq = tg[b];
            if(isecLL(p,pp,q,qq)) cand.pb(crosspointLL(p,pp,q,qq));
        }
    }

    auto inner = [&](Point q){
        rep(i,n)if(inPolygon(obj[i],q)==1) return true;
        return false;
    };

    int ans = 1;
    for(Point p:cand){
        if(inner(p)) continue;

        int tmp = 0;
        rep(i,m){
            VP cps;
            rep(j,n){
                int L = obj[j].size();
                rep(k,L){
                    Point pp = obj[j][k], qq = obj[j][(k+1)%L];
                    if(isecSS(p,tg[i],pp,qq)) cps.pb(crosspointLL(p,tg[i],pp,qq));
                }
            }
            sort(all(cps));

            int ok = 1;
            int SZ = cps.size();
            rep(j,SZ-1){
                Point mid = (cps[j]+cps[j+1])*0.5;
                if(inner(mid)) ok = 0;
            }
            tmp += ok;
        }

        ans = max(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}
