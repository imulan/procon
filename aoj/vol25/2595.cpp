#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

ll mod_pow(ll x, ll n)
{
    x%=mod;
    n%=(mod-1);

    ll pw[32];
    pw[0]=x;
    for(int i=1; i<32; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    rep(i,32)if(n>>i&1) (ret*=pw[i])%=mod;
    return ret;
}

ll mod_inv(ll x)
{
    return mod_pow(x,mod-2);
}

ll C(ll D, ll P)
{
    ll x=1,y=1;
    for(ll i=1; i<=P; ++i)
    {
        (y*=i)%=mod;
        (x*=(D-P+i)%mod)%=mod;
    }

    return (x*mod_inv(y))%mod;
}

ll dp[2001][2001];

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int N,X;
    ll D;
    while(cin >>N >>D >>X,N)
    {
        if(X==1)
        {
            cout << "0" << '\n';
            continue;
        }

        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1; i<=N; ++i)
        {
            ll sum=0;
            for(int j=1; j<=N; ++j)
            {
                sum = (sum+dp[i-1][j-1])%mod;
                dp[i][j]=sum;
                if(j-X+1>=0) sum = (sum - dp[i-1][j-X+1] + mod)%mod;
            }
        }

        ll ans=0;

        for(int i=1; i<=N; ++i)
        {
            if(D-i<0) break;
            (ans += (dp[i][N]*C(D,i))%mod)%=mod;
        }

        cout << ans << '\n';
    }
    return 0;
}
