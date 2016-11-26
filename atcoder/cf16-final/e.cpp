#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

vector<ll> factor(ll n)
{
    vector<ll> ret;

    for(ll i=1; i*i<=n; ++i)
    {
        if(n%i==0)
        {
            ret.pb(i);
            if(i != n/i) ret.pb(n/i);
        }
    }
    sort(all(ret));

    return ret;
}

const int D_MAX=1000001;
const ll INF=123456789012345LL;
ll dp[D_MAX];

int main()
{
    ll N,A;
    cin >>N >>A;

    // vector<ll> d = factor(N);
    // int D=d.size();

    fill(dp,dp+D_MAX,INF);
    dp[1]=0;
    for(int i=1; i<=N; ++i)
    {
        for(int j=2; j*i<=N; ++j)
        {
            ll T=dp[i]+j+A;
            dp[j*i] = min(dp[j*i],T);
        }
    }

    ll ans=INF;
    for(int i=1; i<=N; ++i)
    {
        ll cost=dp[i]+(N+i-1)/i;
        ans=min(ans,cost);
    }

    cout << ans << endl;
    return 0;
}
