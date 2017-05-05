#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n,m;
int f[1001][1001]={};
int dp[1001][1001]={};

int calc(int lx, int ly, int rx, int ry)
{
    return dp[ry][rx] - dp[ry][lx-1] - dp[ly-1][rx] + dp[ly-1][lx-1];
}

int main()
{
    scanf(" %d %d", &n, &m);
    rep(i,n)rep(j,m) scanf(" %d", &f[i+1][j+1]);

    for(int i=1; i<=n; ++i)for(int j=1; j<=m; ++j) dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+f[i][j];

    int ans=-1;
    for(int i=2; i<n; ++i)for(int j=2; j<m; ++j)
    {
        if(f[i][j]==1 && f[i-1][j]==0 && f[i][j-1]==0 && f[i-1][j-1]==0)
        {
            int x=j;
            while(x<=m && f[i][x]==1) ++x;
            --x;

            int y=i;
            while(y<=n && f[y][j]==1) ++y;
            --y;

            if(x==m || y==n) continue;

            if(calc(j,i,x,y)==(x-j+1)*(y-i+1) && calc(j,i,x,y)==calc(j-1,i-1,x+1,y+1))
            {
                ans = max(ans,(x-j+1)*(y-i+1));
            }
        }
    }

    printf("%d\n", ans);
    return 0;
}
