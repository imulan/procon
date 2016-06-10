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

//左上を(1,1),右下を(i,j)とした時に含まれるJOIの数
int dp[1001][1001][3]={0};

int main()
{
    string joi="JOI";
    int m,n,q;
    cin >>m >>n >>q;

    vector<string> f(m);
    rep(i,m) cin >>f[i];

    for(int i=1; i<=m; ++i)rep(j,3)
    {
        dp[i][1][j]=dp[i-1][1][j];
        if(f[i-1][0]==joi[j]) ++dp[i][1][j];
    }
    for(int i=1; i<=n; ++i)rep(j,3)
    {
        dp[1][i][j]=dp[1][i-1][j];
        if(f[0][i-1]==joi[j]) ++dp[1][i][j];
    }

    for(int i=2; i<=m; ++i)for(int j=2; j<=n; ++j)rep(k,3)
    {
        dp[i][j][k]=dp[i-1][j][k]+dp[i][j-1][k]-dp[i-1][j-1][k];
        if(f[i-1][j-1]==joi[k]) ++dp[i][j][k];
    }

    rep(Q,q)
    {
        int a,b,c,d;
        scanf(" %d %d %d %d", &a, &b, &c, &d);
        rep(i,3)
        {
            if(i)printf(" ");
            printf("%d", dp[c][d][i]-dp[a-1][d][i]-dp[c][b-1][i]+dp[a-1][b-1][i]);
        }
        printf("\n");
    }

    return 0;
}
