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

int main()
{
    int n;
    cin >>n;

    vector<vi> b(n);
    rep(i,n)
    {
        vi v(3);
        rep(j,3) cin >>v[j];
        sort(all(v));

        b[i] = v;
    }
    sort(all(b));

    vi dp(n,1);
    rep(i,n)rep(j,i)
    {
        bool ok = true;
        rep(k,3) ok &= (b[i][k]>b[j][k]);

        if(ok) dp[i] = max(dp[i],dp[j]+1);
    }

    int ans = 1;
    rep(i,n) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
