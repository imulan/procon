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

ll pw[401][401];
ll sumpw[401][401]={0};
int n,c;
ll a[400],b[400];

ll dp[401][401];
ll dfs(int now, int r)
{
    if(dp[now][r]>=0) return dp[now][r];
    if(now==n) return (r==0);

    ll ret=0;
    rep(i,r+1)
    {
        ll sum=(sumpw[b[now]][i]-sumpw[a[now]-1][i]+mod)%mod;
        // printf("sum=%lld\n", sum);
        ret+=(sum*dfs(now+1,r-i))%mod;
        ret%=mod;
    }

    return dp[now][r]=ret;
}

int main()
{
    rep(i,401)
    {
        pw[i][0]=1;
        for(int j=1; j<=400; ++j) pw[i][j]=(pw[i][j-1]*i)%mod;
    }

    rep(i,401)
    {
        for(int j=1; j<=400; ++j) (sumpw[j][i]+=sumpw[j-1][i]+pw[j][i])%=mod;
    }

    cin >>n >>c;
    rep(i,n) cin >>a[i];
    rep(i,n) cin >>b[i];

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,c) << endl;
    return 0;
}
