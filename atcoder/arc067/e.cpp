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

int n,a,b,c,d;

ll C[1010][1010]={};
ll dp[1010][1010];
ll fact[1010];
ll fact_inv[1010];

ll mod_inv(ll x)
{
    ll pw[32];
    pw[0]=x;
    for(int i=1; i<32; ++i) pw[i]=(pw[i-1]*pw[i-1])%mod;

    ll ret=1;
    ll p=mod-2;
    rep(i,32) if(p>>i&1) (ret*=pw[i])%=mod;
    return ret;
}

void init()
{
    // combination
    rep(i,1001)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1; j<i; ++j) C[i][j] = (C[i-1][j-1]+C[i-1][j])%mod;
    }

    // fact
    fact[0]=fact[1]=1;
    for(int i=2; i<1001; ++i) fact[i]=(fact[i-1]*i)%mod;

    rep(i,1001) fact_inv[i] = mod_inv(fact[i]);

    // initialize
    memset(dp,-1,sizeof(dp));
}

ll dfs(int rem, int group)
{
    if(group==b+1) return rem?0:1;
    if(dp[rem][group]>=0) return dp[rem][group];

    ll ret=0;

    // 0人
    (ret+=dfs(rem,group+1))%=mod;

    if(c*group <= rem)
    {
        int tr = rem;
        int i=0;
        ll comb=1;
        while(i<c)
        {
            (comb*=C[tr][group])%=mod;
            tr -= group;
            ++i;
        }

        while(i<=d)
        {
            if(tr<0) break;

            // printf(" i = %d\n", i);
            ll add = (dfs(rem-i*group, group+1)*comb)%mod;
            (add*=fact_inv[i])%=mod;

            (ret+=add)%=mod;

            (comb*=C[tr][group])%=mod;
            tr -= group;
            ++i;
        }
    }

    return dp[rem][group]=ret;
}

int main()
{
    cin >>n >>a >>b >>c >>d;
    init();
    cout << dfs(n,a) << endl;
    return 0;
}
