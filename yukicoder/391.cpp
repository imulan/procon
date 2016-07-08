#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

ll mod_fact(ll x)
{
    ll ret=1;
    for(ll i=2; i<=x; ++i) (ret*=i)%=mod;
    return ret;
}

//x^n
ll mod_pow(ll x, ll n)
{
    ll ret=1;

    ll pw[40];
    pw[0]=x;
    for(int i=1; i<40; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    rep(i,40)
    {
        if(n>>i&1) (ret*=pw[i])%=mod;
    }

    return ret;
}

ll mod_inv(ll x)
{
    ll pw[32];
    pw[0]=x;
    for(int i=1; i<32; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll p=mod-2;
    ll ret=1;
    rep(i,32)
    {
        if(p>>i&1) (ret*=pw[i])%=mod;
    }

    return ret;
}

int main()
{
    ll n,m;
    cin >>n >>m;

    ll ans=0;

    if(n>=m)
    {
        int sgn=1;
        ll a=mod_fact(m);
        ll b=a;
        ll c=1;
        for(ll i=m; i>=1; --i)
        {
            ll mul=1;

            //mCi
            (mul*=a)%=mod;
            (mul*=mod_inv(b))%=mod;
            (mul*=mod_inv(c))%=mod;

            //printf("b= %lld c= %lld\n", b,c);

            (b*=mod_inv(i))%=mod;
            (c*=(m-i+1))%=mod;

            //i^n
            (mul*=mod_pow(i,n))%=mod;

            ans=(ans+sgn*mul+mod)%mod;
            sgn=-sgn;
        }
    }

    cout << ans << endl;

    return 0;
}
