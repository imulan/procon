#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll mod=1e9+7;

using pi = pair<int,int>;

struct Hash{
    size_t operator()(const pi &p) const {
        return (p.fi<<12) + p.se;
    }
};

unordered_map<pi,ll,Hash> dp[3010];

ll a[3010][3010]={};
ll ans[3010][3010]={};

ll fact(ll n)
{
    ll ret=1;
    for(ll i=1; i<=n; ++i) (ret*=i)%=mod;
    return ret;
}

int main()
{
    dp[0][pi(0,0)]=1;
    rep(i,3001)
    {
        for(const auto &p:dp[i])
        {
            int j=p.fi.fi, k=p.fi.se;

            (dp[i+1][pi(j+1,k)] += k*p.se)%=mod;
            (dp[i+1][pi(j,k+2)] += (i+1-k)*p.se)%=mod;
        }
    }

    int ct=0;
    rep(i,3001)
    {
        for(const auto &p:dp[i])
        {
            int j=p.fi.fi;
            (a[i][j]+=p.se)%=mod;
            ++ct;
        }
    }
    // printf("ct = %d\n", ct);

    rep(i,3010)
    {
        ans[i][3009]=a[i][3009];
        for(int j=3008; j>=0; --j) ans[i][j]=(ans[i][j+1]+a[i][j])%mod;
    }

    // assert(ans[500][0]==fact(500));

    int q;
    scanf(" %d", &q);
    while(q--)
    {
        int n,k;
        scanf(" %d %d", &n, &k);
        printf("%lld\n", ans[n][k]);
    }
    return 0;
}
