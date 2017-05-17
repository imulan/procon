#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

const int N=1000;
const int INF=INT_MAX/3;
int f[N][N];
int s[N][N];
pi pos[N*N];

int main()
{
    int h,w;
    scanf(" %d %d", &h, &w);
    rep(i,h)rep(j,w)
    {
        scanf(" %d", &f[i][j]);
        --f[i][j];
        pos[f[i][j]] = pi(i,j);
    }

    #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

    memset(s,-1,sizeof(s));
    rep(i,h*w)
    {
        int x=pos[i].se, y=pos[i].fi;

        int low=0;
        rep(d,4)
        {
            int nx=x+dx[d], ny=y+dy[d];
            if(!IN(nx,ny)) continue;
            low += (i>f[ny][nx]);
        }
        if(low==0) s[y][x]=i;

        rep(d,4)
        {
            int nx=x+dx[d], ny=y+dy[d];
            if(!IN(nx,ny)) continue;

            if(i<f[ny][nx])
            {
                if(s[ny][nx]==-1) s[ny][nx] = s[y][x];
                else
                {
                    if(s[ny][nx] != s[y][x]) s[ny][nx] = INF;
                }
            }
        }
    }

    int ans=0;
    rep(i,h)rep(j,w) ans+=(s[i][j]==INF);
    printf("%d\n", ans);
    return 0;
}
