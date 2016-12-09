#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=123456789;
int dp[101][100001];
int min_cost[100001];

int main()
{
    int C,N;
    scanf(" %d %d", &C, &N);
    vector<int> a(N);
    rep(i,N) scanf(" %d", &a[i]);

    fill(dp[0],dp[101],INF);
    dp[0][0]=0;
    for(int i=1; i<=N; ++i)
    {
        rep(j,a[i-1])
        {
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            min_cost[j]=dp[i-1][j];
        }

        for(int j=a[i-1]; j<=C; ++j)
        {
            int idx=j%a[i-1];
            ++min_cost[idx];
            min_cost[idx] = min(min_cost[idx], dp[i-1][j]);
            dp[i][j] = min(dp[i][j],min_cost[idx]);
        }
    }

    int ans=dp[N][C];
    if(ans==INF) ans=-1;
    printf("%d\n", ans);
    return 0;
}
