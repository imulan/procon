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

const ll INF=123456789012345LL;

int main()
{
    int n,m;
    ll k;
    cin >>n >>m >>k;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    ll dp[20001];
    fill(dp,dp+n+1,INF);
    dp[0]=0;

    //始点i
    rep(i,n)
    {
        ll x=0, y=1234567890LL;
        //終点j
        for(int j=i; j<min(n,i+m); ++j)
        {
            x=max(x,a[j]);
            y=min(y,a[j]);
            int s=j-i+1;

            dp[j+1]=min(dp[j+1],dp[i]+k+s*(x-y));
        }
    }

    cout << dp[n] << endl;
    return 0;
}
