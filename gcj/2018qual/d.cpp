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

typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double EPS = 1e-9;
const double INF = 1e9;
#define X real()
#define Y imag()
// #define LE(n,m) ((n) < (m) + EPS)
#define LE(n,m) ((n) - (m) < EPS)
// #define GE(n,m) ((n) + EPS > (m))
#define GE(n,m) (EPS > (m) - (n))
#define EQ(n,m) (abs((n)-(m)) < EPS)

double dot(Point a, Point b) {
  return a.X*b.X + a.Y*b.Y;
}

double cross(Point a, Point b) {
  return a.X*b.Y - a.Y*b.X;
}

int ccw(Point a, Point b, Point c) {
  b -= a;  c -= a;
  if (cross(b,c) >  EPS) return +1;  // counter clockwise
  if (cross(b,c) < -EPS) return -1;  // clockwise
  if (dot(b,c)   < -EPS) return +2;  // c--a--b on line
  if (norm(b) < norm(c)) return -2;  // a--b--c on line or a==b
  return 0;                          // a--c--b on line or a==c or b==c
}

namespace std {
  bool operator<(const Point a, const Point b) {
    return a.X != b.X ? a.X < b.X : a.Y < b.Y;
  }
}

#define ps_edge(PS,i) PS[i],PS[(i+1)%PS.size()]

VP convexHull(VP ps) {
  int n = ps.size(), k = 0;
  sort(ps.begin(), ps.end());
  VP ch(2*n);
  for (int i = 0; i < n; ch[k++] = ps[i++]) // lower-hull
    while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]) // upper-hull
    while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) --k;
  ch.resize(k-1);
  return ch;
}

double area(const VP& ps) {
  double a = 0;
  rep (i, ps.size()) a += cross(ps[i], ps[(i+1) % ps.size()]);
  return a / 2;
}

const double pi = acos(-1);

using vd = vector<double>;
using mat = vector<vd>;

vd Rx(const vd &p, double t){
    mat R({{1,0,0},{0,cos(t),-sin(t)},{0,sin(t),cos(t)}});
    vd ret(3,0);

    rep(i,3)rep(j,3) ret[i] += R[i][j]*p[j];
    return ret;
}

vd Rz(const vd &p, double t){
    mat R({{cos(t),-sin(t),0},{sin(t),cos(t),0},{0,0,1}});
    vd ret(3,0);

    rep(i,3)rep(j,3) ret[i] += R[i][j]*p[j];
    return ret;
}

void solve(){
    double a;
    cin >>a;

    vector<vd> cube;
    for(double y:{0.5,-0.5}){
        for(double x:{0.5,-0.5}){
            for(double z:{0.5,-0.5}){
                cube.pb({x,y,z});
            }
        }
    }

    if(a<=1.414213){
        double l=0, r=pi/4;
        rep(loop,50){
            double m = (l+r)/2;
            vector<vd> c(cube);
            rep(i,8) c[i] = Rx(c[i], m);

            VP p(8);
            rep(i,8) p[i] = {c[i][0], c[i][2]};

            if(abs(area(convexHull(p))) < a) l = m;
            else r = m;
        }

        rep(i,8) cube[i] = Rx(cube[i], r);
    }
    else{
        rep(i,8) cube[i] = Rx(cube[i], pi/4);

        // double mx=0;
        // double rad = 0;
        // for(double m = 0.6154; m<0.6155; m+=0.0000001){
        //     vector<vd> c(cube);
        //     rep(i,8) c[i] = Rz(c[i], m);

        //     VP p(8);
        //     rep(i,8) p[i] = {c[i][0], c[i][2]};

        //     double S = abs(area(convexHull(p)));
        //     if(mx < S){
        //         mx = S;
        //         rad = m;
        //     }
        // }
        // dbg(rad);

        double l=0, r=0.61548;
        rep(loop,50){
            double m = (l+r)/2;
            vector<vd> c(cube);
            rep(i,8) c[i] = Rz(c[i], m);

            VP p(8);
            rep(i,8) p[i] = {c[i][0], c[i][2]};

            if(abs(area(convexHull(p))) < a) l = m;
            else r = m;
        }

        rep(i,8) cube[i] = Rz(cube[i], r);
    }

    for(vector<int> idx: vector<vector<int>>({{0,1,2,3},{0,2,4,6},{0,1,4,5}})){
        double ans[3]={};
        for(int i:idx){
            rep(j,3) ans[j] += cube[i][j];
        }

        rep(i,3) printf("%.10f%c", ans[i]/4, " \n"[i==2]);
    }
}

int main(){
    int T;
    cin >>T;
    rep(i,T){
        printf("Case #%d:\n", i+1);
        solve();
    }
    return 0;
}
