#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=301;

int n;
int f[N][N]={};
int sumx[N][N]={};
int sumy[N][N]={};

int main()
{
    scanf(" %d", &n);
    rep(i,n)rep(j,n) scanf(" %d", &f[i+1][j+1]);

    for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j) sumx[i][j] = sumx[i][j-1]+f[i][j];
    for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j) sumy[j][i] = sumy[j-1][i]+f[j][i];

    int ans = -1000;
    for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j)for(int k=j; k<=n; ++k) ans = max(ans, sumx[i][k]-sumx[i][j-1]);
    for(int i=1; i<=n; ++i)for(int j=1; j<=n; ++j)for(int k=j; k<=n; ++k) ans = max(ans, sumy[k][i]-sumy[j-1][i]);

    // x幅を固定
    for(int lx=1; lx<=n; ++lx)for(int rx=lx+1; rx<=n; ++rx)
    {
        int dp = sumx[n][rx]-sumx[n][lx-1];
        for(int y=n-1; y>=1; --y)
        {
            ans = max(ans, dp+(sumx[y][rx]-sumx[y][lx-1]));
            dp = max(dp+f[y][lx]+f[y][rx],(sumx[y][rx]-sumx[y][lx-1]));
        }
    }

    printf("%d\n", ans);
    return 0;
}
