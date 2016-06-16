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

int main()
{
    int n;
    int A[101][101]={0};
    int dp[101][101]={0};

    cin >>n;
    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
    scanf(" %d", &A[i][j]);

    dp[1][1]=A[1][1];

    for(int i=2; i<=n; ++i) dp[1][i]=dp[1][i-1]+A[1][i];

    for(int i=2; i<=n; ++i) dp[i][1]=dp[i-1][1]+A[i][1];

    for(int i=2; i<=n; ++i)
    for(int j=2; j<=n; ++j)
    dp[i][j]=A[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];

/*
    for(int i=1; i<=n; ++i)
    {
        for(int j=1; j<=n; ++j)printf(" %d", dp[i][j]);
        printf("\n");
    }
*/
    int ans=-10000;

    for(int i=1; i<=n; ++i)
    for(int j=1; j<=n; ++j)
    ans=max(ans,A[i][j]);

    for(int a=1; a<=n; ++a)
    for(int b=1; b<=n; ++b)
    for(int c=a; c<=n; ++c)
    for(int d=b; d<=n; ++d)
    {
        int t=dp[c][d]-dp[a-1][d]-dp[c][b-1]+dp[a-1][b-1];
        ans=max(ans,t);
    }

    cout << ans << endl;
    return 0;
}
