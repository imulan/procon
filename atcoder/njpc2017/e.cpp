#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int V=100000,INF=1010101010;

struct edge
{
    int to,cost,luck;
};

vector<edge> G[V];
int d0[V],du[V],dv[V];

int rev_count;

void dfs(int now, int par, int d[])
{
    rep(i,G[now].size())
    {
        edge e=G[now][i];
        if(e.to == par) continue;

        d[e.to] = d[now]+e.cost;
        if(e.luck==1) ++rev_count;

        dfs(e.to,now,d);
    }
}

// 0からiへ移動するパス上の縁起の悪い方向の増減
int path[V];
void dfs2(int now, int par)
{
    rep(i,G[now].size())
    {
        edge e=G[now][i];
        if(e.to == par) continue;

        path[e.to] = path[now]+e.luck;
        dfs2(e.to,now);
    }
}

int main()
{
    int N,D;
    scanf(" %d %d", &N, &D);
    rep(i,N-1)
    {
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        --a;
        --b;
        G[a].pb(edge{b,c,1});
        G[b].pb(edge{a,c,-1});
    }

    int u=-1,v=-1;

    // 0からの距離
    d0[0]=0;
    dfs(0,0,d0);

    // 0から最も遠い点u
    int maxd=0;
    rep(i,N)
    {
        if(maxd<d0[i])
        {
            u=i;
            maxd=d0[i];
        }
    }

    // uからの距離
    du[u]=0;
    dfs(u,u,du);

    // uから最も遠い点v
    maxd=0;
    rep(i,N)
    {
        if(maxd<du[i])
        {
            v=i;
            maxd=du[i];
        }
    }

    // vからの距離
    dv[v]=0;
    dfs(v,v,dv);

    // printf(" u v %d %d\n", u,v);
    // rep(i,N) printf(" d0[%d] %d\n", i,d0[i]);
    // rep(i,N) printf(" du[%d] %d\n", i,du[i]);
    // rep(i,N) printf(" dv[%d] %d\n", i,dv[i]);

    // 0を根とした時点での縁起の悪い方向の個数
    rev_count=0;
    dfs(0,0,d0);

    // 0からiへ行くパス上の縁起の悪い方向の増減をカウント
    path[0]=0;
    dfs2(0,0);

    int ans=INF;
    rep(i,N)if(max(du[i],dv[i])<=D) ans = min(ans, rev_count-path[i]);

    printf("%d\n", (ans==INF)?-1:ans);
    return 0;
}
