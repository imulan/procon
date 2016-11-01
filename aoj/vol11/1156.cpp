#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=12345678;

struct state{ int x,y,d; };

int main()
{
    int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};

    int w,h;
    while(cin >>w >>h,w)
    {
        int s[30][30];
        int c[4];

        rep(i,h)rep(j,w) scanf(" %d", &s[i][j]);
        rep(i,4) scanf(" %d", &c[i]);

        int dist[30][30][4];
        rep(i,30)rep(j,30)rep(k,4) dist[i][j][k]=INF;
        dist[0][0][1]=0;
        queue<state> que;
        que.push(state{0,0,1});
        #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
        while(!que.empty())
        {
            state now=que.front();
            que.pop();
            if(now.x==w-1 && now.y==h-1) continue;

            rep(i,4)
            {
                int cost=c[i];
                if(s[now.y][now.x]==i) cost=0;

                int nd=(now.d+i)%4;
                int nx=now.x+dx[nd], ny=now.y+dy[nd];
                if(IN(nx,ny) && dist[ny][nx][nd]>dist[now.y][now.x][now.d]+cost)
                {
                    dist[ny][nx][nd]=dist[now.y][now.x][now.d]+cost;
                    que.push(state{nx,ny,nd});
                }
            }
        }

        int ans=INF;
        rep(i,4) ans=min(ans,dist[h-1][w-1][i]);
        printf("%d\n", ans);
    }
    return 0;
}
