#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=1010101010;
int dp[5001];
int nx[5001];
int min1[5001], min2[5001];

int main()
{
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    for(int i=1; i<n; ++i) scanf(" %d", &a[i]);

    fill(dp,dp+5001,INF);
    dp[0]=0;

    rep(i,n/2+1) min1[i]=dp[i];
    min2[0]=INF;
    for(int i=1; i<=n/2; ++i) min2[i]=dp[i-1];

    int ans=INF;

    for(int i=1; i<n; ++i)
    {
        rep(j,n/2+1) nx[j]=min(min1[j],min2[j])+a[i];

        rep(j,n/2+1) min1[j]=min(min1[j], nx[j]);
        for(int j=n/2; j>=1; --j) min2[j]=min(min2[j-1],nx[j-1]);

        rep(j,n/2+1) dp[j]=nx[j];

        ans=min(ans,dp[n/2]);
        if(n/2-n+i>=0) ans=min(ans,dp[n/2-n+i]);
    }

    printf("%d\n", ans);
    return 0;
}
