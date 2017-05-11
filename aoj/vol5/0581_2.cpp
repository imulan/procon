#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
char f[60][51];

int vis[60][50]={};
int dp[60][50][1<<12][4];

int main()
{
    int H,W,K;
    cin >>H >>W >>K;

    rep(i,6)
    {
        f[i][0]='.';
        for(int j=1; j<W; ++j) f[i][j]='#';
    }
    rep(i,H) scanf("%s", f[i+6]);
    H+=6;

    #define IN(y,x) (0<=y && y<H && 0<=x && x<W)
    memset(dp,-1,sizeof(dp));
    dp[6][0][0][0]=0;
    rep(b,K+1)rep(y,H)rep(x,W)if(f[y][x]!='#')
    {
        rep(mask,1<<12)if(dp[y][x][mask][b]>=0)
        {
            int d[6];
            rep(i,6) d[i] = (mask>>(2*i))&3;

            int px[7],py[7];
            px[0] = x;
            py[0] = y;
            rep(i,6)
            {
                px[i+1] = px[i] - dx[d[i]];
                py[i+1] = py[i] - dy[d[i]];
            }

            rep(i,7) vis[py[i]][px[i]]=1;

            rep(i,4)
            {
                int nx = x+dx[i], ny = y+dy[i], nb = b+(i>=2);
                if(nb<=K && IN(ny,nx) && f[ny][nx]!='#')
                {
                    int add=max(0,f[ny][nx]-'0');
                    if(vis[ny][nx]) add=0;

                    int nmask = ((mask<<2)&((1<<12)-1)) + i;

                    dp[ny][nx][nmask][nb] = max(dp[ny][nx][nmask][nb], dp[y][x][mask][b] + add);
                }
            }

            rep(i,7) vis[py[i]][px[i]]=0;
        }
    }

    int ans=0;
    rep(M,1<<12)rep(B,K+1) ans=max(ans,dp[H-1][W-1][M][B]);
    printf("%d\n", ans);
    return 0;
}
