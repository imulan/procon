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

int w,h;

inline bool in(int x, int y)
{
    return (0<=x&&x<=(w+1) && 0<=y&&y<=(h+1));
}

int main()
{
    cin >>w >>h;

    //0:建物がない,1:建物がある,2:外が確定,3:内が確定
    int f[102][102];

    for(int i=1; i<=h; ++i)for(int j=1; j<=w; ++j) scanf(" %d", &f[j][i]);

    //外側を埋める
    rep(i,w+2) f[i][0]=f[i][h+1]=2;
    rep(i,h+2) f[0][i]=f[w+1][i]=2;

    int dy[6]={1,1,0,0,-1,-1};
    int dx[2][6]={{-1,0,-1,1,-1,0},{0,1,-1,1,0,1}};

    //外かどうか調べる
    for(int i=1; i<=h; ++i)for(int j=1; j<=w; ++j)
    {
        if(f[j][i]!=0) continue;

        bool out=false;

        int vis[102][102]={0};
        vis[j][i]=1;
        queue<pi> que;
        que.push(pi(j,i));

        while(!que.empty())
        {
            pi now=que.front();
            que.pop();
            rep(k,6)
            {
                int nx=now.fi+dx[now.se%2][k],ny=now.se+dy[k];

                if(!in(nx,ny)) continue;

                if(f[nx][ny]==2) out=true;
                if(f[nx][ny]==0 && !vis[nx][ny])
                {
                    vis[nx][ny]=1;
                    que.push(pi(nx,ny));
                }
            }
        }

        int num=3;
        if(out) num=2;

        rep(x,w+2)rep(y,h+2) if(vis[x][y]) f[x][y]=num;
    }

    int ans=0;
    for(int y=1; y<=h; ++y)for(int x=1; x<=w; ++x)
    {
        if(f[x][y]==1)
        {
            rep(i,6)
            {
                int nx=x+dx[y%2][i],ny=y+dy[i];
                if(f[nx][ny]==2) ++ans;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
