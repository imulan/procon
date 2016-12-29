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

int main()
{
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
    int w,h;
    while(scanf(" %d %d", &w, &h), w)
    {
        int n;
        scanf(" %d", &n);

        vector<int> x1(n), y1(n), x2(n), y2(n);
        vector<int> x,y;

        rep(i,n)
        {
            scanf(" %d %d %d %d", &x1[i], &y1[i], &x2[i], &y2[i]);
            x.pb(x1[i]);
            x.pb(x2[i]);
            y.pb(y1[i]);
            y.pb(y2[i]);
        }

        x.pb(0);
        x.pb(w);
        y.pb(0);
        y.pb(h);

        sort(all(x));
        x.erase(unique(all(x)),x.end());
        sort(all(y));
        y.erase(unique(all(y)),y.end());

        int X=x.size(), Y=y.size();

        vector<vector<int>> f(Y,vector<int>(X,0)), dp(Y,vector<int>(X));

        rep(i,X) f[Y-1][i]=1;
        rep(i,Y) f[i][X-1]=1;

        rep(i,n)
        {
            int lx = lower_bound(all(x),x1[i])-x.begin();
            int rx = lower_bound(all(x),x2[i])-x.begin();
            int ly = lower_bound(all(y),y1[i])-y.begin();
            int ry = lower_bound(all(y),y2[i])-y.begin();

            // printf("%d,%d  %d %d\n", lx,rx, ly,ry);
            ++f[ly][lx];
            --f[ly][rx];
            --f[ry][lx];
            ++f[ry][rx];
        }

        dp[0][0]=f[0][0];
        for(int i=1; i<X; ++i) dp[0][i] = dp[0][i-1]+f[0][i];
        for(int i=1; i<Y; ++i) dp[i][0] = dp[i-1][0]+f[i][0];

        for(int i=1; i<Y; ++i)for(int j=1; j<X; ++j) dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+f[i][j];

        // for(int i=Y-1; i>=0; --i)
        // {
        //     rep(j,X) printf("%d", dp[i][j]);
        //     printf("\n");
        // }

        vector<vector<bool>> vis(Y,vector<bool>(X,false));

        #define IN(a,b) (0<=a && a<X && 0<=b && b<Y)
        int ans=0;
        rep(i,Y)rep(j,X)
        {
            if((dp[i][j]>0) || vis[i][j]) continue;

            ++ans;

            queue<pi> que;
            que.push(pi(i,j));
            vis[i][j]=true;
            while(!que.empty())
            {
                pi now=que.front();
                que.pop();
                rep(k,4)
                {
                    int nx=now.se+dx[k], ny=now.fi+dy[k];
                    if(IN(nx,ny) && !vis[ny][nx] && dp[ny][nx]==0)
                    {
                        vis[ny][nx]=true;
                        que.push(pi(ny,nx));
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
