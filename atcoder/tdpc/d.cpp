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

//2,3,5の素因数の数
double dp[100][100][100];
double newdp[100][100][100];


int main()
{
    int n;
    ll d;
    cin >>n >>d;

    int X=0,Y=0,Z=0;
    while(d%2==0){d/=2; ++X;}
    while(d%3==0){d/=3; ++Y;}
    while(d%5==0){d/=5; ++Z;}

    if(d>1) printf("0\n");
    else
    {
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;

        int add[7][3]={0};
        add[2][0]=1;
        add[3][1]=1;
        add[4][0]=2;
        add[5][2]=1;
        add[6][0]=1;
        add[6][1]=1;

        //サイコロi個目
        rep(i,n)
        {
            memset(newdp,0,sizeof(newdp));
            //jの目が出るとき
            for(int j=1; j<=6; ++j)
            {
                rep(x,X+1)rep(y,Y+1)rep(z,Z+1)
                {
                    int nx=min(x+add[j][0],X);
                    int ny=min(y+add[j][1],Y);
                    int nz=min(z+add[j][2],Z);
                    //printf("now %d: (%d,%d,%d) -> (%d,%d,%d) add %lf\n", j,x,y,z,nx,ny,nz, dp[x][y][z]/6.0);
                    newdp[nx][ny][nz]+=dp[x][y][z]/6.0;
                }
            }

            rep(x,100)rep(y,100)rep(z,100) dp[x][y][z]=newdp[x][y][z];
        }

        printf("%.10lf\n", dp[X][Y][Z]);
    }
    return 0;
}
