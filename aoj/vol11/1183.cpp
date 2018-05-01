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

// 線分と線分
bool isecSS(Point a1, Point a2, Point b1, Point b2) {
  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&
  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;
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

struct edge{
    int to;
    double cost;
};

const int N = 200;
vector<edge> G[N];

int main(){
    int n;
    while(scanf(" %d", &n),n){
        rep(i,N) G[i].clear();

        vector<Point> p(n);
        vector<int> r(n);
        rep(i,n){
            int x,y;
            scanf(" %d %d %d", &x, &y, &r[i]);
            p[i] = Point(x,y);
        }

        vector<VP> c(n-1);
        rep(i,n-1) c[i] = crosspointCC(p[i],r[i],p[i+1],r[i+1]);

        int S = 2*n-2, T = S+1;

        bool direct = true;
        rep(i,n-1){
            direct &= isecSS(p[0],p[n-1],c[i][0],c[i][1]);
        }
        if(direct){
            G[S].pb({T,abs(p[0]-p[n-1])});
            G[T].pb({S,abs(p[0]-p[n-1])});
        }

        rep(i,n-1)rep(j,2){
            bool ok = true;
            rep(k,i) ok &= isecSS(p[0],c[i][j],c[k][0],c[k][1]);
            if(ok){
                G[S].pb({2*i+j, abs(p[0]-c[i][j])});
                G[2*i+j].pb({S, abs(p[0]-c[i][j])});
            }
        }

        rep(i,n-1)rep(j,2){
            bool ok = true;
            for(int k=n-2; k>i; --k) ok &= isecSS(p[n-1],c[i][j],c[k][0],c[k][1]);
            if(ok){
                G[T].pb({2*i+j, abs(p[n-1]-c[i][j])});
                G[2*i+j].pb({T, abs(p[n-1]-c[i][j])});
            }
        }

        rep(i,n-1)rep(j,2)for(int k=i+1; k<n-1; ++k)rep(l,2){
            bool ok = true;
            for(int a=i+1; a<k; ++a) ok &= isecSS(c[i][j],c[k][l],c[a][0],c[a][1]);
            if(ok){
                G[2*i+j].pb({2*k+l, abs(c[i][j]-c[k][l])});
                G[2*k+l].pb({2*i+j, abs(c[i][j]-c[k][l])});
            }
        }

        vector<double> d(2*n,INF);
        d[S] = 0;

        using P = pair<double,int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,S});
        while(!pq.empty()){
            P now = pq.top();
            pq.pop();
            int v = now.se;
            if(now.fi > d[v]) continue;
            for(const auto &e:G[v]){
                if(d[e.to] > d[v]+e.cost){
                    d[e.to] = d[v]+e.cost;
                    pq.push({d[e.to],e.to});
                }
            }
        }
        printf("%.10f\n", d[T]);
    }
    return 0;
}
