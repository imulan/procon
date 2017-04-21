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

int f[1001][1001];
int ct[1001][1001];

int main()
{
    int H,W,N;
    while(scanf(" %d %d %d", &H, &W, &N),H)
    {
        rep(i,H)rep(j,W) scanf(" %d", &f[i][j]);
        #define IN(x,y) (0<=x && x<W && 0<=y && y<H)

        memset(ct,0,sizeof(ct));
        ct[0][0]=N-1;

        int dx[2]={0,1}, dy[2]={1,0};
        rep(s,H+W+1)
        {
            int l=max(0,s-H), r=min(W-1,s);
            for(int x=l; x<=r; ++x)
            {
                int y=s-x;
                rep(i,2)
                {
                    int nx=x+dx[i], ny=y+dy[i];
                    if(!IN(nx,ny)) continue;

                    int nct=ct[y][x]/2;
                    if(ct[y][x]%2==1 && f[y][x]==i) ++nct;

                    ct[ny][nx]+=nct;
                }
            }
        }

        int X=0,Y=0;
        while(IN(X,Y))
        {
            int d=(f[Y][X]+ct[Y][X])%2;
            X+=dx[d];
            Y+=dy[d];
        }
        printf("%d %d\n", Y+1,X+1);
    }
    return 0;
}
