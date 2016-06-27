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

const ll mod = 1000000007;

//nPr
ll mod_perm(ll n, ll r)
{
    ll ret=1;
    rep(i,r) (ret*=n-i)%=mod;
    return ret;
}

//逆元
ll mod_inv(ll n)
{
    ll pw[32];

    pw[0]=n%mod;
    for(int i=1; i<32; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    ll x=mod-2;
    rep(i,32) if(x>>i&1) (ret*=pw[i])%=mod;

    return ret;
}

int main()
{
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    ll ans=1;

    int st=0;
    while(st<n)
    {
        int ed=st+1;
        while(ed<n && a[ed]==-1) ++ed;

        if(ed>=n) break;

        ll X=a[st], Y=a[ed], L=ed-st-1;
        if(L>0)
        {
            (ans*=mod_perm(Y-X+L,L))%=mod;
            (ans*=mod_inv(mod_perm(L,L)))%=mod;
        }

        st=ed;
    }

    cout << ans << endl;
    return 0;
}
