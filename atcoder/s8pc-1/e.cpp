#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll mod = 1e9+7;

ll mod_pow(ll x, ll n)
{
    ll ret = 1;

    ll pw[32];
    pw[0]=x;
    for(int i=1; i<32; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    rep(i,32)
    {
        if(n>>i&1) (ret*=pw[i])%=mod;
    }

    return ret;
}

int main()
{
    int n,q;
    scanf(" %d %d", &n, &q);

    vector<int> a(n),c(q+2);
    rep(i,n) scanf(" %d", &a[i]);

    c[0]=0;
    rep(i,q)
    {
        scanf(" %d", &c[i+1]);
        --c[i+1];
    }
    c[q+1]=0;

    // iとi+1の間の距離
    vector<ll> d(n-1);
    rep(i,n-1) d[i]=mod_pow(a[i],a[i+1]);

    vector<ll> sumd(n);
    for(int i=1; i<n; ++i) sumd[i]=(sumd[i-1]+d[i-1])%mod;

    ll ans = 0;
    rep(i,q+1)
    {
        int x=c[i], y=c[i+1];
        if(x>y) swap(x,y);
        ans+=(sumd[y]-sumd[x]+mod)%mod;
        ans%=mod;
    }

    cout << ans << endl;
    return 0;
}
