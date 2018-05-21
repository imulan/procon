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
const double EPS = 1e-6; // 許容誤差^2
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

// 2円の交点
VP crosspointCC(Point a, double ar, Point b, double br) {
  VP ps;
  Point ab = b-a;
  double d = abs(ab);
  double crL = (norm(ab) + ar*ar - br*br) / (2*d);
  if (EQ(d, 0) || ar+EPS < abs(crL)) return ps;

  double sub = ar*ar - crL*crL;
  if(EQ(sub,0)) sub = 0;

  Point abN = ab * Point(0, sqrt(sub) / d);
  Point cp = a + crL/d * ab;
  ps.push_back(cp + abN);
  if (!EQ(norm(abN), 0)) ps.push_back(cp - abN);
  return ps;
}

using pd = pair<double,double>;

pd calc(pd p, int b){
    if(b<p.fi) return {p.fi-b, p.se+b};
    else if(b<p.se) return {0, p.se+b};
    return {b-p.se, p.se+b};
}

pd UNI(pd a, pd b){
    double l = max(a.fi,b.fi), r = min(a.se,b.se);
    return {l,r};
}

int main(){
    int n;
    cin >>n;

    vector<int> l(n);
    rep(i,n) cin >>l[i];

    int tx,ty;
    cin >>tx >>ty;
    Point T(tx,ty);

    vector<pd> F(n+1);
    F[0] = {0,0};
    rep(i,n) F[i+1] = calc(F[i], l[i]);

    vector<pd> B(n+1);
    if(LE(F[n].fi,abs(T)) && LE(abs(T),F[n].se)) B[n] = {abs(T),abs(T)};
    else{
        double d;
        if(GE(abs(T), F[n].se)) d = F[n].se;
        else d = F[n].fi;
        B[n] = {d,d};
    }
    for(int i=n-1; i>=0; --i) B[i] = calc(B[i+1], l[i]);

    vector<pd> D(n+1);
    rep(i,n+1) D[i] = UNI(F[i],B[i]);

    Point goal;
    if(EQ(D[n].fi,0)){
        goal = Point(0,0);
    }
    else{
        double sz = sqrt(tx*tx + ty*ty);
        if(LE(sz,0)) goal = Point(D[n].fi,0);
        else{
            double pp = D[n].fi/sz;
            goal = Point(pp*tx, pp*ty);
        }
    }

    VP ans(n);
    ans[n-1] = goal;
    for(int i=n-1; i>0; --i){
        double R = (D[i].fi+D[i].se)*0.5;

        VP cand = crosspointCC(Point(0,0), R, ans[i], l[i]);
        if(cand.empty()) ans[i-1] = Point(ans[i].X+l[i], ans[i].Y);
        else ans[i-1] = cand[0];
    }

    // check
    rep(i,n){
        double d;
        if(i==0) d = abs(ans[0]);
        else d = abs(ans[i]-ans[i-1]);
        assert(LE(d,l[i]));
    }

    // output
    rep(i,n) printf("%.10f %.10f\n", ans[i].X, ans[i].Y);
    return 0;
}
