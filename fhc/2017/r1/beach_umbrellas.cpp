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
    ll pw[33];
    pw[0]=x;
    for(int i=1; i<33; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,33)if(n>>i&1) (ret*=pw[i])%=mod;
    return ret;
}

ll mod_inv(ll n)
{
    return mod_pow(n,mod-2);
}

map<ll,ll> dp;
ll P(ll n, ll r)
{
    if(dp.count(n)) return dp[n];

    ll ret=1;

    ll t=n;
    rep(i,r)
    {
        ret*=t;
        ret%=mod;
        --t;
    }

    dp[n]=ret;
    return ret;
}

ll solve()
{
    dp.clear();

    int n;
    ll m;
    cin >>n >>m;

    int sum_r=0;
    vector<int> r(n);
    rep(i,n)
    {
        cin >>r[i];
        sum_r+=r[i]*2;
    }

    if(n==1) return m;


    ll factn=1;
    for(ll i=1; i<=n; ++i) (factn*=i)%=mod;

    ll inv_factn = mod_inv(factn);

    ll f2 = 1;
    for(ll i=1; i<=n-2; ++i) (f2*=i)%=mod;

    ll ret=0;
    // 左端i,右端j
    rep(i,n)rep(j,n)if(i!=j)
    {
        ll rem = m - (sum_r - r[i] - r[j])-1;
        if(rem<0) continue;

        ret += (((P(rem+n,n)*inv_factn)%mod)*f2)%mod;
        ret %= mod;
    }
    return ret;
}

int main()
{
    int T;
    cin >>T;
    rep(cases,T) printf("Case #%d: %lld\n", cases+1, solve());
    return 0;
}
