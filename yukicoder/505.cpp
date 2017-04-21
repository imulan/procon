#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF=LLONG_MAX/4;
ll dp[16][2];

int main()
{
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    rep(i,n)
    {
        dp[i][0]=-INF;
        dp[i][1]=INF;
    }

    dp[0][0]=dp[0][1]=a[0];
    for(int i=1; i<n; ++i)
    {
        rep(j,2)
        {
            dp[i][0]=max(dp[i][0], dp[i-1][j]+a[i]);
            dp[i][1]=min(dp[i][1], dp[i-1][j]+a[i]);

            dp[i][0]=max(dp[i][0], dp[i-1][j]-a[i]);
            dp[i][1]=min(dp[i][1], dp[i-1][j]-a[i]);

            dp[i][0]=max(dp[i][0], dp[i-1][j]*a[i]);
            dp[i][1]=min(dp[i][1], dp[i-1][j]*a[i]);

            if(a[i]!=0)
            {
                dp[i][0]=max(dp[i][0], dp[i-1][j]/a[i]);
                dp[i][1]=min(dp[i][1], dp[i-1][j]/a[i]);
            }
        }
    }

    cout << dp[n-1][0] << endl;
    return 0;
}
