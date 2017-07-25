#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int INF = 19191919;
int w,h;
char s[100][100];
int f[100][100];

// next step: left(0), right(1)
int dp[60][30][60][30][2];

struct State{
    int ly,lx,ry,rx,LR;
};

int main()
{
    while(scanf(" %d %d", &w, &h),w)
    {
        rep(i,h)rep(j,w)
        {
            scanf(" %c", &s[i][j]);
            if(s[i][j]=='X') f[i][j]=-1;
            else if(s[i][j]=='S' || s[i][j]=='T') f[i][j]=0;
            else f[i][j] = s[i][j]-'0';
        }

        // initialize
        rep(i,60)rep(j,30)rep(k,60)rep(l,30)rep(m,2) dp[i][j][k][l][m]=INF;

        queue<State> que;
        rep(i,h)rep(j,w)if(s[i][j]=='S')
        {
            dp[0][0][i][j][0] = 0;
            que.push({0,0,i,j,0});
            dp[i][j][0][0][1] = 0;
            que.push({i,j,0,0,1});
        }

        #define IN(y,x) (0<=y && y<h && 0<=x && x<w)
        int dy[5]={-2,-1,0,1,2};
        int limx[5]={1,2,3,2,1};
        while(!que.empty())
        {
            State n = que.front();
            que.pop();

            // printf(" (%d %d %d %d %d)\n", n.ly,n.lx,n.ry,n.rx,n.LR);

            int sx,sy,mul;
            if(n.LR == 0)
            {
                sx = n.rx;
                sy = n.ry;
                mul = -1;
            }
            else
            {
                sx = n.lx;
                sy = n.ly;
                mul = 1;
            }

            rep(d,5)for(int i=1; i<=limx[d]; ++i)
            {
                int ny = sy+dy[d];
                int nx = sx+mul*i;
                if(IN(ny,nx) && f[ny][nx]!=-1)
                {
                    if(n.LR==0)
                    {
                        if(dp[ny][nx][sy][sx][1] > dp[n.ly][n.lx][n.ry][n.rx][0]+f[ny][nx])
                        {
                            dp[ny][nx][sy][sx][1] = dp[n.ly][n.lx][n.ry][n.rx][0]+f[ny][nx];
                            que.push({ny,nx,sy,sx,1});
                        }
                    }
                    else
                    {
                        if(dp[sy][sx][ny][nx][0] > dp[n.ly][n.lx][n.ry][n.rx][1]+f[ny][nx])
                        {
                            dp[sy][sx][ny][nx][0] = dp[n.ly][n.lx][n.ry][n.rx][1]+f[ny][nx];
                            que.push({sy,sx,ny,nx,0});
                        }
                    }
                }
            }
        }

        int ans = INF;
        rep(i,h)rep(j,w)if(s[i][j]=='T')
        {
            rep(k,h)rep(l,w)
            {
                ans = min(ans,dp[k][l][i][j][0]);
                ans = min(ans,dp[i][j][k][l][1]);
            }
        }
        if(ans == INF) ans = -1;
        printf("%d\n", ans);
    }
    return 0;
}
