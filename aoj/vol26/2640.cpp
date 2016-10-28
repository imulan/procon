#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct state
{
    int x;
    int y;
    int hand; //0:正面, 1:斜め右前, 2:右, 3:斜め右後ろ
    int dir; //0:^. 1:>, 2:v, 3:<
};

const int INF=123456789;

int n,m;
#define IN(x,y) (0<=x && x<m && 0<=y && y<n)
char f[55][55];

// (dir,hand) = (i,j)
int hx[4][4]={
    {0,1,1,1},
    {1,1,0,-1},
    {0,-1,-1,-1},
    {-1,-1,0,1}
};
int hy[4][4]={
    {-1,-1,0,1},
    {0,1,1,1},
    {1,1,0,-1},
    {0,-1,-1,-1}
};

int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};
int dd[2]={1,-1};


int ct[55][55]={0};
int vis[55][55][4][4]={0};
int dfs(state cur)
{
    if(f[cur.y][cur.x]=='G')
    {
        int ret=0;
        rep(i,55)rep(j,55) if(ct[i][j]) ++ret;
        return ret;
    }

    if(vis[cur.y][cur.x][cur.hand][cur.dir]) return INF;
    vis[cur.y][cur.x][cur.hand][cur.dir]=1;

    int ret=INF;
    state nx;

    // current_hand
    int chx=cur.x+hx[cur.dir][cur.hand];
    int chy=cur.y+hy[cur.dir][cur.hand];

    // move forward
    nx=cur;
    nx.x+=dx[nx.dir];
    nx.y+=dy[nx.dir];
    if(f[nx.y][nx.x]!='#')
    {
        // search hand area
        rep(i,4)
        {
            int tx=nx.x+hx[nx.dir][i];
            int ty=nx.y+hy[nx.dir][i];
            if(chx==tx && chy==ty)
            {
                nx.hand=i;
                ct[nx.y][nx.x]+=1;
                ret=min(ret,dfs(nx));
                ct[nx.y][nx.x]-=1;
            }
        }
    }

    // turn right,left
    rep(d_id,2)
    {
        nx=cur;
        nx.dir=(nx.dir+dd[d_id]+4)%4;
        // search hand area
        rep(i,4)
        {
            int tx=nx.x+hx[nx.dir][i];
            int ty=nx.y+hy[nx.dir][i];
            if(chx==tx && chy==ty)
            {
                nx.hand=i;
                ret=min(ret,dfs(nx));
            }
        }
    }

    // move hand
    rep(i,4)
    {
        nx=cur;
        int tx=nx.x+hx[nx.dir][i];
        int ty=nx.y+hy[nx.dir][i];
        if(f[ty][tx]=='#' && abs(tx-chx)<=1 && abs(ty-chy)<=1)
        {
            nx.hand=i;
            ret=min(ret,dfs(nx));
        }
    }

    return ret;
}


int main()
{
    scanf(" %d %d", &n, &m);

    state start;

    rep(i,m+2) f[0][i]='#';
    for(int i=1; i<=n; ++i)
    {
        f[i][0]='#';
        for(int j=1; j<=m; ++j)
        {
            scanf(" %c", &f[i][j]);
            if(f[i][j]!='.' && f[i][j]!='#' && f[i][j]!='G')
            {
                start.y=i;
                start.x=j;
                start.hand=2;
                if(f[i][j]=='^') start.dir=0;
                if(f[i][j]=='>') start.dir=1;
                if(f[i][j]=='v') start.dir=2;
                if(f[i][j]=='<') start.dir=3;
            }
        }
        f[i][m+1]='#';
    }
    rep(i,m+2) f[n+1][i]='#';
    n+=2;
    m+=2;

    ct[start.y][start.x]+=1;
    int ans=dfs(start);
    if(ans==INF) ans=-1;
    printf("%d\n", ans);
    return 0;
}
