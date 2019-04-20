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

using pi = pair<int,int>;

inline int dist(pi p, pi q){
    return abs(p.fi-q.fi) + abs(p.se-q.se);
}

void solve(){
    int n;
    scanf(" %d", &n);

    vector<int> x(n),y(n),d(n);
    rep(i,n) scanf(" %d %d %d", &x[i], &y[i], &d[i]);

    map<int,pi> p,m;
    rep(i,n){
        int b = y[i]-x[i];
        for(int j:{-1,1}){
            int bb = b+j*d[i];

            int lx = x[i], rx = x[i]+d[i];
            if(j==1){
                lx -= d[i];
                rx -= d[i];
            }

            if(!p.count(bb)) p[bb] = {lx,rx};
            else{
                int nl = max(p[bb].fi, lx);
                int nr = min(p[bb].se, rx);
                p[bb] = {nl,nr};
            }
        }

        b = x[i]+y[i];
        for(int j:{-1,1}){
            int bb = b+j*d[i];

            int lx = x[i], rx = x[i]+d[i];
            if(j==-1){
                lx -= d[i];
                rx -= d[i];
            }

            if(!m.count(bb)) m[bb] = {lx,rx};
            else{
                int nl = max(m[bb].fi, lx);
                int nr = min(m[bb].se, rx);
                m[bb] = {nl,nr};
            }
        }
    }

    vector<pi> cand;
    for(const auto &t:p){
        int b = t.fi;
        pi tmp = t.se;
        if(tmp.fi<=tmp.se){
            cand.pb({tmp.fi, tmp.fi+b});
            if(tmp.fi<tmp.se) cand.pb({tmp.se, tmp.se+b});
        }
    }
    for(const auto &t:m){
        int b = t.fi;
        pi tmp = t.se;
        if(tmp.fi<=tmp.se){
            cand.pb({tmp.fi, -tmp.fi+b});
            if(tmp.fi<tmp.se) cand.pb({tmp.se, -tmp.se+b});
        }
    }

    for(const auto &t:p){
        int b = t.fi;
        pi tmp = t.se;
        if(tmp.fi>tmp.se) continue;
        Point pp1(tmp.fi, tmp.fi+b), pp2(tmp.se, tmp.se+b);

        for(const auto &tt:m){
            int bb = tt.fi;
            pi tmpp = tt.se;
            if(tmpp.fi>tmpp.se) continue;
            Point qq1(tmpp.fi, -tmpp.fi+bb), qq2(tmpp.se, -tmpp.se+bb);

            if(isecSS(pp1,pp2,qq1,qq2)){
                Point cp = crosspointLL(pp1,pp2,qq1,qq2);
                cand.pb({(int)cp.X, (int)cp.Y});
            }
        }
    }
    sort(all(cand));
    cand.erase(unique(all(cand)), cand.end());

    int sz = cand.size();
    int ct = 0;
    pi ans;
    rep(i,sz){
        // dbg(cand[i]);

        bool ok = true;
        rep(j,n){
            int dd = dist({x[j],y[j]}, cand[i]);
            if(dd != d[j]){
                ok = false;
                break;
            }
        }

        if(ok){
            ++ct;
            if(ct>1){
                printf("uncertain\n");
                return;
            }
            ans = cand[i];
        }
    }

    if(ct==0) printf("impossible\n");
    else printf("%d %d\n", ans.fi, ans.se);
}

int main(){
    solve();
    return 0;
}
