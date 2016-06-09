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

const ll INF=123456789012;

int main()
{
    int n,m;
    cin >>n >>m;

    vector<int> d(n),c(m);
    rep(i,n) scanf(" %d", &d[i]);
    rep(i,m) scanf(" %d", &c[i]);

    //今都市iにいる，j日目終了
    ll dp[1001][1001];
    fill(dp[0],dp[1001],INF);

    dp[0][0]=0;
    rep(j,m)
    {
        rep(i,n)
        {
            //次の都市へ移動
            dp[i+1][j+1]=min(dp[i+1][j],dp[i][j]+d[i]*c[j]);
            //待機
            dp[i][j+1]=min(dp[i][j+1],dp[i][j]);
        }
    }

    cout << dp[n][m] << endl;
    return 0;
}
