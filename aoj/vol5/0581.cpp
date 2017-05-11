#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct State{
    int y, x, mask, b;
};

const int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
char f[60][51];

int dp[60][50][1<<12][4]={};
int vis[60][50]={};

int main()
{
    int H,W,K;
    cin >>H >>W >>K;

    memset(dp,-1,sizeof(dp));
    rep(i,6)
    {
        f[i][0]='.';
        for(int j=1; j<W; ++j) f[i][j]='#';
    }
    rep(i,H) scanf("%s", f[i+6]);
    H+=6;

    #define IN(y,x) (0<=y && y<H && 0<=x && x<W)
    queue<State> que;
    que.push({6,0,0,0});
    dp[6][0][0][0]=0;
    while(!que.empty())
    {
        State s = que.front();
        que.pop();

        int d[6];
        rep(i,6) d[i] = (s.mask>>(2*i))&3;

        int px[7],py[7];
        px[0] = s.x;
        py[0] = s.y;
        rep(i,6)
        {
            px[i+1] = px[i] - dx[d[i]];
            py[i+1] = py[i] - dy[d[i]];
        }
        rep(i,7) vis[py[i]][px[i]]=1;

        rep(i,4)
        {
            int nx = s.x+dx[i], ny = s.y+dy[i];
            int nb = s.b+(i>=2);
            if(nb<=K && IN(ny,nx) && f[ny][nx]!='#')
            {
                int add=max(0,f[ny][nx]-'0');
                if(vis[ny][nx]) add=0;

                int nmask = ((s.mask<<2)&((1<<12)-1)) + i;
                if(dp[ny][nx][nmask][nb] < dp[s.y][s.x][s.mask][s.b] + add)
                {
                    dp[ny][nx][nmask][nb] = dp[s.y][s.x][s.mask][s.b] + add;
                    que.push({ny,nx,nmask,nb});
                }
            }
        }

        rep(i,7) vis[py[i]][px[i]]=0;
    }

    int ans=0;
    rep(M,1<<12)rep(B,4) ans=max(ans,dp[H-1][W-1][M][B]);
    printf("%d\n", ans);
    return 0;
}
