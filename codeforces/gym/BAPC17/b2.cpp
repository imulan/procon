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

const double pi = acos(-1);

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
int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

VP crosspointLC(Point a1, Point a2, Point c, double r) {
  VP ps;
  Point ft = proj(a1, a2, c);
  if(!GE(r*r,norm(ft-c))) return ps;
  Point dir = sqrt(max(r*r - norm(ft-c), (double)0)) / abs(a2-a1) * (a2-a1);
  ps.push_back(ft + dir);
  if (!EQ(r*r, norm(ft-c))) ps.push_back(ft - dir);
  return ps;
}

// 2円の交点
VP crosspointCC(Point a, double ar, Point b, double br) {
  VP ps;
  Point ab = b-a;
  double d = abs(ab);
  double crL = (norm(ab) + ar*ar - br*br) / (2*d);
  if (EQ(d, 0) || ar+EPS < abs(crL)) return ps;

  // 円が接する時、こことEPSの設定をうまくしないとsqrt(sub)がnanになるので注意
  double sub = ar*ar - crL*crL;
  if(EQ(sub,0)) sub = 0;

  Point abN = ab * Point(0, sqrt(sub) / d);
  Point cp = a + crL/d * ab;
  ps.push_back(cp + abN);
  if (!EQ(norm(abN), 0)) ps.push_back(cp - abN);
  return ps;
}

Point read_p(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

struct edge{
    int to;
    double cost;
};

using P = pair<double,int>;

int main(){
    Point start = read_p(), goal = read_p();

    int n;
    cin >>n;
    VP c(n);
    vector<double> r(n);
    rep(i,n){
        c[i] = read_p();

        int RR;
        cin >>RR;
        r[i] = (double)RR;
    }

    VP pts;
    pts.pb(start);
    pts.pb(goal);
    rep(i,n)rep(j,i){
        for(Point cand:crosspointCC(c[i],r[i],c[j],r[j])) pts.pb(cand);
    }

    auto valid = [&](Point p, Point q){
        rep(i,n){
            if( LE(abs(c[i]-p),r[i]) && LE(abs(c[i]-q),r[i]) ) return true;
        }

        VP z;
        z.pb(p);
        z.pb(q);
        rep(i,n){
            for(Point cp:crosspointLC(p,q,c[i],r[i])){
                bool ok = true;
                // dbg(cp);
                // printf(" DOT %.10Lf  %.10Lf <= %.10Lf? \n", dot(cp-p, q-p), abs(cp-p)+EPS, abs(q-p));
                if( dot(cp-p, q-p) < 0 ) ok = false;
                if( abs(cp-p)+EPS > abs(q-p)) ok = false;
                if(ok) z.pb(cp);
            }
        }

        int Z = z.size();
        sort(all(z));
        rep(i,Z-1){
            Point mid = (z[i]+z[i+1])*(double)0.5;

            bool in_circle = false;
            rep(j,n)if( LE(abs(c[j]-mid),r[j]) ) in_circle = true;
            if(!in_circle) return false;
        }
        return true;
    };

    int V = pts.size();
    vector<vector<edge>> G(V);

    rep(i,V)rep(j,i){
        if(valid(pts[i],pts[j])){
            double d = abs(pts[i]-pts[j]);
            G[i].pb({j,d});
            G[j].pb({i,d});
        }
    }

    priority_queue<P,vector<P>,greater<P>> pq;
    vector<double> d(V,INF);
    d[0] = 0;
    pq.push({0,0});
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();
        int v = now.se;
        if(d[v]<now.fi) continue;
        for(const auto &e:G[v]){
            if(d[e.to] > d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                pq.push({d[e.to], e.to});
            }
        }
    }

    double ans = d[1];
    if(EQ(ans,INF)) printf("impossible\n");
    else printf("%.10Lf\n", ans);
    return 0;
}
