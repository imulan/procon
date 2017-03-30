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

ll mod_pow(ll x, ll n)
{
    ll pw[32];
    pw[0]=x%mod;
    for(int i=1; i<32; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,32)if(n>>i&1) (ret*=pw[i])%=mod;
    return ret;
}

ll mod_inv(ll x)
{
    return mod_pow(x,mod-2);
}

int gx,gy,k;
int x[5],y[5],n[5];

ll fact[100];

ll ans = 0;

int num[5];
void dfs(int depth)
{
    if(depth == k)
    {
        int X=0,Y=0;
        rep(i,k)
        {
            X += num[i]*x[i];
            Y += num[i]*y[i];
        }

        if(X == gx && Y == gy)
        {
            int sum = 0;
            rep(i,k) sum += num[i];

            ll add = fact[sum];
            rep(i,k) (add*=mod_inv(fact[num[i]]))%=mod;
            (ans+=add)%=mod;
        }

        return;
    }

    rep(i,n[depth]+1)
    {
        num[depth] = i;
        dfs(depth+1);
    }
}

int main()
{
    fact[0]=1;
    for(ll i=1; i<100; ++i) fact[i] = (fact[i-1]*i)%mod;

    cin >>gx >>gy >>k;
    rep(i,k) cin >>x[i] >>y[i] >>n[i];

    dfs(0);

    cout << ans << endl;
    return 0;
}
