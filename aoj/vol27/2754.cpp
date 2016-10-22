#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n,m;
int k[200], s[200][20], h[200][20];

double dp[201][201];
double dfs(int now, int r)
{
    if(now==n) return 0;
    if(dp[now][r]>=0) return dp[now][r];

    double ret=0;

    rep(i,r+1)
    {
        double add=0;
        int tr=i;
        rep(j,k[now])
        {
            int d=s[now][j]*h[now][j];
            if(tr-d<0)
            {
                add+=(double)tr/s[now][j];
                break;
            }

            tr-=d;
            add+=h[now][j];
        }
        ret=max(ret,dfs(now+1,r-i)+add);
    }

    return dp[now][r]=ret;
}

int main()
{
    scanf(" %d %d", &n, &m);
    rep(i,n)
    {
        scanf(" %d", &k[i]);
        rep(j,k[i]) scanf(" %d %d", &s[i][j], &h[i][j]);
    }

    fill(dp[0],dp[201],-1.0);
    printf("%.10f\n", dfs(0,m));
    return 0;
}
