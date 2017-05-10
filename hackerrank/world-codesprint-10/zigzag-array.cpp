#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=1234;
int dp[101][101][101];

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    rep(i,101)rep(j,101)rep(k,101) dp[i][j][k]=INF;

    dp[0][0][0]=0;
    rep(i,n)
    {
        dp[i+1][0][0] = min(dp[i+1][0][0],dp[i][0][0]+1);

        dp[i+1][a[i]][0] = min(dp[i+1][a[i]][0],dp[i][0][0]);
        for(int j=1; j<=100; ++j)
        {
            dp[i+1][j][0] = min(dp[i+1][j][0],dp[i][j][0]+1);
            if(a[i]!=j) dp[i+1][a[i]][j] = min(dp[i+1][a[i]][j],dp[i][j][0]);
        }

        for(int j=1; j<=100; ++j)for(int k=1; k<=100; ++k)if(j!=k)
        {
            dp[i+1][j][k] = min(dp[i+1][j][k],dp[i][j][k]+1);
            if(k<j)
            {
                if(j>a[i]) dp[i+1][a[i]][j] = min(dp[i+1][a[i]][j], dp[i][j][k]);
            }
            else
            {
                if(j<a[i]) dp[i+1][a[i]][j] = min(dp[i+1][a[i]][j], dp[i][j][k]);
            }
        }
    }

    int ans=INF;
    rep(i,101)rep(j,101) ans=min(ans,dp[n][i][j]);
    cout << ans << endl;
    return 0;
}
