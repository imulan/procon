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

const ll INF=1234567890;

int main()
{
    int m,n;
    cin >>m >>n;

    vector<int> p(m);
    rep(i,m) cin >>p[i];
    sort(all(p),greater<int>());

    vector<int> c(n),e(n);
    rep(i,n) cin >>c[i] >>e[i];

    //饅頭i個入れるために必要な箱を買う金額の最小値
    ll dp[10001];
    fill(dp,dp+10001,INF);
    dp[0]=0;

    rep(i,n)for(int j=m; j>=0; --j)
    {
        //箱iを買う
        int nx=j+c[i];
        if(nx>m) nx=m;
        dp[nx]=min(dp[nx],dp[j]+e[i]);
    }

    //最小値を更新していく
    ll a=INF;
    for(int i=m; i>=0; --i)
    {
        a=min(a,dp[i]);
        dp[i]=min(dp[i],a);
    }

    //饅頭をi個売る時の売上
    vector<ll> ben(m+1,0);
    for(int i=1; i<=m; ++i) ben[i]=ben[i-1]+p[i-1];

    ll ans=0;
    //饅頭をi個売る時
    rep(i,m+1) ans=max(ans,ben[i]-dp[i]);

    cout << ans << endl;
    return 0;
}
