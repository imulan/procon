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
vector<edge> G[1000];

const int INF=123456789;

int dist[13][1000];
int D=0;

void dijkstra(int start)
{
    int *d = dist[D];
    fill(d,d+1000,INF);

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

    ++D;
}

int k,p;
int s[6],t[6];

int dp[64][64][13];
int dfs(int S, int T, int now)
{
    if(dp[S][T][now]>=0) return dp[S][T][now];

    int M=(1<<k)-1;
    if(S==M && T==M) return 0;

    int ret=INF;

    rep(i,k)
    {
        if(!(S>>i&1)) ret = min(ret, dfs(S|(1<<i), T, i+1)+dist[now][s[i]]);
    }
    rep(i,k)
    {
        if((S>>i&1) && !(T>>i&1)) ret = min(ret, dfs(S, T|(1<<i), 1+k+i)+dist[now][t[i]]);
    }

    return dp[S][T][now]=ret;
}

int main()
{
    int n,m;
    scanf(" %d %d %d %d", &n, &m ,&k, &p);
    --p;

    rep(i,m)
    {
        int x,y,w;
        scanf(" %d %d %d", &x, &y, &w);
        --x;
        --y;
        G[x].pb(edge{y,w});
        G[y].pb(edge{x,w});
    }

    rep(i,k)
    {
        scanf(" %d %d", &s[i], &t[i]);
        --s[i];
        --t[i];
    }

    // 0:p, 1~k: s[0]~s[k-1], k+1~2k: t[0]~t[k-1]
    dijkstra(p);
    rep(i,k) dijkstra(s[i]);
    rep(i,k) dijkstra(t[i]);

    memset(dp,-1,sizeof(dp));
    int ans = dfs(0,0,0);

    if(ans==INF) printf("Cannot deliver\n");
    else printf("%d\n", ans);

    return 0;
}
