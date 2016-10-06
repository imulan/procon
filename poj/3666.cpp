#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF=123456789012345LL;
ll dp[2001][2001];

int n;
int a[2000];

ll solve()
{
    vector<int> x(n);
    rep(i,n) x[i]=a[i];
    sort(all(x));
    x.erase(unique(all(x)),x.end());
    int X=x.size();

    rep(i,n) dp[0][i]=abs(a[0]-x[i]);

    for(int i=1; i<n; ++i)
    {
        dp[i][0] = dp[i-1][0]+abs(a[i]-x[0]);
        ll value = dp[i-1][0];
        for(int j=1; j<X; ++j)
        {
            dp[i][j] = min(dp[i-1][j], value)+abs(a[i]-x[j]);
            value = min(value, dp[i-1][j]);
        }
    }

    ll ret=INF;
    rep(i,X) ret=min(ret, dp[n-1][i]);
    return ret;
}

int main()
{
    scanf(" %d", &n);
    rep(i,n) scanf(" %d", &a[i]);

    ll ans=solve();
    rep(i,n) a[i] = -a[i];
    ans=min(ans,solve());

    cout << ans << endl;
    return 0;
}
