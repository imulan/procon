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
// i行目, j番目の石, k回一行飛ばしジャンプ使用
ll dp[150][10][150];

int k[150];
int x[150][10], d[150][10];

int main()
{
    int n,m;
    while(scanf(" %d %d", &n, &m),n)
    {
        rep(i,n)
        {
            scanf(" %d", &k[i]);
            rep(j,k[i]) scanf(" %d %d", &x[i][j], &d[i][j]);
        }

        fill(dp[0][0],dp[150][0],INF);

        // 0行目
        rep(i,k[0]) dp[0][i][0]=0;
        // 1行目
        if(m>0) rep(i,k[1]) dp[1][i][1]=0;

        ll ans=INF;
        rep(r,n)rep(s,k[r])rep(j,min(76,m+1))
        {
            if(r==n-1 || (r==n-2 && j<m))
            {
                ans = min(ans, dp[r][s][j]);
                continue;
            }

            // 普通のジャンプ
            rep(i,k[r+1])
            {
                ll add=(d[r][s]+d[r+1][i])*abs(x[r][s]-x[r+1][i]);
                dp[r+1][i][j] = min(dp[r+1][i][j], dp[r][s][j]+add);
            }

            // 一行飛ばしのジャンプ
            if(j<m)
            {
                rep(i,k[r+2])
                {
                    ll add=(d[r][s]+d[r+2][i])*abs(x[r][s]-x[r+2][i]);
                    dp[r+2][i][j+1] = min(dp[r+2][i][j+1], dp[r][s][j]+add);
                }
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
