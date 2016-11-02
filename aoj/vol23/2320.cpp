#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct state{ int x,y,d; };

state memo[44444];

int main()
{
    int dx[4]={0,1,0,-1}, dy[4]={-1,0,1,0};

    int h,w;
    ll L;
    while(cin >>h >>w >>L,h)
    {
        vector<string> c(h);
        rep(i,h) cin >>c[i];

        ll v[100][100][4];
        memset(v,-1,sizeof(v));

        int x=0,y=0,d=0;
        rep(i,h)rep(j,w)
        {
            if(c[i][j]!='.' && c[i][j]!='#')
            {
                x=j;
                y=i;
                if(c[i][j]=='N') d=0;
                else if(c[i][j]=='E') d=1;
                else if(c[i][j]=='S') d=2;
                else if(c[i][j]=='W') d=3;
                break;
            }
        }

        ll cycle=0;
        ll pre=0;

        ll now=1;
        v[y][x][d]=0;
        memo[0]=state{x,y,d};
        #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
        bool cantmove=true;
        while(1)
        {
            cantmove=true;
            rep(i,4)
            {
                int nx=x+dx[d], ny=y+dy[d];
                if(IN(nx,ny) && c[ny][nx]!='#')
                {
                    cantmove=false;
                    x=nx;
                    y=ny;
                    break;
                }
                d=(d+1)%4;
            }

            if(cantmove) break;

            // printf("y,x,d(%d,%d,%d) : %lld\n", y,x,d,now);

            if(v[y][x][d]>0)
            {
                pre=v[y][x][d];
                cycle=now-v[y][x][d];
                break;
            }

            v[y][x][d]=now;
            memo[now]=state{x,y,d};
            if(now==L) break;
            ++now;
        }

        if(!cantmove && now<L)
        {
            L-=pre;
            ll X=L/cycle;
            ll Y=L-X*cycle;
            // printf("cycle= %lld: pre,X,Y %lld,%lld,%lld\n", cycle, pre,X,Y);

            state final=memo[pre+Y];
            x=final.x;
            y=final.y;
            d=final.d;
        }

        string NESW="NESW";
        printf("%d %d %c\n", y+1, x+1, NESW[d]);
    }
    return 0;
}
