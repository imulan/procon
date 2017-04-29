#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

unordered_map<int,ll> dp[101];

int main()
{
    int n,W;
    cin >>n >>W;
    vector<int> w(n),v(n);
    rep(i,n) cin >>w[i] >>v[i];

    dp[0][0]=0;
    rep(i,n)
    {
        for(const auto &p:dp[i])
        {
            int j=p.fi;
            // printf("  j= %d, p.se=  %d\n", j,p.se);
            if(j+w[i]<=W) dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], p.se+v[i]);
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        }
    }

    ll ans=0;
    for(const auto &p:dp[n]) ans=max(ans,p.se);
    cout << ans << endl;
    return 0;
}
