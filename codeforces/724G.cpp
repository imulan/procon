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

#define pf push_front
using pi = pair<int,int>;
struct edge{ int to; ll cost; };

const ll mod = 1e9+7;
const int N = 100001;
const int INF = 19191919;
vector<edge> G[N];
int d[N];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    rep(i,m)
    {
        int u,v;
        ll t;
        scanf(" %d %d %lld", &u, &v, &t);
        --u;
        --v;
        G[u].pb({v,t});
        G[v].pb({u,t});
    }

    ll ans = 0;
    rep(i,60)
    {
        vector<bool> vis(n);
        fill(d,d+N,INF);
        rep(j,n)
        {
            if(vis[j]) continue;

            vector<int> v;
            deque<pi> dq;
            d[j] = 0;
            dq.pb({0,j});
            while(!dq.empty())
            {
                pi p = dq.front();
                dq.pop_front();

                int now = p.se;
                if(p.fi>d[now]) continue;
                v.pb(now);
                for(const auto &e:G[now])
                {
                    int cost = e.cost>>i&1;
                    if(d[e.to]>d[now]+cost)
                    {
                        d[e.to]=d[now]+cost;
                        if(cost==0) dq.pf({d[e.to],e.to});
                        else dq.pb({d[e.to],e.to});
                    }
                }
            }

            dbg(v);

            bool odd_loop = false;
            ll odd = 0, even = 0;
            for(const auto &x:v)
            {
                vis[x]=true;
                if(d[x]%2==0) ++even;
                else ++odd;

                for(const auto &e:G[x])
                {
                    int cost = e.cost>>i&1;
                    int diff = abs(d[x]-d[e.to]);
                    if(cost==1 && diff%2==0) odd_loop=true;
                }
            }

            ll add = (1LL<<i)%mod;
            if(odd_loop)
            {
                dbg("ODD");
                ll V = v.size();
                ll mul = (V*(V-1)/2)%mod;
                (add*=mul)%=mod;

            }
            else (add*=(odd*even)%mod)%=mod;
            dbg(add);
            (ans += add)%=mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
