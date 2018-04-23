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
    int n;
    while(scanf(" %d", &n),n){
        vector<Point> p(n);
        vector<int> l(n);
        rep(i,n){
            int x,y;
            scanf(" %d %d %d", &x, &y, &l[i]);
            p[i] = Point(x,y);
        }

        if(n==1){
            printf("%d\n", l[0]);
            continue;
        }

        int min_l = 300;
        rep(i,n) min_l = min(min_l, l[i]);

        auto check = [&](double h){
            vector<double> r(n);
            rep(i,n) r[i] = sqrt(l[i]*l[i] - h*h);

            VP candidate;
            rep(i,n) candidate.pb(p[i]);
            rep(i,n)rep(j,i){
                for(Point c:crosspointCC(p[i],r[i],p[j],r[j])) candidate.pb(c);
            }

            for(Point c:candidate){
                bool ok = true;
                rep(i,n){
                    double d = abs(p[i]-c);
                    ok &= (LE(d,r[i]));
                }
                if(ok) return true;
            }
            return false;
        };

        double L=0, R=min_l;
        rep(loop,50){
            double m = (L+R)/2;
            if(check(m)) L=m;
            else R=m;
        }

        printf("%.10f\n", L);
    }
    return 0;
}
