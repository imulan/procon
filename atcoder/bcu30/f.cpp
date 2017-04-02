#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

ll mod_pow(ll x, ll n)
{
    ll pw[30];
    pw[0]=x;
    for(int i=1; i<30; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,30)if(n>>i&1) (ret*=pw[i])%=mod;
    return ret;
}

ll mod_inv(ll x)
{
    return mod_pow(x,mod-2);
}

int main()
{
    int n;
    scanf(" %d", &n);
    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    ll ans=0;

    ll add=0;
    ll t=1;
    int r=n-1;
    rep(i,n)
    {
        (t*=a[i])%=mod;
        (add+=(t*mod_pow(2,max(0,r-1)))%mod)%=mod;
        --r;
    }
    ans += add;

    r = n-1;
    for(int i=1; i<n; ++i)
    {
        (add*=mod_inv(a[i-1]))%=mod;
        add = (add-mod_pow(2,max(0,r-1))+mod)%mod;
        (ans+=add*(mod_pow(2,max(0,i-1))))%=mod;
        --r;
    }

    printf("%lld\n", ans);
    return 0;
}
