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

const ll mod = 1e9+7;

void solve()
{
    int n,q;
    scanf(" %d %d", &n, &q);

    vector<vector<int>> G(n);
    rep(i,n-1)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        --x; --y;
        G[x].pb(y);
        G[y].pb(x);
    }

    vector<ll> val(n);
    while(q--)
    {
        int t,v;
        scanf(" %d %d", &t, &v);
        --v;
        if(t==1)
        {
            int k;
            ll a,b;
            scanf(" %d %lld %lld", &k, &a, &b);

            vector<ll> f(k+2);
            f[0] = a;
            f[1] = b;
            for(int i=2; i<=k; ++i) f[i] = (f[i-1]+f[i-2])%mod;

            vector<int> d(n,19191919);
            queue<int> que;
            que.push(v);
            d[v] = 0;
            while(!que.empty())
            {
                int now = que.front();
                que.pop();
                for(int nx:G[now])
                {
                    if(d[nx]>d[now]+1)
                    {
                        d[nx]=d[now]+1;
                        que.push(nx);
                    }
                }
            }

            rep(i,n)if(d[i]<=k) (val[i]+=f[d[i]])%=mod;
        }
        else printf("%lld\n", val[v]);
    }
}

int main()
{
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
