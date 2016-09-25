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
    int h,w;
    cin >>h >>w;

    int sx,sy,gx,gy;
    cin >>sx >>sy >>gx >>gy;

    pi s=pi(sx-1, sy-1), g=pi(gx-1, gy-1);

    vector<string> b(h);
    rep(i,h) cin >>b[i];

    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
    #define IN(x,y) (0<=x && x<w && 0<=y && y<h)

    vector<vector<bool>> vis(h, vector<bool>(w,false));
    queue<pi> que;
    que.push(s);
    vis[s.fi][s.se]=true;

    while(!que.empty())
    {
        pi now=que.front();
        que.pop();

        // printf(" visit %d %d\n", now.fi,now.se);

        // 1マス隣
        rep(i,4)
        {
            int nx=now.se+dx[i], ny=now.fi+dy[i];
            if(IN(nx,ny) && abs(b[now.fi][now.se]-b[ny][nx])<=1 && !vis[ny][nx])
            {
                vis[ny][nx]=true;
                que.push(pi(ny,nx));
            }
        }

        // 2マス隣
        rep(i,4)
        {
            int nx=now.se+2*dx[i], ny=now.fi+2*dy[i];
            int tx=now.se+dx[i], ty=now.fi+dy[i];

            if(IN(nx,ny) && IN(tx,ty) && b[now.fi][now.se]-b[ny][nx]==0 && b[ty][tx]<b[ny][nx] && !vis[ny][nx])
            {
                vis[ny][nx]=true;
                que.push(pi(ny,nx));
            }
        }
    }

    string ans="NO";
    if(vis[g.fi][g.se]) ans="YES";
    cout << ans << endl;
    return 0;
}
