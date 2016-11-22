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
typedef pair<pi,pi> P;

const int INF=123456789;
int d[50][50];
int c[50][50][50][50];

int dx[4]={1,0,-1,0}, dy[4]={0,1,0,-1};

void init()
{
    rep(i,50)rep(j,50)rep(k,50)rep(l,50) c[i][j][k][l]=INF;
}

int main()
{
    int w,h;
    while(scanf(" %d %d",&w,&h),w)
    {
        init();

        pi tk,kz;
        scanf(" %d %d", &tk.se, &tk.fi);
        scanf(" %d %d", &kz.se, &kz.fi);
        --tk.fi; --tk.se;
        --kz.fi; --kz.se;

        rep(i,h)rep(j,w) scanf(" %d", &d[i][j]);

        queue<P> que;
        que.push(P(tk,kz));
        c[tk.fi][tk.se][kz.fi][kz.se]=0;
        #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
        while(!que.empty())
        {
            P now=que.front(); que.pop();
            pi a=now.fi, b=now.se;

            rep(i,4)
            {
                int ax=a.se+dx[i], ay=a.fi+dy[i];
                int bx=b.se+dx[i^2], by=b.fi+dy[i^2];

                if(!IN(ax,ay) || d[ay][ax]==1)
                {
                    ax=a.se;
                    ay=a.fi;
                }
                if(!IN(bx,by) || d[by][bx]==1)
                {
                    bx=b.se;
                    by=b.fi;
                }

                if(c[ay][ax][by][bx]>c[a.fi][a.se][b.fi][b.se]+1)
                {
                    c[ay][ax][by][bx]=c[a.fi][a.se][b.fi][b.se]+1;
                    que.push(P(pi(ay,ax),pi(by,bx)));
                }
            }
        }

        int ans=INF;
        rep(i,h)rep(j,w) ans=min(ans,c[i][j][i][j]);
        if(ans==INF) printf("NA\n");
        else printf("%d\n", ans);
    }
    return 0;
}
