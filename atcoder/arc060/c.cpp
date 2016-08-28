#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll dp[51][51][2501]={0};

int main()
{
    int n,a;
    cin >>n >>a;
    vector<int> x(n);
    rep(i,n) cin >>x[i];

    dp[0][0][0]=1;
    rep(i,n)rep(j,n)rep(k,2501)
    {
        ll add=dp[i][j][k];
        dp[i+1][j+1][k+x[i]]+=add;
        dp[i+1][j][k]+=add;
    }

    ll ans=0;
    for(int i=1; i<=n; ++i) ans+=dp[n][i][a*i];
    cout << ans << endl;

    return 0;
}
