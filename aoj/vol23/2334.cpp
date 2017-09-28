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

using pd = pair<double,int>;
const int N = 1000;
struct edge{int to; double cost;};
vector<edge> G[N];

double dijkstra()
{
    vector<double> dist(N,INF);
    dist[0] = 0;
    priority_queue<pd,vector<pd>,greater<pd>> pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        pd now = pq.top();
        pq.pop();
        int v = now.se;
        if(now.fi>dist[v]) continue;
        for(const auto &e:G[v])
        {
            if(dist[e.to] > dist[v]+e.cost)
            {
                dist[e.to] = dist[v]+e.cost;
                pq.push({dist[e.to],e.to});
            }
        }
    }

    return dist[1];
}

int main()
{
    int na,nb;
    cin >>na >>nb;

    vector<Point> a(na),b(nb);
    rep(i,na)
    {
        int x,y;
        cin >>x >>y;
        a[i] = Point(x,y);
    }
    rep(i,nb)
    {
        int x,y;
        cin >>x >>y;
        b[i] = Point(x,y);
    }

    double ans = INF;

    // a[0]とa[1]を直接つなぐ
    rep(i,nb)rep(j,i)
    {
        if(!isecSS(a[0],a[1],b[i],b[j]))
        {
            G[i].pb({j,abs(b[i]-b[j])});
            G[j].pb({i,abs(b[i]-b[j])});
        }
    }
    double d = dijkstra();
    if(d<INF) ans = min(ans, d+abs(a[0]-a[1]));

    // b[0]とb[1]を直接つなぐ
    rep(i,N) G[i].clear();
    rep(i,na)rep(j,i)
    {
        if(!isecSS(b[0],b[1],a[i],a[j]))
        {
            G[i].pb({j,abs(a[i]-a[j])});
            G[j].pb({i,abs(a[i]-a[j])});
        }
    }
    d = dijkstra();
    if(d<INF) ans = min(ans, d+abs(b[0]-b[1]));

    if(ans>1e8) printf("-1\n");
    else printf("%.15f\n",ans);
    return 0;
}
