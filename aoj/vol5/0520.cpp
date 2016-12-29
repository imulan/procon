#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

inline ll lcm(ll x, ll y)
{
    return x/__gcd(x,y)*y;
}

typedef pair<ll,ll> F;

inline F mul(const F& a, const F& b)
{
    ll p=a.fi*b.fi;
    ll q=a.se*b.se;

    ll g=__gcd(p,q);
    p/=g;
    q/=g;
    return F(p,q);
}

vector<int> tlist;
vector<int> G[100];
vector<bool> vis;

void dfs(int v)
{
    if(vis[v]) return;
    vis[v]=true;
    rep(i,G[v].size()) dfs(G[v][i]);
    tlist.pb(v);
}

void tsort(int n)
{
    vis=vector<bool>(n,false);
    rep(i,n) dfs(i);
    reverse(all(tlist));
}

inline void init()
{
    tlist.clear();
    rep(i,100) G[i].clear();
}

int main()
{
    int n;
    while(scanf(" %d", &n),n)
    {
        init();

        vector<ll> p(n),q(n);
        vector<int> r(n),b(n);

        rep(i,n)
        {
            scanf(" %lld %lld %d %d", &p[i], &q[i], &r[i], &b[i]);

            ll g=__gcd(p[i],q[i]);
            p[i]/=g;
            q[i]/=g;

            --r[i];
            --b[i];

            if(r[i]>=0) G[i].pb(r[i]);
            if(b[i]>=0) G[i].pb(b[i]);
        }

        tsort(n);

        vector<F> dat(n);
        vector<F> w;

        dat[tlist[0]] = F(1,1);
        rep(i,n)
        {
            int idx = tlist[i];

            ll D=p[idx]+q[idx];

            F nr = mul(dat[idx],F(q[idx],D));
            F nb = mul(dat[idx],F(p[idx],D));
            if(r[idx]==-1) w.pb(nr);
            else dat[r[idx]]=nr;
            if(b[idx]==-1) w.pb(nb);
            else dat[b[idx]]=nb;
        }

        ll M=1;
        rep(i,w.size()) M = lcm(M,w[i].se);

        ll ans=0;
        rep(i,w.size())
        {
            F t = mul(w[i],F(M,1));
            ans += t.fi;
        }

        printf("%lld\n", ans);

    }
    return 0;
}
