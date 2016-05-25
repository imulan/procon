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
typedef pair<int,pi> P;

struct grid{int t,r,b,l;};

inline grid setg(char c)
{
    grid a;
    if(c=='+'){a.t=1; a.r=1; a.b=1; a.l=1;}
    else if(c=='-'){a.t=0; a.r=1; a.b=0; a.l=1;}
    else if(c=='|'){a.t=1; a.r=0; a.b=1; a.l=0;}
    else if(c=='^'){a.t=1; a.r=0; a.b=0; a.l=0;}
    else if(c=='>'){a.t=0; a.r=1; a.b=0; a.l=0;}
    else if(c=='<'){a.t=0; a.r=0; a.b=0; a.l=1;}
    else if(c=='v'){a.t=0; a.r=0; a.b=1; a.l=0;}
    else if(c=='L'){a.t=1; a.r=1; a.b=1; a.l=0;}
    else if(c=='R'){a.t=1; a.r=0; a.b=1; a.l=1;}
    else if(c=='U'){a.t=0; a.r=1; a.b=1; a.l=1;}
    else if(c=='D'){a.t=1; a.r=1; a.b=0; a.l=1;}
    else{a.t=0; a.r=0; a.b=0; a.l=0;}

    return a;
}

inline grid rotate(grid g)
{
    grid ret;
    ret.t=g.l;
    ret.r=g.t;
    ret.b=g.r;
    ret.l=g.b;
    return ret;
}

const int INF=99999999;

int n,m;
grid f[4][1000][1000];
int d[4][1000][1000];


inline bool inn(int x, int y)
{
    return (0<=x&&x<n && 0<=y&&y<m);
}

int main()
{
    scanf(" %d %d",&n,&m);

    vector<string> field(n);
    rep(i,n) cin >>field[i];

    int xt,yt,xm,ym;
    scanf(" %d %d",&xt,&yt);
    scanf(" %d %d",&xm,&ym);
    --xt;
    --yt;
    --xm;
    --ym;

    rep(i,n)rep(j,m) f[0][i][j]=setg(field[i][j]);

    for(int k=1; k<=3; ++k)rep(i,n)rep(j,m)
        f[k][i][j]=rotate(f[k-1][i][j]);

    //初期化
    rep(k,4)rep(i,n)rep(j,m) d[k][i][j]=INF;
    d[0][xt][yt]=0;
    queue<P> que;
    que.push(P(0,pi(xt,yt)));
    while(!que.empty())
    {
        P now = que.front();
        que.pop();

        int rot=now.fi;
        pi cur=now.se;

        //その場回転
        if(d[(rot+1)%4][cur.fi][cur.se]>d[rot][cur.fi][cur.se]+1)
        {
            d[(rot+1)%4][cur.fi][cur.se]=d[rot][cur.fi][cur.se]+1;
            que.push(P((rot+1)%4,cur));
        }

        int nx,ny;
        //上
        nx=cur.fi-1;
        ny=cur.se;
        if(inn(nx,ny))
        {
            if(f[rot][cur.fi][cur.se].t==1 && f[rot][nx][ny].b==1)
            {
                if(d[rot][nx][ny]>d[rot][cur.fi][cur.se]+1)
                {
                    d[rot][nx][ny]=d[rot][cur.fi][cur.se]+1;
                    que.push(P(rot,pi(nx,ny)));
                }
            }
        }

        //右
        nx=cur.fi;
        ny=cur.se+1;
        if(inn(nx,ny))
        {
            if(f[rot][cur.fi][cur.se].r==1 && f[rot][nx][ny].l==1)
            {
                if(d[rot][nx][ny]>d[rot][cur.fi][cur.se]+1)
                {
                    d[rot][nx][ny]=d[rot][cur.fi][cur.se]+1;
                    que.push(P(rot,pi(nx,ny)));
                }
            }
        }

        //下
        nx=cur.fi+1;
        ny=cur.se;
        if(inn(nx,ny))
        {
            if(f[rot][cur.fi][cur.se].b==1 && f[rot][nx][ny].t==1)
            {
                if(d[rot][nx][ny]>d[rot][cur.fi][cur.se]+1)
                {
                    d[rot][nx][ny]=d[rot][cur.fi][cur.se]+1;
                    que.push(P(rot,pi(nx,ny)));
                }
            }
        }

        //左
        nx=cur.fi;
        ny=cur.se-1;
        if(inn(nx,ny))
        {
            if(f[rot][cur.fi][cur.se].l==1 && f[rot][nx][ny].r==1)
            {
                if(d[rot][nx][ny]>d[rot][cur.fi][cur.se]+1)
                {
                    d[rot][nx][ny]=d[rot][cur.fi][cur.se]+1;
                    que.push(P(rot,pi(nx,ny)));
                }
            }
        }
    }

    int ans=INF;

    rep(i,4) ans=min(ans,d[i][xm][ym]);
    if(ans==INF) ans=-1;

    cout << ans << endl;
    return 0;
}
