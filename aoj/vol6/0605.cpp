#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using P = pair<ll,int>;

const int V=400004;
const ll INF=LLONG_MAX/3;

struct Point{int x,y,id;};
bool cmp1(const Point &l, const Point &r)
{
    return l.x==r.x ? l.y<r.y : l.x<r.x;
}
bool cmp2(const Point &l, const Point &r)
{
    return l.y==r.y ? l.x<r.x : l.y<r.y;
}

struct edge{int to; ll cost;};
vector<edge> G[V];
ll d[V];

int main()
{
    int m,n,k;
    scanf(" %d %d %d", &m, &n, &k);

    vector<Point> p(k);
    rep(i,k) scanf(" %d %d", &p[i].x, &p[i].y);

    // sort by x,y
    sort(all(p),cmp1);

    rep(i,k) p[i].id=i;

    // put switch to goal if there is not
    if(!(p[k-1].x==m && p[k-1].y==n))
    {
        p.pb({m,n,k});
        ++k;
    }

    // connect y-direction
    rep(i,k-1)
    {
        if(p[i].x==p[i+1].x)
        {
            int dist = p[i+1].y-p[i].y;
            int u = 2*p[i].id, v = 2*p[i+1].id;
            G[u].pb({v,dist});
            G[v].pb({u,dist});
        }
    }

    // connect start and p[0]
    int start = 2*k;
    if(p[0].x==1)
    {
        int u = 2*p[0].id;
        G[start].pb({u,p[0].y-1});
        G[u].pb({start,p[0].y-1});
    }

    // sort by y,x
    sort(all(p),cmp2);

    // connect x-direction
    rep(i,k-1)
    {
        if(p[i].y==p[i+1].y)
        {
            int dist = p[i+1].x-p[i].x;
            int u = 2*p[i].id+1, v = 2*p[i+1].id+1;
            G[u].pb({v,dist});
            G[v].pb({u,dist});
        }
    }

    // change direction
    rep(i,k)
    {
        int u = 2*i, v = 2*i+1;
        G[u].pb({v,1});
        G[v].pb({u,1});
    }

    // dijkstra
    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push(P(0,start));
    fill(d,d+V,INF);
    d[start] = 0;
    while(!pq.empty())
    {
        P now = pq.top();
        pq.pop();
        int v = now.se;
        if(now.fi>d[v]) continue;
        for(const auto &e:G[v])
        {
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to] = d[v]+e.cost;
                pq.push(P(d[e.to],e.to));
            }
        }
    }

    ll ans = min(d[2*k-2],d[2*k-1]);
    if(ans == INF) ans = -1;
    printf("%lld\n", ans);
    return 0;
}
