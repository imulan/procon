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
typedef vector<int> vi;

const int INF=123456789;

int main()
{
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

    int w,h;
    while(cin >>w >>h,w)
    {
        vector<string> s(h);
        rep(i,h) cin >>s[i];

        vector<pi> tiles;
        rep(i,h)rep(j,w) if(s[i][j]=='o') tiles.pb(pi(i,j));
        rep(i,h)rep(j,w) if(s[i][j]=='*') tiles.pb(pi(i,j));

        int T=tiles.size();

        int d[11][11]={0};

        #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
        rep(i,T)
        {
            vector<vi> dist(h,vi(w,INF));
            dist[tiles[i].fi][tiles[i].se]=0;
            queue<pi> que;
            que.push(pi(tiles[i]));
            while(!que.empty())
            {
                pi now=que.front();
                que.pop();
                rep(j,4)
                {
                    int nx=now.se+dx[j], ny=now.fi+dy[j];
                    if(IN(nx,ny) && s[ny][nx]!='x' && dist[ny][nx]>dist[now.fi][now.se]+1)
                    {
                        dist[ny][nx]=dist[now.fi][now.se]+1;
                        que.push(pi(ny,nx));
                    }
                }
            }

            rep(j,T)
            {
                if(i==j) continue;
                d[i][j]=dist[tiles[j].fi][tiles[j].se];
            }
        }

        int dp[2048][11];
        fill(dp[0],dp[2048],INF);
        dp[1][0]=0;
        for(int i=1; i<(1<<T); ++i)rep(j,T)if(i>>j&1)rep(k,T)if(!(i>>k&1))
        {
            int nx=i+(1<<k);
            dp[nx][k]=min(dp[nx][k],dp[i][j]+d[j][k]);
        }

        int ans=INF;
        rep(i,T) ans=min(ans,dp[(1<<T)-1][i]);
        if(ans==INF) ans=-1;
        printf("%d\n", ans);
    }
    return 0;
}
