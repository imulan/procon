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

const int N=1000, M=10000;
const ll INF=123456789012345LL;

int U[M], V[M], W[M];

struct edge{int to,cost;};
vector<edge> G1[N], G2[N];
ll d1[N], d2[N];
int par[N];

// 0:存在しない, -1:未定辺, -2:最短経路に含まれる未定辺
ll ans[N][N]={0};

int main()
{
    int n,m,L,s,t;
    scanf(" %d %d %d %d %d", &n, &m, &L, &s, &t);

    rep(i,m)
    {
        int u,v,w;
        scanf(" %d %d %d", &u, &v, &w);
        if(w==0)
        {
            G2[u].pb(edge{v,1});
            G2[v].pb(edge{u,1});
            ans[u][v]=ans[v][u]=-1;
        }
        else
        {
            G1[u].pb(edge{v,w});
            G1[v].pb(edge{u,w});
            G2[u].pb(edge{v,w});
            G2[v].pb(edge{u,w});

            ans[u][v]=ans[v][u]=w;
        }

        U[i]=u;
        V[i]=v;
        W[i]=w;
    }

    priority_queue<pi,vector<pi>,greater<pi>> que;

    // 未定辺を含まないグラフでの最短経路
    // dijkstra
    fill(d1,d1+N,INF);
    d1[s]=0;
    que.push(pi(0,s));
    while(!que.empty())
    {
        pi p=que.top();
        que.pop();
        int v=p.se;
        if(d1[v]<p.fi) continue;
        rep(i,G1[v].size())
        {
            edge e=G1[v][i];
            if(d1[e.to]>d1[v]+e.cost)
            {
                d1[e.to]=d1[v]+e.cost;
                que.push(pi(d1[e.to],e.to));
            }
        }
    }

    if(d1[t]<L)
    {
        printf("NO\n");
        return 0;
    }
    if(d1[t]==L)
    {
        printf("YES\n");
        rep(i,m)
        {
            int u=U[i], v=V[i];
            ll d=ans[u][v];
            if(d<0) d=INF;
            printf("%d %d %lld\n", u, v, d);
        }
        return 0;
    }

    // 未定辺の重みを全て1にしたグラフでの最短経路
    // dijkstra
    fill(d2,d2+N,INF);
    d2[s]=0;
    que.push(pi(0,s));
    memset(par,-1,sizeof(par));
    while(!que.empty())
    {
        pi p=que.top();
        que.pop();
        int v=p.se;
        if(d2[v]<p.fi) continue;
        rep(i,G2[v].size())
        {
            edge e=G2[v][i];
            if(d2[e.to]>d2[v]+e.cost)
            {
                d2[e.to]=d2[v]+e.cost;
                que.push(pi(d2[e.to],e.to));
                // 経路復元のために親を記録
                par[e.to]=v;
            }
        }
    }

    if(d2[t]>L)
    {
        printf("NO\n");
        return 0;
    }

    int now=t;
    while(now!=s)
    {
        int nx=par[now];
        if(ans[now][nx]==-1) ans[now][nx]=ans[nx][now]=-2;
        now=nx;
    }
    // 最短経路に関係ない未定辺を全てINFに設定
    rep(i,N)rep(j,N)
    {
        if(ans[i][j]==-1) ans[i][j]=INF;
    }
    // もどしておく
    rep(i,N)rep(j,N)
    {
        if(ans[i][j]==-2) ans[i][j]=-1;
    }

    // 最短経路がLに一致するまでやる
    while(1)
    {
        // dijkstra
        fill(d2,d2+N,INF);
        d2[s]=0;
        que.push(pi(0,s));
        memset(par,-1,sizeof(par));
        while(!que.empty())
        {
            pi p=que.top();
            que.pop();
            int v=p.se;
            if(d2[v]<p.fi) continue;
            rep(i,G2[v].size())
            {
                edge e=G2[v][i];
                int cost=ans[v][e.to];
                if(d2[e.to]>d2[v]+abs(cost))
                {
                    d2[e.to]=d2[v]+abs(cost);
                    que.push(pi(d2[e.to],e.to));
                    // 経路復元のために親を記録
                    par[e.to]=v;
                }
            }
        }

        if(d2[t]==L) break;

        now=t;
        while(now!=s)
        {
            int nx=par[now];

            // 未定辺
            if(ans[now][nx]<0)
            {
                ll dist=abs(ans[now][nx]);
                ans[now][nx]=ans[nx][now]=dist+(L-d2[t]);
                break;
            }

            now=nx;
        }
    }


    printf("YES\n");
    rep(i,m)
    {
        int u=U[i], v=V[i];
        ll d=abs(ans[u][v]);
        printf("%d %d %lld\n", u, v, d);
    }
    return 0;
}
