#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF=12345678901234LL;
ll dp[101][101][101];

int main()
{
    int n,m,k,c[100],p[100][100];
    cin >>n >>m >>k;
    rep(i,n) scanf(" %d", &c[i]);
    rep(i,n)rep(j,m) scanf(" %d", &p[i][j]);

    rep(x,101)rep(y,101)rep(z,101) dp[x][y][z]=INF;

    if(c[0]==0)
    {
        for(int i=1; i<=m; ++i) dp[0][i][1]=p[0][i-1];
    }
    else dp[0][c[0]][1]=0;

    for(int i=1; i<n; ++i)
    {
        for(int b=1; b<=k; ++b)
        {
            if(c[i]==0)
            {
                for(int j=1; j<=m; ++j)
                {
                    for(int prev=1; prev<=m; ++prev)
                    {
                        if(j==prev) dp[i][j][b]=min(dp[i][j][b], dp[i-1][prev][b]+p[i][j-1]);
                        else dp[i][j][b]=min(dp[i][j][b], dp[i-1][prev][b-1]+p[i][j-1]);
                    }
                }
            }
            else
            {
                for(int j=1; j<=m; ++j)
                {
                    if(j!=c[i]) dp[i][c[i]][b]=min(dp[i][c[i]][b], dp[i-1][j][b-1]);
                    else dp[i][c[i]][b]=min(dp[i][c[i]][b], dp[i-1][j][b]);
                }
            }

        }
    }

    ll ans=INF;
    for(int i=1; i<=m; ++i) ans=min(ans,dp[n-1][i][k]);

    if(ans==INF) ans=-1;
    cout << ans << endl;
    return 0;
}
