#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;

const ll INF=123456789012345LL;
ll dp[301][301];

ll solve()
{
    fill(dp[0],dp[301],INF);

    int n,m;
    cin >>n >>m;

    vector<vi> c(n,vi(m));
    rep(i,n)
    {
        rep(j,m) cin >>c[i][j];
        sort(all(c[i]));
    }

    // rep(i,n)
    // {
    //     printf(" %d - th day --------------\n", i);
    //     rep(j,m) printf(" %d", c[i][j]);
    //     printf("\n");
    // }

    dp[0][0]=0;
    // i日目
    rep(i,n)
    {
        // いまj個持っている(i日目終了時にi個以上は買ってないとダメ)
        for(int j=i; j<=n; ++j)
        {
            ll price=0;
            // 今日何個買うか
            rep(k,m+1)
            {
                int nx=j+k;
                if(nx>n) break;

                dp[i+1][nx] = min(dp[i+1][nx], dp[i][j]+price+k*k);

                if(k<m) price+=c[i][k];
            }
        }
    }

    assert(dp[n][n]<INF);
    return dp[n][n];
}

int main()
{
    int T;
    cin >>T;
    rep(cases,T) printf("Case #%d: %lld\n", cases+1, solve());
    return 0;
}
