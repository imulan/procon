#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<ll,int> P;
struct edge{int to; ll cost;};

const int N=100001;
const ll INF=12345678901234LL;

ll cost[N][10];
vector<edge> G[N];

int main()
{
    int n,m,r,Q;
    scanf(" %d %d %d %d", &n, &m, &r, &Q);

    while(m--)
    {
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        G[b].pb(edge{a,c});
    }

    fill(cost[0],cost[N],INF);

    rep(i,r)
    {
        priority_queue<P,vector<P>,greater<P>> pq;
        for(int j=i; j<=n; j+=r)
        {
            cost[j][i]=0;
            pq.push(P(0,j));
        }

        while(!pq.empty())
        {
            P p = pq.top();
            pq.pop();

            int v=p.se;
            if(cost[p.se][i]<p.fi) continue;
            for(edge &e:G[v])
            {
                if(cost[e.to][i] > cost[v][i]+e.cost)
                {
                    cost[e.to][i] = cost[v][i]+e.cost;
                    pq.push(P(cost[e.to][i], e.to));
                }
            }

        }
    }

    ll ans=0;
    while(Q--)
    {
        int x,y,z;
        scanf(" %d %d %d", &x, &y, &z);

        ll mincost=INF;
        rep(i,r) mincost = min(mincost, cost[x][i]+cost[y][i]);

        if(z>mincost) ans+=z-mincost;
    }

    printf("%lld\n", ans);
    return 0;
}
