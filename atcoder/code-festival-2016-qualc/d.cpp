#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int h,w;
string c[300];

int cost[2][301][301]={0};

int dp[301][301][301];
int dfs(int x, int y, int z)
{
    if(dp[x][y][z]>=0) return dp[x][y][z];
    if(x+y+z==3*h) return 0;

    int ret=12345678;

    if(x<h) ret = min(ret,dfs(x+1,y,z)+cost[0][x][y]);
    if(y<h) ret = min(ret,dfs(x,y+1,z)+cost[0][x][y]+cost[1][y][z]);
    if(z<h) ret = min(ret,dfs(x,y,z+1)+cost[1][y][z]);

    return dp[x][y][z]=ret;
}

int main()
{
    cin >>h >>w;
    rep(i,h) cin >>c[i];
    if(w>0)
    {
        for(int i=1; i<w-1; ++i)
        {
            rep(x,h)rep(y,h)
            {
                cost[0][x][y]=0;
                int stx=h-1-x, sty=h-1-y;
                while(stx>=0 && sty>=0)
                {
                    if(c[stx][i-1]==c[sty][i]) ++cost[0][x][y];
                    --stx;
                    --sty;
                }
            }
            rep(y,h)rep(z,h)
            {
                cost[1][y][z]=0;
                int sty=h-1-y, stz=h-1-z;
                while(sty>=0 && stz>=0)
                {
                    if(c[sty][i]==c[stz][i+1]) ++cost[1][y][z];
                    --sty;
                    --stz;
                }
            }

            memset(dp,-1,sizeof(dp));
            cout << dfs(0,0,0) << endl;
        }
    }
    return 0;
}
