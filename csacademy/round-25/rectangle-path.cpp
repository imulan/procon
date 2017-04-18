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

const int INF=123456789;

int n,m;
int f[1001][1001];
int h,w,sr,sc,fr,fc;

int dp[1001][1001]={};

int ok[1001][1001]={};
int d[1001][1001];

inline int calc(int r, int c)
{
    return dp[r+h-1][c+w-1] - dp[r-1][c+w-1] - dp[r+h-1][c-1] + dp[r-1][c-1];
}

int solve()
{
    cin >>n >>m;
    rep(i,n)rep(j,m) scanf(" %d", &f[i+1][j+1]);
    cin >>h >>w >>sr >>sc >>fr >>fc;

    for(int i=1; i<=n; ++i)for(int j=1; j<=m; ++j) dp[i][j] = dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+f[i][j];

    for(int i=1; i<=n-h+1; ++i)for(int j=1; j<=m-w+1; ++j) ok[i][j] = calc(i,j);

    // for(int i=1; i<=n; ++i)
    // {
    //     for(int j=1; j<=m; ++j) printf(" %d", ok[i][j]);
    //     printf("\n");
    // }

    fill(d[0],d[1001],INF);
    d[sr][sc]=0;
    queue<pi> que;
    que.push(pi(sr,sc));

    int dr[4]={1,-1,0,0}, dc[4]={0,0,1,-1};
    #define IN(y,x)(1<=y && y<=n-h+1 && 1<=x && x<=m-w+1)
    while(!que.empty())
    {
        pi p=que.front();
        que.pop();
        rep(i,4)
        {
            int nr=p.fi+dr[i], nc=p.se+dc[i];
            if(IN(nr,nc) && ok[nr][nc]==0 && d[nr][nc]>d[p.fi][p.se]+1)
            {
                d[nr][nc]=d[p.fi][p.se]+1;
                que.push(pi(nr,nc));
            }
        }
    }

    int ret=d[fr][fc];
    if(ret==INF) ret=-1;
    return ret;
}

int main()
{
    printf("%d\n", solve());
    return 0;
}
