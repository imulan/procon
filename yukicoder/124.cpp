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
typedef pair<pi,pi> P;

inline bool check(int x, int y, int z)
{
    //まだ3つ揃っていない
    if(x==0) return true;
    //判定
    if(x==y || y==z || z==x) return false;
    if((x<y&&y>z)||(x>y&&y<z)) return true;
    return false;
}

const int INF=12345678;
int cost[100][100][10][10];

int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int main()
{
    int w,h;
    int m[100][100];

    cin >>w >>h;
    rep(i,h)rep(j,w) cin >>m[i][j];

    rep(a,100)rep(b,100)rep(c,10)rep(d,10) cost[a][b][c][d]=INF;
    cost[0][0][0][m[0][0]]=0;

    queue<P> que;
    que.push(P(pi(0,0),pi(0,m[0][0])));
    while(!que.empty())
    {
        P p=que.front();
        que.pop();

        //現在位置
        pi now=p.fi;
        //(2つ前,1つ前)
        pi prev=p.se;

        // printf("now=%d,%d ::: prev=%d,%d\n", now.fi,now.se,prev.fi,prev.se);

        //4近傍
        rep(i,4)
        {
            int nx=now.fi+dx[i], ny=now.se+dy[i];
            if(0<=nx&&nx<w && 0<=ny&&ny<h)
            {
                pi nxprev(prev.se,m[ny][nx]);

                if(check(prev.fi,prev.se,m[ny][nx]) && cost[ny][nx][nxprev.fi][nxprev.se] > cost[now.se][now.fi][prev.fi][prev.se]+1)
                {
                    cost[ny][nx][nxprev.fi][nxprev.se] = cost[now.se][now.fi][prev.fi][prev.se]+1;
                    que.push(P(pi(nx,ny),nxprev));
                }
            }
        }
    }

    int ans=INF;
    rep(i,10)rep(j,10) ans=min(ans,cost[h-1][w-1][i][j]);
    if(ans==INF) ans=-1;
    cout << ans << endl;
    return 0;
}
