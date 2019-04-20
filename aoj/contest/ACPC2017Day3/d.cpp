#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

const int INF = 12345678;
const int A = 10000;
int dp[101][A+1];

int main()
{
    int n,C;
    cin >>n >>C;
    vector<int> a(n),b(n),c(n);
    rep(i,n) cin >>a[i] >>b[i] >>c[i];

    fill(dp[0],dp[101],-INF);
    dp[0][0] = 0;
    rep(i,n)
    {
        for(int cost=C; cost>=0; --cost)
        {
            if(cost+c[i]<=C)
            {
                int nx = cost+c[i];
                rep(j,A+1)
                {
                    dp[nx][min(A,j+a[i])] = max(dp[nx][min(A,j+a[i])], dp[cost][j]+b[i]);
                    dp[nx][min(A,j+b[i])] = max(dp[nx][min(A,j+b[i])], dp[cost][j]+a[i]);
                }
            }
        }
    }

    int ans = 0;
    rep(i,C+1)rep(j,A+1)
    {
        ans = max(ans,min(j,dp[i][j]));
    }

    cout << ans << endl;
}
