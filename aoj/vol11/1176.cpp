#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

int h,w,s;
int u[33][33];

int sum[33][33];
int U;

pi dp[33][33][33][33];

inline void init()
{
    memset(sum,0,sizeof(sum));
    U=0;
    rep(i,33)rep(j,33)rep(k,33)rep(l,33) dp[i][j][k][l]=pi(-1,-1);

}

inline int SUM(int lx, int ly, int rx, int ry)
{
    return sum[ry][rx] - sum[ly-1][rx] - sum[ry][lx-1] + sum[ly-1][lx-1];
}

pi dfs(int lx, int ly, int rx, int ry)
{
    if(dp[lx][ly][rx][ry].fi>=0) return dp[lx][ly][rx][ry];

    pi ret(1,s-U+SUM(lx,ly,rx,ry));

    // 縦に切る
    for(int i=lx; i<rx; ++i)
    {
        if(U-SUM(lx,ly,i,ry)<=s && U-SUM(i+1,ly,rx,ry)<=s)
        {
            pi A = dfs(lx,ly,i,ry), B = dfs(i+1,ly,rx,ry);
            ret = max(ret, pi(A.fi+B.fi, min(A.se,B.se)));
        }
    }

    // 横に切る
    for(int i=ly; i<ry; ++i)
    {
        if(U-SUM(lx,ly,rx,i)<=s && U-SUM(lx,i+1,rx,ry)<=s)
        {
            pi A = dfs(lx,ly,rx,i), B = dfs(lx,i+1,rx,ry);
            ret = max(ret, pi(A.fi+B.fi, min(A.se,B.se)));
        }
    }

    return dp[lx][ly][rx][ry] = ret;
}

int main()
{
    while(scanf(" %d %d %d", &h, &w, &s),h)
    {
        init();

        rep(i,h)rep(j,w)
        {
            scanf(" %d", &u[i+1][j+1]);
            U+=u[i+1][j+1];
        }

        sum[1][1]=u[1][1];
        for(int i=2; i<=w; ++i) sum[1][i] = sum[1][i-1]+u[1][i];
        for(int i=2; i<=h; ++i) sum[i][1] = sum[i-1][1]+u[i][1];
        for(int i=2; i<=h; ++i)for(int j=2; j<=w; ++j) sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + u[i][j];

        pi a = dfs(1,1,w,h);
        printf("%d %d\n", a.fi, a.se);
    }
    return 0;
}
