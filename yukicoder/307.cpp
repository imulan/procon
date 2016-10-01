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
    int a[200][200];
    scanf(" %d %d", &h, &w);
    rep(i,h)rep(j,w) scanf(" %d", &a[i][j]);

    #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

    // クエリ処理
    bool all_done=false;
    int col=-1;

    int Q;
    scanf(" %d", &Q);

    while(Q--)
    {
        int r,c,x;
        scanf(" %d %d %d", &r, &c, &x);
        --r;
        --c;

        if(all_done)
        {
            col=x;
            continue;
        }

        if(a[r][c]==x) continue;

        queue<pi> que;
        que.push(pi(r,c));
        int vis_num=1;
        a[r][c]=x;
        while(!que.empty())
        {
            pi now=que.front();
            que.pop();
            rep(i,4)
            {
                int nx=now.se+dx[i], ny=now.fi+dy[i];
                if(IN(nx,ny) && a[ny][nx]!=x)
                {
                    a[ny][nx]=x;
                    que.push(pi(ny,nx));
                    ++vis_num;
                }
            }
        }

        if(vis_num==h*w)
        {
            all_done=true;
            col=x;
        }
    }

    // 出力
    rep(y,h)
    {
        rep(x,w)
        {
            if(x) printf(" ");
            if(all_done) a[y][x]=col;
            printf("%d", a[y][x]);
        }
        printf("\n");
    }
    return 0;
}
