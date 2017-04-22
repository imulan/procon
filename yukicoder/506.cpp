#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll mod=1e9+7;
ll dp[33][33];
int ban[33][33];

int main()
{
    int H,W,K,P;
    cin >>H >>W >>K >>P;

    vector<int> x(K),y(K);
    vector<string> N(K);
    rep(i,K) cin >>x[i] >>y[i] >>N[i];

    ll ans=0;
    vector<string> s;
    rep(mask,1<<K)
    {
        if(__builtin_popcount(mask) != P) continue;

        fill(ban[0],ban[33],0);
        rep(i,K)
        {
            if(!(mask>>i&1)) ban[x[i]][y[i]]=1;

        }

        fill(dp[0],dp[33],0);
        if(!ban[0][0]) dp[0][0]=1;
        for(int i=1; i<=H; ++i)if(!ban[i][0]) dp[i][0] = dp[i-1][0];
        for(int i=1; i<=W; ++i)if(!ban[0][i]) dp[0][i] = dp[0][i-1];

        for(int i=1; i<=H; ++i)for(int j=1; j<=W; ++j)
        {
            if(!ban[i][j]) dp[i][j] = dp[i-1][j]+dp[i][j-1];
        }

        if(dp[H][W]>ans)
        {
            ans = dp[H][W];
            s.clear();
            rep(i,K)if(mask>>i&1) s.pb(N[i]);
        }
    }

    // output
    cout << ans%mod << endl;
    for(const auto &name:s) cout << name << endl;
    return 0;
}
