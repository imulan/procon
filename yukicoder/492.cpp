#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll mod_pow(ll x, ll n, ll mod)
{
    ll pw[64];
    pw[0]=x%mod;
    for(int i=1; i<64; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,64)
    {
        if(n>>i&1) (ret*=pw[i])%=mod;
    }
    return ret;
}

ll mod_inv(ll n, ll mod)
{
    return mod_pow(n,mod-2,mod);
}

ll solve1(ll n)
{
    ll mod = 1000000007;

    ll ret = (mod_pow(100,n,mod)-1+mod)%mod;
    ret*=mod_inv(99,mod);

    return ret%mod;
}

string solve2(ll n)
{
    if(n%11==0) return "0";

    string ret="1";
    rep(i,n%11-1) ret+="01";
    return ret;
}

int main()
{
    ll n;
    cin >>n;
    cout << solve1(n) << endl;
    cout << solve2(n) << endl;
    return 0;
}
