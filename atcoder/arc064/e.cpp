#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<double,int> pi;

struct circle
{
    double x,y,r;
};

struct edge
{
    int to;
    double cost;
};

const int N=1002;
vector<edge> G[N];

const double INF=1e18;
double dist[N];

inline double dtd(double x1, double y1, double x2, double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

inline double dtc(double x, double y, circle c)
{
    double d=dtd(x,y,c.x,c.y);
    d-=c.r;

    if(d<0) return 0;
    return d;
}

inline double ctc(circle a, circle b)
{
    double d=dtd(a.x,a.y,b.x,b.y);
    d-=a.r+b.r;

    if(d<0) return 0;
    return d;
}

int main()
{
    double xs,ys,xt,yt;
    scanf(" %lf %lf %lf %lf", &xs,&ys,&xt,&yt);

    int n;
    scanf(" %d", &n);
    vector<circle> c(n);
    rep(i,n) scanf(" %lf %lf %lf", &c[i].x, &c[i].y, &c[i].r);

    G[0].pb(edge{n+1,dtd(xs,ys,xt,yt)});
    G[n+1].pb(edge{0,dtd(xs,ys,xt,yt)});

    rep(i,n)
    {
        double d=dtc(xs,ys,c[i]);
        G[0].pb(edge{i+1,d});
        G[i+1].pb(edge{0,d});
        // printf("%d,%d %f\n", 0,i+1,d);
    }
    rep(i,n)
    {
        double d=dtc(xt,yt,c[i]);
        G[n+1].pb(edge{i+1,d});
        G[i+1].pb(edge{n+1,d});
        // printf("%d,%d %f\n", n+1,i+1,d);
    }

    rep(i,n)rep(j,i)
    {
        double d=ctc(c[i],c[j]);
        G[i+1].pb(edge{j+1,d});
        G[j+1].pb(edge{i+1,d});
        // printf("%d,%d %f\n", i+1,j+1,d);
    }

    // dijkstra
    priority_queue< pi,vector<pi>,greater<pi> > que;

    fill(dist,dist+N,INF);
    dist[0]=0;
    que.push(pi(0,0));
    while(!que.empty())
    {
        pi p=que.top();
        que.pop();
        int v=p.se;
        if(dist[v]<p.fi) continue;

        rep(i,G[v].size())
        {
            edge e=G[v][i];
            if(dist[e.to]>dist[v]+e.cost)
            {
                dist[e.to]=dist[v]+e.cost;
                que.push(pi(dist[e.to],e.to));
            }
        }
    }

    printf("%.20f\n", dist[n+1]);
    return 0;
}
