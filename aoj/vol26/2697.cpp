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

// 点pから円aへの接線の接点
VP tangentPoints(Point a, double ar, Point p) {
  VP ps;
  double sin = ar / abs(p-a);
  if (!LE(sin, 1)) return ps;  // ここでNaNも弾かれる
  double t = PI/2 - asin(min(sin, (double)1.0));
  ps.push_back(                 a + (p-a)*polar(sin, t));
  if (!EQ(sin, 1)) ps.push_back(a + (p-a)*polar(sin, -t));
  return ps;
}

int main(){
    double x,y,theta,w;
    cin >>x >>y >>theta >>w;

    Point p(x,y);
    theta = theta/360*2*PI;
    w = w/360*2*PI;

    p = p*polar(1.0,-theta);
    theta = 0;

    double alpha = acos(p.X/abs(p));
    if(p.Y<0) alpha = 2*PI - alpha;

    bool rev = (p.Y<0);

    double R = abs(p);

    auto valid = [&](double v){
        double r = v/w;
        for(Point tp:tangentPoints(Point(0,0),r,p)){
            double z = acos(tp.X/abs(tp));
            if(tp.Y<0) z = 2*PI - z;

            if(z-alpha>PI){
                if(!rev) continue;
            }
            else if(alpha-z>PI){
                if(rev) continue;
            }
            else{
                if(rev && z-alpha>0) continue;
                if(!rev && z-alpha<0) continue;
            }

            double diff = z;
            if(rev) diff = 2*PI - z;

            double limit_time = diff/w;

            double t = abs(p-tp)/v;
            if(LE(t,limit_time)) return true;
        }
        return false;
    };

    double ng=0, ok=R*w;
    rep(loop,100){
        double mid = (ng+ok)/2;
        if(valid(mid)) ok = mid;
        else ng = mid;
    }
    printf("%.10f\n", ng);
    return 0;
}
