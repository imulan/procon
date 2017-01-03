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

map<int,int> factorize(int n)
{
    map<int,int> ret;

    int t=n;
    for(int i=2; i*i<=n; ++i)
    {
        while(t%i==0)
        {
            t/=i;
            ++ret[i];
        }
    }
    if(t>1) ++ret[t];

    return ret;
}

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

ll fact[200001];

ll comb(ll n, ll r)
{
    ll ret=fact[n];
    (ret*=mod_inv(fact[r]))%=mod;
    (ret*=mod_inv(fact[n-r]))%=mod;
    return ret;
}

int main()
{
    fact[0]=1;
    for(ll i=1; i<=200000; ++i) fact[i]=(fact[i-1]*i)%mod;

    int n,m;
    cin >>n >>m;

    ll ans=0;
    int st=(n<0)?1:0;
    for(int i=st; i<=m; i+=2) (ans+=comb(m,i))%=mod;

    map<int,int> f=factorize(abs(n));
    for(const auto &x:f) (ans*=comb(x.se+m-1,x.se))%=mod;

    cout << ans << endl;
    return 0;
}
