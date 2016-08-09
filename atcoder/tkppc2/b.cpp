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

int main()
{
    int n,m;
    cin >>n >>m;
    vector<int> v(n),t(n);
    rep(i,n) cin >>v[i] >>t[i];

    vector<int> dp(m+1);
    rep(i,n)
    {
        for(int j=m; j>=0; --j)
        {
            if(j+t[i]<=m) dp[j+t[i]]=max(dp[j+t[i]], dp[j]+v[i]);
        }
    }

    int ans=0;
    rep(i,m+1) ans=max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
