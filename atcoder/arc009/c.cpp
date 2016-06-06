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

const ll mod =1777777777;

ll mod_inv(ll x)
{
    ll pw[33];
    pw[0]=x%mod;
    for(int i=1; i<=32; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll p=mod-2;
    ll ret=1;
    rep(i,33)
    {
        if(p>>i&1)
        {
            ret*=pw[i];
            ret%=mod;
        }
    }

    return ret;
}

int main()
{
    ll n,k;
    cin >>n >>k;

    ll ans=1;
    for(ll i=n-k+1; i<=n; ++i)
    {
        ans*=i%mod;
        ans%=mod;
    }
    for(ll i=1; i<=k; ++i)
    {
        ans*=mod_inv(i);
        ans%=mod;
    }

    ll m[777778];
    m[1]=0;
    m[2]=1;
    for(int i=3; i<=k; ++i)
    {
        m[i]=(m[i-1]+m[i-2])%mod;
        m[i]*=i-1;
        m[i]%=mod;
    }

    ans*=m[k];
    ans%=mod;

    cout << ans << endl;

    return 0;
}
