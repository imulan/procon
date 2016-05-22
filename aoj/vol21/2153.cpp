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

const int INF=12345678;

int w,h;
int d[50][50][50][50];

inline bool in(int x, int y)
{
    return (0<=x&&x<w && 0<=y&&y<h);
}

int main()
{
    int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};

    while(cin >>w >>h,w|h)
    {
        vector<string> l(h),r(h);
        rep(i,h) cin >>l[i] >>r[i];

        pi len,rin;
        pi gl,gr;
        rep(i,h)rep(j,w)
        {
            if(l[i][j]=='L') len=pi(j,i);
            if(r[i][j]=='R') rin=pi(j,i);
            if(l[i][j]=='%') gl=pi(j,i);
            if(r[i][j]=='%') gr=pi(j,i);
        }

        //len(x,y),rin(x,y)
        rep(a1,50)rep(a2,50)rep(a3,50)rep(a4,50) d[a1][a2][a3][a4]=INF;
        d[len.fi][len.se][rin.fi][rin.se]=0;

        queue<P> que;
        que.push(P(len,rin));
        while(!que.empty())
        {
            P now=que.front();
            que.pop();

            pi nl=now.fi, nr=now.se;

            rep(i,4)
            {
                int nlx=nl.fi+dx[i], nly=nl.se+dy[i];
                int nrx=nr.fi-dx[i], nry=nr.se+dy[i];

                if(!in(nlx,nly) || (in(nlx,nly)&&l[nly][nlx]=='#'))
                {
                    //not move
                    nlx=nl.fi;
                    nly=nl.se;
                }

                if(!in(nrx,nry) || (in(nrx,nry)&&r[nry][nrx]=='#'))
                {
                    //not move
                    nrx=nr.fi;
                    nry=nr.se;
                }

                if(l[nly][nlx]=='%' && r[nry][nrx]!='%') continue;
                if(l[nly][nlx]!='%' && r[nry][nrx]=='%') continue;

                if(d[nlx][nly][nrx][nry]>d[nl.fi][nl.se][nr.fi][nr.se]+1)
                {
                    d[nlx][nly][nrx][nry]=d[nl.fi][nl.se][nr.fi][nr.se]+1;
                    que.push(P(pi(nlx,nly),pi(nrx,nry)));
                }
            }
        }

        puts((d[gl.fi][gl.se][gr.fi][gr.se]<INF)?"Yes":"No");
    }
    return 0;
}
