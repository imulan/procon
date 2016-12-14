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
    ll pw[40];
    pw[0]=x;
    for(int i=1; i<40; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,40)
    {
        if(n>>i&1) (ret*=pw[i])%=mod;
    }
    return ret;
}

vector<int> factor(int n)
{
    vector<int> ret;

    for(int i=1; i*i<=n; ++i)
    {
        if(n%i==0)
        {
            ret.pb(i);
            if(i != n/i) ret.pb(n/i);
        }
    }

    sort(all(ret));
    return ret;
}

int main()
{
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<int> d = factor(n);
    int D=d.size();

    vector<ll> dp(D);
    rep(i,D)
    {
        dp[i] = mod_pow(k,(d[i]+1)/2);

        rep(j,i)if(d[i]%d[j]==0) dp[i] = (dp[i]-dp[j]+mod)%mod;
    }

    ll ans=0;
    rep(i,D)
    {
        if(d[i]%2==0) (ans+=dp[i]*d[i]/2)%=mod;
        else (ans+=dp[i]*d[i])%=mod;
    }

    printf("%lld\n", ans);
    return 0;
}
