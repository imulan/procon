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

bool inline in(int x, int y)
{
    return (0<=x&&x<3 && 0<=y&&y<3);
}

int main()
{
    int n;
    int dx[]={1,-1,0,0}, dy[]={0,0,1,-1};
    while(cin >>n,n)
    {
        char s,t,b;
        scanf(" %c %c %c",&s,&t,&b);

        pi S((s-'A')/3,(s-'A')%3);
        pi T((t-'A')/3,(t-'A')%3);
        pi B((b-'A')/3,(b-'A')%3);

        //(j,i)にいる確率
        double dp[3][3]={0};

        dp[S.fi][S.se]=1;
        rep(i,n)
        {
            double newdp[3][3]={0};
            //現在位置(x,y)
            rep(y,3)rep(x,3)
            {
                rep(j,4)
                {
                    int nx=x+dx[j], ny=y+dy[j];
                    if(in(nx,ny) && B!=pi(ny,nx))
                    {
                        //移動
                        newdp[ny][nx]+=dp[y][x]/4;
                    }
                    else
                    {
                        //とどまる
                        newdp[y][x]+=dp[y][x]/4;
                    }
                }
            }

            memcpy(dp,newdp,sizeof(newdp));
        }

        printf("%.10lf\n", dp[T.fi][T.se]);
    }
    return 0;
}
