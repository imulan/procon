#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

ll fact(int n)
{
    ll ret=1;
    for(ll i=1; i<=n; ++i) (ret*=i)%=mod;
    return ret;
}

ll mod_pow(int x, int n)
{
    ll pw[32];
    pw[0]=x;
    for(int i=1; i<32; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,32)if(n>>i&1) (ret*=pw[i])%=mod;
    return ret;
}

ll mod_inv(int x)
{
    return mod_pow(x,mod-2);
}

ll C(int n, int k)
{
    ll ret=fact(n);
    (ret*=mod_inv(fact(k)))%=mod;
    (ret*=mod_inv(fact(n-k)))%=mod;
    return ret;
}

int main()
{
    int n,k;
    cin >>n >>k;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    map<ll,int> m;
    rep(i,n) ++m[a[i]];

    ll ans=0;
    for(int i=60; i>=0; --i)
    {
        map<ll,int> nx;

        int ct=0;
        for(const auto &p:m)
        {
            ll v=p.fi;
            if(v>>i&1)
            {
                ct += p.se;
                nx[v]=p.se;
            }
        }

        if(ct>=k)
        {
            ans+=1LL<<i;
            m=nx;
        }
    }

    int r=0;
    for(const auto &p:m) r+=p.se;

    cout << ans << endl;
    cout << C(r,k) << endl;
    return 0;
}
