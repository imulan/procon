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

int h,w;
string f[1000];

int dx[8]={0,1,1,1,0,-1,-1,-1}, dy[8]={1,1,0,-1,-1,-1,0,1};
int dp[1000][1000];

inline bool in(int y, int x)
{
    return (0<=y&&y<h && 0<=x&&x<w);
}

int main()
{
    cin >>h >>w;
    rep(i,h) cin >>f[i];

    fill(dp[0],dp[1000],INF);
    rep(i,h)rep(j,w) if(f[i][j]=='.') dp[i][j]=0;

    queue<pi> que;

    rep(i,h)rep(j,w)
    {
        if(dp[i][j]==0)
        {
            rep(k,8)
            {
                int nx=j+dx[k], ny=i+dy[k];
                if(in(ny,nx) && f[ny][nx]!='.')
                {
                    int ct=0;
                    int lim=f[ny][nx]-'0';
                    rep(l,8)
                    {
                        int nnx=nx+dx[l], nny=ny+dy[l];
                        if(f[nny][nnx]=='.') ++ct;
                    }

                    if(ct>=lim)
                    {
                        dp[ny][nx]=1;
                        que.push(pi(ny,nx));
                    }
                }
            }
        }
    }

    while(!que.empty())
    {
        pi now=que.front();
        que.pop();
        rep(i,8)
        {
            int nx=now.se+dx[i], ny=now.fi+dy[i];

            if(f[ny][nx]=='.') continue;
            if(f[ny][nx]=='9') continue;

            vector<int> a;
            rep(j,8)
            {
                int nnx=nx+dx[j], nny=ny+dy[j];
                a.pb(dp[nny][nnx]);
            }
            sort(all(a));

            int p=f[ny][nx]-'0';

            if(dp[ny][nx]>a[p-1]+1)
            {
                dp[ny][nx]=a[p-1]+1;
                que.push(pi(ny,nx));
            }
        }
    }

    int ans=0;
    rep(i,h)rep(j,w) if(dp[i][j]!=INF) ans=max(ans,dp[i][j]);
    cout << ans << endl;
    return 0;
}
