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
const int LIM = 256;
const int M = 1<<17;

int ct[LIM]={};
ll f[191919];

ll mod_pow(ll x, ll n)
{
    ll ret = 1;
    while(n)
    {
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

ll mod_inv(ll x)
{
    return mod_pow(x, mod-2);
}

ll C(ll n, ll r)
{
    ll ret = f[n];
    (ret*=mod_inv(f[r]))%=mod;
    (ret*=mod_inv(f[n-r]))%=mod;
    return ret;
}

int main()
{
    f[0] = 1;
    for(ll i=1; i<191919; ++i) f[i]=(f[i-1]*i)%mod;

    int n,k;
    cin >>n >>k;

    vector<int> l;
    rep(i,n)
    {
        int a;
        cin >>a;

        if(a<LIM) ++ct[a];
        else l.pb(a);
    }

    vector<ll> dp(M);
    dp[0]=1;
    rep(i,l.size())
    {
        vector<ll> nx(M);
        rep(mask,M)
        {
            (nx[mask] += dp[mask])%=mod;

            int nmask = mask^l[i];
            (nx[nmask] += dp[mask])%=mod;
        }

        dp = nx;
    }

    vector<ll> dp2(LIM);
    dp2[0]=1;
    for(int i=1; i<LIM; ++i)if(ct[i]>0)
    {
        ll e=0, o=0;
        rep(j,ct[i]+1)
        {
            if(j%2==0) (e+=C(ct[i],j))%=mod;
            else (o+=C(ct[i],j))%=mod;
        }
        vector<ll> nx(LIM);
        rep(mask,LIM)
        {
            (nx[mask] += dp2[mask]*e)%=mod;

            int nmask = mask^i;
            (nx[nmask] += dp2[mask]*e)%=mod;
        }


        dp2 = nx;
    }

    ll ans = 0;
    rep(i,M)rep(j,LIM)
    {
        if((i^j)==k) (ans += (dp[i]*dp2[j])%mod)%=mod;
    }
    cout << ans << endl;
    return 0;
}
