#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=129402307;

ll MOD(string s, ll z)
{
    ll a=0;
    rep(i,s.size())
    {
        a*=10;
        a+=s[i]-'0';
        a%=z;
    }
    return a;
}

ll mod_pow(ll x, ll n)
{
    ll pw[40];
    pw[0]=x;
    for(int i=1; i<40; ++i) pw[i] = (pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,40)if(n>>i&1) (ret*=pw[i])%=mod;
    return ret;
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    string N,M;
    cin >>N >>M;

    ll ans=0;
    
    if(N=="0") ans=0;
    else if(M=="0") ans=1;
    else
    {
        if(MOD(N,mod) == 0) ans=0;
        else
        {
            ll n=MOD(N,mod), m=MOD(M,mod-1);
            ans = mod_pow(n,m);
        }
    }

    cout << ans << '\n';
    return 0;
}
