#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
struct edge{ int to,cost; };

const int N=300, INF=123456789;
vector<edge> G[N];

int dp[16][1<<16];
int dist[16][16];

int d[N];
void dijkstra(int start)
{
    fill(d,d+N,INF);

    priority_queue<pi,vector<pi>,greater<pi>> que;
    d[start]=0;
    que.push(pi(0,start));
    while(!que.empty()){
        pi p=que.top();
        que.pop();
        int v=p.se;
        if(d[v]<p.fi) continue;
        rep(i,G[v].size())
        {
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(pi(d[e.to],e.to));
            }
        }
    }
}

int main()
{
    int n,m,l,s,t;
    while(scanf(" %d %d %d %d %d", &n, &m, &l, &s, &t),n)
    {
        --s;
        rep(i,N) G[i].clear();

        rep(i,m)
        {
            int a,b,c;
            scanf(" %d %d %d", &a, &b, &c);
            --a;
            --b;
            G[a].pb(edge{b,c});
            G[b].pb(edge{a,c});
        }

        vector<int> J(l), E(l);
        rep(i,l)
        {
            scanf(" %d %d", &J[i], &E[i]);
            --J[i];
        }

        fill(dp[0],dp[16],INF);

        // スタート地点から
        dijkstra(s);
        rep(i,l) dp[i][1<<i] = d[J[i]] + E[i];

        rep(i,l)
        {
            dijkstra(J[i]);
            rep(j,l) dist[i][j] = d[J[j]];
        }

        for(int mask=1; mask<(1<<l); ++mask)rep(last,l)
        {
            if(!(mask>>last&1)) continue;

            rep(nx,l)if(!(mask>>nx&1))
            {
                int nmask = mask|(1<<nx);
                dp[nx][nmask] = min(dp[nx][nmask], dp[last][mask] + dist[last][nx] + E[nx]);
            }
        }

        int ans=0;

        dijkstra(s);
        rep(mask,1<<l)
        {
            rep(i,l)
            {
                if(dp[i][mask] + d[J[i]] <= t) ans=max(ans,__builtin_popcount(mask));
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
