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

int w,h;
string s[1000];
int n;
int x[1000],y[1000];
bool wall[1000];

int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

#define IN(x,y) (0<=x && x<w && 0<=y && y<h)
int vis[1000][1000];
bool check(int q)
{
    rep(i,q) s[y[i]][x[i]]='.';
    memset(vis,0,sizeof(vis));

    bool ret=false;

    queue<pi> que;
    que.push(pi(0,0));
    vis[0][0]=true;
    while(!que.empty())
    {
        pi now=que.front();
        que.pop();

        if(s[now.fi][now.se]=='t')
        {
            ret=true;
            break;
        }

        rep(i,4)
        {
            int nx=now.se+dx[i], ny=now.fi+dy[i];
            if(IN(nx,ny) && s[ny][nx]!='#' && !vis[ny][nx])
            {
                vis[ny][nx]=1;
                que.push(pi(ny,nx));
            }
        }
    }

    rep(i,q) if(wall[i]) s[y[i]][x[i]]='#';
    return ret;
}

int main()
{
    while(cin >>w >>h)
    {
        rep(i,h) cin >>s[i];
        cin >>n;
        rep(i,n)
        {
            cin >>x[i] >>y[i];
            wall[i]=(s[y[i]][x[i]]=='#');
        }

        if(check(0))
        {
            printf("0\n");
            continue;
        }

        int l=0, r=n+1;
        while(r-l>1)
        {
            int m=(l+r)/2;

            if(check(m)) r=m;
            else l=m;
        }

        if(r==n+1) r=-1;
        printf("%d\n", r);
    }
    return 0;
}
