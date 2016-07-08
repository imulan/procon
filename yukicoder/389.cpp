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
    int m;
    cin >>m;

    vector<ll> h;
    ll a;
    while(cin >>a) h.pb(a);

    int k=h.size();
    //rep(i,k) printf(" %lld\n",h[i]);

    if(k==1)
    {
        int ans=1;
        if(h[0]>0) ans=m-h[0]+1;
        printf("%d\n", ans);
    }
    else
    {
        ll s=0;
        rep(i,k) s+=h[i];

        //区間の間には必ず1つ以上白がいる
        ll r=m-s-(k-1);

        if(r<0) printf("NA\n");
        else
        {
            ll ans=mod_fact(r+k);
            (ans*=mod_inv(mod_fact(r)))%=mod;
            (ans*=mod_inv(mod_fact(k)))%=mod;

            cout << ans << endl;
        }
    }

    return 0;
}
