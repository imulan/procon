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
    int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
    int w,h;
    while(cin >>w >>h)
    {
        vector<string> s(h);
        rep(i,h) cin >>s[i];
        int n;
        scanf(" %d", &n);
        vector<int> x(n),y(n);
        rep(i,n) scanf(" %d %d", &x[i], &y[i]);

        pi g;
        rep(i,h)rep(j,w) if(s[i][j]=='t') g=pi(i,j);

        int ans=-1;
        #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
        vector<vector<bool>> vis(h,vector<bool>(w,false));
        vis[0][0]=true;
        queue<pi> que;
        que.push(pi(0,0));
        rep(i,n+1)
        {
            while(!que.empty())
            {
                pi now=que.front();
                que.pop();
                if(now==g)
                {
                    ans=i;
                    break;
                }
                rep(j,4)
                {
                    int nx=now.se+dx[j],ny=now.fi+dy[j];
                    if(IN(nx,ny) && s[ny][nx]!='#' && !vis[ny][nx])
                    {
                        vis[ny][nx]=true;
                        que.push(pi(ny,nx));
                    }
                }
            }

            if(i==n || ans>=0) break;

            s[y[i]][x[i]]='.';
            rep(j,4)
            {
                int tx=x[i]+dx[j],ty=y[i]+dy[j];
                if(IN(tx,ty) && vis[ty][tx] && !vis[y[i]][x[i]])
                {
                    vis[y[i]][x[i]]=true;
                    que.push(pi(y[i],x[i]));
                }
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
