#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;
struct edge{int to; ll cost;};

const int V=100000;

int n,k;

vector<edge> G[V];

edge par[V];
vector<edge> ch[V];
int d[V];

ll cost[V]={};

ll dp[V];
ll dfs(int x)
{
    if(dp[x]>=0) return dp[x];

    ll ret=0;

    priority_queue<pi> PQ;
    map<int,ll> COST;
    for(const auto &e:ch[x])
    {
        COST[e.to]=cost[e.to]+e.cost;
        PQ.push(pi(COST[e.to],e.to));
    }

    int lastnum=-1;
    ll sum=0;
    set<int> S;
    int ct=0;
    while(ct<k && !PQ.empty())
    {
        ++ct;

        pi val = PQ.top();
        PQ.pop();

        sum += val.fi;
        S.insert(val.se);
        if(ct==k) lastnum = val.se;
    }

    // printf(" x(%d), S=\n", x);
    // for(const auto &X:S) printf(" %d", X);
    // printf("\n");

    // k回行く方向を決める
    for(const auto &e:ch[x])
    {
        ll add=sum;
        if(S.count(e.to)) add -= COST[e.to];
        else
        {
            if(lastnum!=-1)
            {
                add -= COST[lastnum];
                // add += COST[e.to];
            }
        }

        // printf("  x %d, nx %d  add %lld (sum %lld)\n", x,e.to,add,sum);
        ret = max(ret, dfs(e.to)+e.cost+add);
    }

    // printf("x %d  -> %lld\n", x,ret);
    return dp[x]=ret;
}

int main()
{
    scanf(" %d %d", &n, &k);
    // scanf(" %d", &n); k=1;

    rep(i,n-1)
    {
        int u,v,c;
        scanf(" %d %d %d", &u, &v, &c);
        G[u].pb({v,c});
        G[v].pb({u,c});
    }

    vector<bool> vis(n,false);
    queue<int> que;
    que.push(0);
    fill(d,d+V,INT_MAX/3);
    d[0] = 0;
    vis[0]=true;
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        for(const auto &e:G[v])
        {
            if(vis[e.to]) continue;

            vis[e.to] = true;
            que.push(e.to);

            par[e.to] = (edge){v,e.cost};
            ch[v].pb(e);
            d[e.to] = d[v]+1;
        }
    }

    vector<pi> TP(n);
    rep(i,n) TP[i]=pi(-d[i],i);
    sort(all(TP));

    rep(i,n)
    {
        int v = TP[i].se;

        priority_queue<int> pq;
        for(const auto &e:ch[v])
        {
            pq.push(cost[e.to]+e.cost);
        }

        int ct=0;
        while(ct<k-1 && !pq.empty())
        {
            int val = pq.top();
            pq.pop();
            cost[v] += val;
            ++ct;
        }

    }

    memset(dp,-1,sizeof(dp));
    printf("%lld\n", dfs(0));
    return 0;
}
