#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=1000;
const int INF=101010101;

int n;
int f[N+1][N+1]={};
int sumf[N+1][N+1]={};

int dp[N+1][N+1];

int main()
{
    scanf(" %d", &n);
    rep(i,n)rep(j,n) scanf(" %d", &f[i+1][j+1]);

    for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j)
    {
        sumf[i][j] = sumf[i][j-1]+f[i][j];
    }

    fill(dp[0],dp[N+1],-INF);
    dp[1][1]=0;
    for(int i=2; i<=n; ++i)
    {
        int m = -INF;
        for(int j=1; j<i; ++j)
        {
            m = max(m, dp[i-1][j]);
            dp[i][j] = m+2*(sumf[i][i]-sumf[i][j-1]);
        }
        dp[i][i] = m;
    }

    int ans = -INF;
    for(int i=1; i<=n; ++i) ans = max(ans, dp[n][i]);
    printf("%d\n", ans);
    return 0;
}
