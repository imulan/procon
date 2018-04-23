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

// 点pの直線aへの射影点を返す
Point proj(Point a1, Point a2, Point p) {
  return a1 + dot(a2-a1, p-a1)/norm(a2-a1) * (a2-a1);
}

VP crosspointLC(Point a1, Point a2, Point c, double r) {
  VP ps;
  Point ft = proj(a1, a2, c);
  if(!GE(r*r,norm(ft-c))) return ps;
  Point dir = sqrt(max(r*r - norm(ft-c), 0.0)) / abs(a2-a1) * (a2-a1);
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
  if (EQ(d, 0) || ar < abs(crL)) return ps;

  Point abN = ab * Point(0, sqrt(ar*ar - crL*crL) / d);
  Point cp = a + crL/d * ab;
  ps.push_back(cp + abN);
  if (!EQ(norm(abN), 0)) ps.push_back(cp - abN);
  return ps;
}

int main(){
    int n,w;
    while(scanf(" %d %d", &n, &w), n){
        vector<int> x(n), y(n), h(n);
        vector<Point> c(n);
        rep(i,n){
            scanf(" %d %d %d", &x[i], &y[i], &h[i]);
            c[i] = Point(x[i],y[i]);
        }

        auto check = [&](double R){
            double lx,rx,ly,ry;
            if(R<w){
                double d = R;
                lx = d;
                rx = 100.0-d;
                ly = d;
                ry = 100.0-d;
            }
            else{
                double d = sqrt(R*R - (R-w)*(R-w));
                lx = d;
                rx = 100.0-d;
                ly = d;
                ry = 100.0-d;
            }
            if(lx>rx) return false;

            vector<double> xx(n);
            rep(i,n){
                if(R<h[i]) xx[i] = R;
                else xx[i] = sqrt(R*R - (R-h[i])*(R-h[i]));
            }

            VP corner;
            corner.pb({lx,ly});
            corner.pb({rx,ly});
            corner.pb({rx,ry});
            corner.pb({lx,ry});

            VP candidate;
            rep(i,4) candidate.pb(corner[i]);
            rep(i,n)rep(j,4){
                for(Point p:crosspointLC(corner[j], corner[(j+1)%4], c[i], xx[i])) candidate.pb(p);
            }
            rep(i,n)rep(j,i){
                for(Point p:crosspointCC(c[i],xx[i],c[j],xx[j])) candidate.pb(p);
            }

            for(Point p:candidate){
                // distance to wall
                if(p.X<lx || rx<p.X || p.Y<ly || ry<p.Y) continue;

                bool ok = true;
                // distance to needle
                rep(i,n){
                    double dist = abs(p-c[i]);
                    ok &= GE(dist,xx[i]);
                }
                if(ok) return true;
            }
            return false;
        };

        double l = 0, r = 1500;
        rep(loop,80){
            double m = (l+r)/2;
            if(check(m)) l = m;
            else r = m;
        }
        printf("%.10f\n", l);
    }
    return 0;
}
