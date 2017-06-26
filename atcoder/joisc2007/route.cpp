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

using pi = pair<int,int>;
using P = pair<int,pi>;

struct Point{ int x,y; };
struct edge{ int to,cost; };

const int V=100;
const int INF=123456789;
vector<edge> G[V];
int d[V][V];

bool ok(Point p, Point q, Point r)
{
    int px = p.x-q.x, py = p.y-q.y;
    int rx = r.x-q.x, ry = r.y-q.y;
    return (px*rx+py*ry)<=0;
}

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<Point> p(n);
    rep(i,n) scanf(" %d %d", &p[i].x, &p[i].y);

    rep(i,m)
    {
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        --a;
        --b;
        G[a].pb({b,c});
        G[b].pb({a,c});
    }

    fill(d[0],d[V],INF);
    priority_queue<P,vector<P>,greater<P>> pq;
    for(const auto &e:G[0])
    {
        d[e.to][0] = e.cost;
        pq.push(P(d[e.to][0],pi(e.to,0)));
    }
    while(!pq.empty())
    {
        P now = pq.top();
        pq.pop();

        int v = now.se.fi, u = now.se.se;
        if(now.fi>d[v][u]) continue;

        for(const auto &e:G[v])
        {
            if(ok(p[u],p[v],p[e.to]) && d[e.to][v]>d[v][u]+e.cost)
            {
                d[e.to][v] = d[v][u]+e.cost;
                pq.push(P(d[e.to][v],pi(e.to,v)));
            }
        }
    }

    int ans = INF;
    rep(i,n) ans = min(ans,d[1][i]);
    if(ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}
