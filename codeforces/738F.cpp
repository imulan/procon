#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF = 500000000;

int n,a[4001];

int suma[4001]={};
int sigma_a(int l, int r)
{
    return suma[r]-suma[l-1];
}

int dp[4001][180][90][2];
int dfs(int l, int d, int k, int turn)
{
    if(abs(dp[l][d+90][k][turn])!=INF) return dp[l][d+90][k][turn];

    int r = n-d-l+1;

    int ret;
    int nd;
    if(turn==0)
    {
        ret = -INF;

        nd = n-r-(l+k-1);
        if(l+k<=r+1) ret = max(ret, dfs(l+k,nd,k,1) + sigma_a(l,l+k-1));

        nd = n-r-(l+k+1-1);
        if(l+k+1<=r+1) ret = max(ret, dfs(l+k+1,nd,k+1,1) + sigma_a(l,l+k));
    }
    else
    {
        ret = INF;

        nd = n-(r-k)-(l-1);
        if(l<=r-k+1) ret = min(ret, dfs(l,nd,k,0) - sigma_a(r-k+1,r));

        nd = n-(r-k-1)-(l-1);
        if(l<=r-k-1+1) ret = min(ret, dfs(l,nd,k+1,0) - sigma_a(r-k,r));
    }

    if(abs(ret)==INF) ret=0;
    return dp[l][d+90][k][turn] = ret;
}

void init()
{
    rep(i,4001)rep(j,180)rep(k,90)
    {
        dp[i][j][k][0] = -INF;
        dp[i][j][k][1] = INF;
    }

    for(int i=1; i<=4000; ++i) suma[i] = suma[i-1]+a[i];
}

int main()
{
    scanf(" %d", &n);
    rep(i,n) scanf(" %d", &a[i+1]);

    init();
    printf("%d\n", dfs(1,0,1,0));
    return 0;
}
