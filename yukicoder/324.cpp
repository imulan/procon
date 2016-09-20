#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=12345678;
int dp[3001][3001][2][2];

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> w(n);
    rep(i,n) scanf(" %d", &w[i]);

    if(m==0) printf("0\n");
    else
    {
        rep(i,3001)rep(j,3001)rep(k,2)rep(l,2) dp[i][j][k][l]=-INF;
        dp[0][0][0][0]=0;
        dp[0][1][1][1]=0;

        rep(i,n-1)rep(j,m+1)
        {
            // i番目を選ばない
            rep(before,2)rep(one,2) dp[i+1][j][0][one] = max(dp[i+1][j][0][one], dp[i][j][before][one]);

            // 選ぶ
            if(j<m)
            {
                rep(before,2)rep(one,2)
                {
                    int add=0;
                    if(before) add+=w[i];
                    if(i==n-2 && one) add+=w[n-1];
                    dp[i+1][j+1][1][one] = max(dp[i+1][j+1][1][one], dp[i][j][before][one]+add);
                }
            }
        }

        int ans=-INF;
        rep(i,2)rep(j,2) ans=max(ans,dp[n-1][m][i][j]);
        printf("%d\n", ans);
    }
    return 0;
}
