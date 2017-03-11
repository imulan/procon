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

const int N=200000;
const int LOG_N=18;

struct edge{int to,cost;};

int n;
int a[N];

int par[LOG_N][N];

ll d[N]={};
vector<edge> G[N];
int depth[N]={};
void dfs(int now, int parent)
{
    rep(i,G[now].size())
    {
        edge e = G[now][i];
        if(parent != e.to)
        {
            d[e.to] = d[now]+e.cost;
            depth[e.to] = depth[now]+1;
            dfs(e.to,now);
        }
    }
}

int ans[N]={};

int main()
{
    memset(par,-1,sizeof(par));

    scanf(" %d", &n);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,n-1)
    {
        int p,w;
        scanf(" %d %d", &p, &w);
        --p;

        G[i+1].pb(edge{p,w});
        G[p].pb(edge{i+1,w});

        par[0][i+1] = p;
    }

    // 根からの距離を計算
    dfs(0,0);

    // ダブリング
    for(int i=1; i<LOG_N; ++i)rep(j,n)
    {
        if(par[i-1][j]!=-1) par[i][j]=par[i-1][par[i-1][j]];
    }

    // 各頂点について、二分探索で条件を満たす境界を探す
    for(int i=1; i<n; ++i)
    {
        int l=0,r=n;
        while(r-l>1)
        {
            int m=(l+r)/2;

            int t=m;
            int now=i;
            for(int j=LOG_N-1; j>=0; --j)
            {
                int sz = 1<<j;
                if(t-sz>=0)
                {
                    if(now!=-1) now = par[j][now];
                    t -= sz;
                }
            }

            bool ok=false;
            if(now!=-1) ok=(d[i]-a[i] <= d[now]);

            if(ok) l=m;
            else r=m;
        }

        // printf(" i = %d , l= %d\n", i,l);

        int t=l;
        int now=i;
        for(int j=LOG_N-1; j>=0; --j)
        {
            int sz = 1<<j;
            if(t-sz>=0)
            {
                if(now!=-1) now = par[j][now];
                // printf("now = %d\n", now);
                t -= sz;
            }
        }

        if(now!=i)
        {
            ++ans[par[0][i]];
            if(par[0][now]!=-1) --ans[par[0][now]];

            // printf(" %d -> %d\n", par[0][i], par[0][now]);
        }
    }

    // 子から順に足し上げる
    vector<pi> v(n);
    rep(i,n) v[i]=pi(-depth[i],i);
    sort(all(v));

    rep(i,n-1)
    {
        int now = v[i].se;
        ans[par[0][now]] += ans[now];
    }

    // output
    rep(i,n)
    {
        if(i) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
