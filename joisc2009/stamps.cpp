#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n;

const int N=1000001;
const int INF=123456789;
int dp[N][2];
int par[2*N];

int main()
{
    scanf(" %d", &n);

    fill(par,par+2*N,-1);
    fill(dp[0],dp[N],INF);
    dp[0][1]=0;

    dp[0][0]=1;
    par[0] = 1;

    rep(i,n)
    {
        char c;
        scanf(" %c", &c);

        // 編集
        if(c=='I')
        {
            rep(j,2)
            {
                if(dp[i+1][j]>=dp[i][!j]+j)
                {
                    dp[i+1][j] = dp[i][!j]+j;
                    par[2*(i+1)+j] = 2*i+(!j);
                }
            }
        }
        else
        {
            rep(j,2)
            {
                if(dp[i+1][j]>=dp[i][!j]+(!j))
                {
                    dp[i+1][j] = dp[i][!j]+(!j);
                    par[2*(i+1)+j] = 2*i+(!j);
                }
            }
        }

        // 挿入
        rep(j,2)
        {
            if(dp[i+1][j]>=dp[i][j]+1)
            {
                dp[i+1][j]=dp[i][j]+1;
                par[2*(i+1)+j] = 2*i+j;
            }
        }
    }

    int now = 2*n;
    int ans = 0;
    while(now!=1)
    {
        int p = par[now];
        // printf(" %d %d\n", p/2,p%2);

        if(p==0)
        {
            ++ans;
            break;
        }

        if(now%2 == p%2) ++ans;

        now = p;
    }

    printf("%d\n%d\n", dp[n][0],n-ans);
    return 0;
}
