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

ll mod_inv(ll n)
{
    ll pw[32];
    pw[0]=n;
    for(int i=1; i<32; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    ll p=mod-2;
    rep(i,32) if(p>>i&1) (ret*=pw[i])%=mod;
    return ret;
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
    for(int i=1; i<=200000; ++i) fact[i]=(fact[i-1]*i)%mod;

    ll h,w,a,b;
    cin >>h >>w >>a >>b;

    ll ans=0;

    for(ll i=b; i<w; ++i)
    {
        ll add=1;

        ll p=h-a-1;

        (add*=comb(p+i,i))%=mod;
        (add*=comb(w-1-i+a-1,a-1))%=mod;

        (ans+=add)%=mod;
    }

    cout << ans << endl;
    return 0;
}
