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


VP READ(){
    int n;
    scanf(" %d", &n);

    VP ret;
    rep(i,n){
        int x,y;
        scanf(" %d %d", &x, &y);
        ret.pb(Point(x,y));
    }
    return ret;
}

using pd = pair<double,int>;

int main(){
    VP a = READ(), b = READ();
    int A = a.size(), B = b.size();

    vector<double> da(A), db(B);
    vector<pd> r;
    for(int i=1; i<A; ++i){
        da[i] = da[i-1] + abs(a[i]-a[i-1]);
        r.pb({da[i],0});
    }
    for(int i=1; i<B; ++i){
        db[i] = db[i-1] + abs(b[i]-b[i-1]);
        r.pb({db[i],1});
    }
    sort(all(r));

    int ai = 0, bi = 0;
    double ans = INF;
    double pre = 0;

    auto f = [&](double t){
        double at = t - da[ai], bt = t - db[bi];

        Point va = a[ai+1]-a[ai], vb = b[bi+1]-b[bi];
        double sz = abs(va);
        va = Point(va.X/sz, va.Y/sz);
        sz = abs(vb);
        vb = Point(vb.X/sz, vb.Y/sz);

        Point now_a = a[ai] + at*va, now_b = b[bi] + bt*vb;
        return abs(now_a - now_b);
    };

    for(pd pp:r){
        if(ai==A-1 || bi==B-1) break;
        // dbg(pp);

        double nt = pp.fi;
        double L=pre, R=nt;
        rep(loop,60){
            double m1 = (2*L+R)/3, m2 = (L+2*R)/3;
            if(f(m1) > f(m2)) L = m1;
            else R = m2;
        }

        ans = min(ans, f(L));

        if(pp.se == 0) ++ai;
        else ++bi;
        pre = nt;
    }

    printf("%.10Lf\n", ans);
    return 0;
}
