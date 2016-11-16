#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int M,W;
int bm[12],bw[12];

inline int calc(int m, int w)
{
    int d=abs(bm[m]-bw[w]);
    return d*(d-30)*(d-30);
}

int dp[13][4100];
int dfs(int x, int mask)
{
    if(dp[x][mask]>=0) return dp[x][mask];
    if(x==M || mask==(1<<W)-1) return 0;

    int ret=dfs(x+1,mask);
    rep(i,W)
    {
        if(mask>>i&1) continue;
        ret=max(ret,dfs(x+1,mask+(1<<i))+calc(x,i));
    }

    return dp[x][mask]=ret;
}

int main()
{
    while(scanf(" %d %d", &M, &W),M)
    {
        rep(i,M) scanf(" %d", &bm[i]);
        rep(i,W) scanf(" %d", &bw[i]);

        memset(dp,-1,sizeof(dp));
        printf("%d\n", dfs(0,0));
    }
    return 0;
}
