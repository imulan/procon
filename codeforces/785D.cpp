#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod = 1e9+7;
const int N=202020;

ll fact[N];

inline ll mod_pow(ll x, ll n)
{
    ll pw[32];
    pw[0]=x;
    for(int i=1; i<32; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,32)if(n>>i&1) (ret*=pw[i])%=mod;
    return ret;
}

inline ll mod_inv(ll x)
{
    return mod_pow(x,mod-2);
}

inline ll comb(int n, int r)
{
    ll ret = fact[n];
    (ret*=mod_inv(fact[r]))%=mod;
    (ret*=mod_inv(fact[n-r]))%=mod;
    return ret;
}

int main()
{
    fact[0]=1;
    for(int i=1; i<N; ++i) fact[i]=(fact[i-1]*i)%mod;

    string s;
    cin >>s;
    int S = s.size();

    int lb=0,rb=0;
    rep(i,S) rb+=(s[i]==')');

    ll ans=0;

    rep(i,S)
    {
        if(s[i]==')') --rb;
        else
        {
            ++lb;
            (ans+=comb(lb+rb-1,lb))%=mod;
        }
    }

    cout << ans << endl;
    return 0;
}
