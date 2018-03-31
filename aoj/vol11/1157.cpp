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

Point read_p(){
    int x,y;
    cin >>x >>y;
    return Point(x,y);
}

int main(){
    int n;
    while(cin >>n,n){
        Point s = read_p();
        Point g = read_p();

        VP mn(n), mx(n);
        vector<int> h(n);
        rep(i,n){
            mn[i] = read_p();
            mx[i] = read_p();
            cin >>h[i];
        }

        auto IN = [&](Point p){
            rep(i,n){
                if(mn[i].X<=p.X && p.X<=mx[i].X && mn[i].Y<=p.Y && p.Y<=mx[i].Y) return true;
            }
            return false;
        };

        if(IN(s) || IN(g)){
            printf("0\n");
            continue;
        }

        auto check = [&](double R){
            rep(i,n){
                VP v;
                v.pb(mn[i]);
                v.pb({mn[i].X, mx[i].Y});
                v.pb(mx[i]);
                v.pb({mx[i].X, mn[i].Y});

                double dist = 19191919;
                rep(j,4){
                    Point p = v[j], q = v[(j+1)%4];
                    dist = min(dist, distSS(s,g,p,q));
                }

                double x = R*R;
                if(R>h[i]) x -= (R-h[i])*(R-h[i]);
                x = sqrt(x);

                if(dist<x) return false;
            }
            return true;
        };

        double l=0, r=1000;
        rep(loop,50){
            double mid = (l+r)/2;
            if(check(mid)) l=mid;
            else r=mid;
        }
        printf("%.10f\n",l);
    }
    return 0;
}
