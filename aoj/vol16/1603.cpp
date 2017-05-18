#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=110;
const int INF=123456789;

int n,p[100];
int dp1[N][50000],dp2[N][50000];

int main()
{
    while(scanf(" %d", &n),n)
    {
        rep(i,n) scanf(" %d", &p[i]);

        fill(dp1[0],dp1[N],-INF);
        fill(dp2[0],dp2[N],INF);

        dp1[0][0]=0;
        dp2[0][0]=0;
        rep(i,n)
        {
            rep(j,50000)
            {
                // 買う
                // 千円札しか出さない
                int r = (1000-p[i]%1000)%1000;
                int add=0;
                if(r>=500)
                {
                    add=1;
                    r-=500;
                }
                if(j+r<50000)
                {
                    if(dp1[i+1][j+r] < dp1[i][j]+add)
                    {
                        dp1[i+1][j+r] = dp1[i][j]+add;
                        dp2[i+1][j+r] = dp2[i][j]+p[i];
                    }
                    else if(dp1[i+1][j+r] == dp1[i][j]+add)
                    {
                        dp2[i+1][j+r] = min(dp2[i+1][j+r],dp2[i][j]+p[i]);
                    }
                }

                // 小銭も使う
                int need = p[i]%1000;
                if(need>=500) need-=500;
                else need+=500;
                if(need<=j)
                {
                    if(dp1[i+1][j-need] < dp1[i][j]+1)
                    {
                        dp1[i+1][j-need] = dp1[i][j]+1;
                        dp2[i+1][j-need] = dp2[i][j]+p[i];
                    }
                    else if(dp1[i+1][j-need] == dp1[i][j]+1)
                    {
                        dp2[i+1][j-need] = min(dp2[i+1][j-need],dp2[i][j]+p[i]);
                    }
                }

                // 買わない
                if(dp1[i+1][j] < dp1[i][j])
                {
                    dp1[i+1][j] = dp1[i][j];
                    dp2[i+1][j] = dp2[i][j];
                }
                else if(dp1[i+1][j] == dp1[i][j])
                {
                    dp2[i+1][j] = min(dp2[i+1][j],dp2[i][j]);
                }
            }
        }

        int x=0;
        rep(i,50000) x = max(x,dp1[n][i]);

        int y=INF;
        rep(i,50000)
        {
            if(dp1[n][i] == x) y = min(y,dp2[n][i]);
        }

        printf("%d %d\n", x,y);
    }
    return 0;
}
