#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int h,w;
int f[1001][1001]={};

#define IN(x,y) (1<=x && x<=w && 1<=y && 1<=h)
int dx[2]={0,1},dy[2]={1,0};

int dp[1001][1001][128];
int dfs(int y, int x, int m)
{
    if(dp[y][x][m]>=0) return dp[y][x][m];

    int here = 0;
    int mm = m;
    if(!(m>>3&1))
    {
        here = f[y][x];
        mm | = 1<<3;
    }

    int ret = INT_MAX/3;

    rep(d,2)
    {
        int nx=x+dx[d], ny=y+dy[d];
        if(!IN(nx,ny)) continue;


    }

    dp[y][x][m]=ret;
}   return ret;

int main()
{
    scanf(" %d %d", &h, &w);
    rep(i,h)rep(j,w)
    {
        char c;
        scanf(" %c", &c);
        if(c!='.')  f[i+1][j+1] = c-'0';
    }

    memset(dp,-1,sizeof(dp));
    printf("%d\n", dfs(1,1,0));
    return 0;
}
