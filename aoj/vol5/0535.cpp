#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

int m,n;
int f[90][90];
int dy[4]={1,-1,0,0}, dx[4]={0,0,1,-1};

inline bool in(int y, int x)
{
    return (0<=y&&y<n && 0<=x&&x<m);
}

//現在位置
int dfs(int y, int x)
{
    int ret=1;
    rep(i,4)
    {
        int ny=y+dy[i], nx=x+dx[i];
        if(in(ny,nx) && f[ny][nx]==1)
        {
            f[y][x]=0;
            ret=max(ret,dfs(ny,nx)+1);
            f[y][x]=1;
        }
    }

    //printf(" %d,%d ret %d\n", y,x,ret);
    return ret;
}

int main()
{
    while(cin >>m >>n,m|n)
    {
        rep(i,n)rep(j,m) scanf(" %d", &f[i][j]);

        int ans=0;
        rep(i,n)rep(j,m)
        {
            if(f[i][j]==0) continue;
            //printf("start %d,%d\n", i,j);
            ans=max(ans,dfs(i,j));
        }

        cout << ans << endl;
    }
    return 0;
}
