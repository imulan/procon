#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n;
int t[30];

const int N=300;
const int INF=1234;
int f[N][N]={};

int dx[8]={0,1,1,1,0,-1,-1,-1};
int dy[8]={-1,-1,0,1,1,1,0,-1};

bool vis[N][N][8][5][30]={};
void dfs(int sx, int sy, int dir, int rem, int depth)
{
    if(depth==n) return;
    if(vis[sy][sx][dir][rem][depth]) return;

    vis[sy][sx][dir][rem][depth]=true;
    f[sy][sx]=1;
    assert(0<=sx && sx<N && 0<=sy && sy<N);

    if(rem>0)
    {
        dfs(sx+dx[dir],sy+dy[dir],dir,rem-1,depth);
    }
    else
    {
        int nd;

        nd=(dir+7)%8;
        dfs(sx+dx[nd],sy+dy[nd],nd,t[depth+1]-1,depth+1);
        nd=(dir+1)%8;
        dfs(sx+dx[nd],sy+dy[nd],nd,t[depth+1]-1,depth+1);
    }
}

int main()
{
    cin >>n;
    rep(i,n) cin >>t[i];

    dfs(N/2,N/2,0,t[0]-1,0);

    int ans=0;
    rep(i,N)rep(j,N) ans+=f[i][j];

    printf("%d\n", ans);
    return 0;
}
