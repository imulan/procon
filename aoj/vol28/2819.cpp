#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using P = pair<ll,int>;

const int V = 50000;
const ll INF = LLONG_MAX/3;
struct edge{int to; ll cost;};

vector<edge> G[V];
ll d[V];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> x(m),y(m);
    vector<ll> t(m);
    rep(i,m)
    {
        scanf(" %d %d %lld", &x[i], &y[i], &t[i]);
        --x[i];
        --y[i];
    }
    int v0,a,b,c;
    scanf(" %d %d %d %d", &v0, &a, &b, &c);

    rep(v,c)
    {
        int nv = (a*v+b)%c;
        rep(i,m)
        {
            G[c*x[i]+v].pb({c*y[i]+nv,t[i]*v});
            G[c*y[i]+v].pb({c*x[i]+nv,t[i]*v});
            int A = c*n;
            G[A+c*x[i]+v].pb({A+c*y[i]+nv,t[i]*v});
            G[A+c*y[i]+v].pb({A+c*x[i]+nv,t[i]*v});
        }
    }

    rep(i,c)
    {
        int u = c*(n-1)+i, v = n*c+u;
        G[u].pb({v,0});
        G[v].pb({u,0});
    }

    // dijkstra
    fill(d,d+V,INF);
    d[v0]=0;
    priority_queue<P,vector<P>,greater<P>> que;
    que.push(P(0,v0));
    while(!que.empty())
    {
        P p = que.top();
        que.pop();

        int v = p.se;
        if(p.fi>d[v]) continue;

        for(const auto &e:G[v])
        {
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to] = d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }

    ll ans = INF;
    rep(i,c) ans = min(ans,d[n*c+i]);
    printf("%lld\n", ans);
    return 0;
}
