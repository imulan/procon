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
typedef pair<ll,int> P;

const int V=100000;
const ll INF=123456789012345LL;

struct edge{int to,cost;};
vector<edge> G[V];
ll d[V];

int r[V];

int main()
{
    int n,m;
    ll C;
    scanf(" %d %d %lld", &n, &m, &C);

    vector<int> a(m),b(m),c(m);
    rep(i,m)
    {
        scanf(" %d %d %d", &a[i], &b[i], &c[i]);
        --a[i];
        --b[i];
        G[a[i]].pb(edge{b[i],c[i]});
        G[b[i]].pb(edge{a[i],c[i]});
    }

    fill(d,d+V,INF);
    priority_queue<pi,vector<pi>,greater<pi>> que;
    d[0]=0;
    que.push(pi(0,0));
    while(!que.empty())
    {
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

    ll ans=0;
    // 全て残す場合
    rep(i,m) ans+=c[i];
    ll sum=ans;

    vector<P> p;
    for(int i=1; i<n; ++i) p.pb(P(d[i],i));
    sort(all(p));

    r[0]=-1;
    rep(i,p.size()) r[p[i].se]=i;

    vector<pi> q;
    rep(i,m) q.pb(pi(max(r[a[i]],r[b[i]]),i));
    sort(all(q));

    ll tsum=0;
    int idx=0;
    rep(i,p.size())
    {
        ll tmp = p[i].fi*C;

        while(idx<m && q[idx].fi==i)
        {
            tsum+=c[q[idx].se];
            ++idx;
        }

        tmp += sum-tsum;

        // printf(" X=%lld ,tmp %lld\n", p[i].fi,tmp);
        ans = min(ans,tmp);
    }

    printf("%lld\n", ans);
    return 0;
}
