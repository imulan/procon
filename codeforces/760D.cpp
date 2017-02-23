#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=1010101010;
int dp[100001];

int main()
{
    fill(dp,dp+100001,INF);

    int n;
    scanf(" %d", &n);
    vector<int> t(n);
    rep(i,n) scanf(" %d", &t[i]);

    dp[0]=0;
    rep(i,n)
    {
        dp[i+1] = min(dp[i+1],dp[i]+20);
        for(int j=i; j<n; ++j)
        {
            if(t[j]-t[i]<90) dp[j+1] = min(dp[j+1],dp[i]+50);
            else break;
        }
        for(int j=i; j<n; ++j)
        {
            if(t[j]-t[i]<1440) dp[j+1] = min(dp[j+1],dp[i]+120);
            else break;
        }
    }

    rep(i,n) printf("%d\n", dp[i+1]-dp[i]);
    return 0;
}
