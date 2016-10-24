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

int cost[301][301];
int dp[301][301];
int dfs(int x, int y)
{
    if(dp[x][y]>=0) return dp[x][y];
    if(x+y==2*h) return 0;

    int ret=123456789;
    if(x<h) ret=min(ret,dfs(x+1,y)+cost[x][y]);
    if(y<h) ret=min(ret,dfs(x,y+1)+cost[x][y]);

    return dp[x][y]=ret;
}

int main()
{
    cin >>h >>w;
    rep(i,h) cin >>c[i];

    int ans=0;
    rep(i,w-1)
    {
        memset(cost,0,sizeof(cost));
        for(int a=h-1; a>=0; --a)for(int b=h-1; b>=0; --b) cost[a][b]=cost[a+1][b+1]+(c[h-1-a][i]==c[h-1-b][i+1]);
        memset(dp,-1,sizeof(dp));
        ans+=dfs(0,0);
    }
    printf("%d\n", ans);
    return 0;
}
