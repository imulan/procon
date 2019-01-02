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



Point READ(){
    double x,y;
    cin >>x >>y;
    return {x,y};
}

int main(){
    int n;
    while(cin >>n,n){
        VP p(n);
        vector<double> v(n);
        rep(i,n){
            p[i] = READ();
            cin >>v[i];
        }

        auto check = [&](double t){
            vector<double> r(n);
            rep(i,n) r[i] = v[i]*t;

            VP cand;
            rep(i,n)rep(j,i){
                double d = abs(p[i]-p[j]);
                if( d+EPS > r[i]+r[j]) return false;

                for(Point cp:crosspointCC(p[i],r[i],p[j],r[j])) cand.pb(cp);
            }
            rep(i,n) cand.pb(p[i]);

            for(Point c:cand){
                bool ok = true;
                rep(i,n){
                    double tt = abs(c-p[i])/v[i];
                    if(tt > t+EPS){
                        ok = false;
                        break;
                    }
                }
                if(ok) return true;
            }
            return false;
        };

        double ng=0, ok=100;
        rep(loop,40){
            double mid = (ng+ok)/2;
            if(check(mid)) ok = mid;
            else ng = mid;
        }
        printf("%.10f\n", ok);
    }
    return 0;
}
