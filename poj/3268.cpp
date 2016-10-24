#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

const int N=1000;
const int INF=123456789;

struct edge{int to,cost;};
vector<edge> G[N], invG[N];

int come[N], back[N];

int main()
{
    int n,m,x;
    scanf(" %d %d %d", &n, &m, &x);
    --x;

    rep(i,m)
    {
        int a,b,t;
        scanf(" %d %d %d", &a, &b, &t);
        --a;
        --b;
        G[a].pb(edge{b,t});
        invG[b].pb(edge{a,t});
    }

    // dijkstra
    priority_queue< pi,vector<pi>,greater<pi> > que;

    fill(come,come+N,INF);
    come[x]=0;
    que.push(pi(0,x));
    while(!que.empty())
    {
        pi p=que.top();
        que.pop();
        int v=p.se;
        if(come[v]<p.fi) continue;
        rep(i,invG[v].size())
        {
            edge e=invG[v][i];
            if(come[e.to]>come[v]+e.cost)
            {
                come[e.to]=come[v]+e.cost;
                que.push(pi(come[e.to],e.to));
            }
        }
    }

    fill(back,back+N,INF);
    back[x]=0;
    que.push(pi(0,x));
    while(!que.empty())
    {
        pi p=que.top();
        que.pop();
        int v=p.se;
        if(back[v]<p.fi) continue;
        rep(i,G[v].size())
        {
            edge e=G[v][i];
            if(back[e.to]>back[v]+e.cost)
            {
                back[e.to]=back[v]+e.cost;
                que.push(pi(back[e.to],e.to));
            }
        }
    }

    int ans=0;
    rep(i,n) ans=max(ans,come[i]+back[i]);
    printf("%d\n", ans);
    return 0;
}
