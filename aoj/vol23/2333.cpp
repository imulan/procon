#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int mod=1e9+7;
int dp[201][10001];

int main()
{
    int n,W,w[200];
    scanf(" %d %d", &n, &W);
    rep(i,n) scanf(" %d", &w[i]);
    sort(w,w+n);

    int ans=0;

    int all_sum=0;
    rep(i,n) all_sum+=w[i];
    ans+=(all_sum<=W);

    rep(i,n)
    {
        int sum=0;
        rep(j,i) sum+=w[j];
        if(sum>W) break;

        memset(dp,0,sizeof(dp));
        dp[i+1][sum]=1;

        for(int j=i+1; j<n; ++j)for(int k=sum; k<=W; ++k)
        {
            (dp[j+1][k]+=dp[j][k])%=mod;
            if(k+w[j]<=W) (dp[j+1][k+w[j]]+=dp[j][k])%=mod;
        }

        for(int j=max(0,W-w[i]+1); j<=W; ++j) (ans+=dp[n][j])%=mod;
        // printf("  %d\n", ans);
    }

    printf("%d\n", ans);
    return 0;
}
