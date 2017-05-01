#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

double convert(string s)
{
    int idx=0;
    while(s[idx]!='/') ++idx;

    double p = atoi(s.substr(0,idx).c_str()), q = atoi(s.substr(idx+1).c_str());
    return p/q;
}

int main()
{
    // input
    int n,A[30][30];
    string s;
    cin >>n >>s;
    rep(i,n)rep(j,n) cin >>A[i][j];
    double P = convert(s);

    double dp[31][31];

    // i番目の人が1をj個得られる確率
    double p1[31][31];

    rep(i,n)
    {
        vector<int> v;
        rep(j,n)if(i!=j) v.pb(A[i][j]);

        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        rep(j,n-1)rep(k,30)
        {
            if(v[j]==0)
            {
                dp[j+1][k] += dp[j][k]*P;
                dp[j+1][k+1] += dp[j][k]*(1.0-P);
            }
            else
            {
                dp[j+1][k+1] += dp[j][k]*P;
                dp[j+1][k] += dp[j][k]*(1.0-P);
            }
        }

        rep(j,31) p1[i][j] = dp[n-1][j];
    }

    // 本来の順位を計算
    vector<pi> x(n);
    rep(i,n)
    {
        int one=0;
        rep(j,n) one -= A[i][j];
        x[i] = pi(one,i);
    }
    sort(all(x));

    memset(dp,0,sizeof(dp));
    rep(i,n) dp[0][i] = p1[x[0].se][i];
    rep(i,n-1)rep(j,n)
    {
        int lim=j-1;
        if(x[i].se<x[i+1].se) lim=j;
        for(int k=0; k<=lim; ++k) dp[i+1][k] += dp[i][j]*p1[x[i+1].se][k];
    }

    double ans = 0;
    rep(i,n) ans += dp[n-1][i];
    printf("%.10f\n", ans);
    return 0;
}
