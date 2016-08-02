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

typedef pair<int,int> pi;

const int INF=123456789;
int n,m;

inline bool in(int x, int y)
{
    return(0<=x && x<m && 0<=y && y<n);
}

int main()
{
    int P;
    int a[300][300];
    int ct[90000]={0};

    //i番の引き出しの位置を記録
    vector<pi> num[90000];

    cin >>n >>m >>P;
    rep(i,n)rep(j,m)
    {
        scanf(" %d", &a[i][j]);
        //0-indexedに揃える
        --a[i][j];

        num[a[i][j]].pb(pi(i,j));
        ++ct[a[i][j]];
    }

    int dp[300][300];
    fill(dp[0],dp[300],INF);

    //まず0の位置のdpを更新しておく
    for(const auto &p:num[0]) dp[p.fi][p.se] = p.fi+p.se;

    for(int b=1; b<P; ++b)
    {
        if(ct[b]*ct[b-1] >= n*m)
        {
            int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

            //BFS
            int d[300][300];
            fill(d[0],d[300],INF);
            queue<pi> que;
            for(const auto &p: num[b-1])
            {
                que.push(p);
                d[p.fi][p.se]=dp[p.fi][p.se];
            }

            while(!que.empty())
            {
                pi v=que.front();
                que.pop();
                rep(i,4)
                {
                    int nx=v.se+dx[i], ny=v.fi+dy[i];
                    if(in(nx,ny) && d[ny][nx]>d[v.fi][v.se]+1)
                    {
                        d[ny][nx] = d[v.fi][v.se]+1;
                        que.push(pi(ny,nx));
                    }
                }
            }

            for(const auto &p:num[b]) dp[p.fi][p.se]=d[p.fi][p.se];
        }
        else
        {
            //ループでDP更新
            for(const auto &p:num[b])
            {
                for(const auto &q:num[b-1])
                {
                    dp[p.fi][p.se] = min(dp[p.fi][p.se], dp[q.fi][q.se]+abs(p.fi-q.fi)+abs(p.se-q.se));
                }
            }
        }
    }

    int ans=INF;
    for(const auto &p:num[P-1]) ans=min(ans, dp[p.fi][p.se]);
    cout << ans << endl;
    return 0;
}
