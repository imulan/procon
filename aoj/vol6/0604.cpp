#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int dp[2001][2001][2]={};

int main()
{
    int m,n;
    string s,t;
    cin >>m >>n >>s >>t;

    rep(i,m+1)rep(j,n+1)
    {
        if(i<m)
        {
            if(s[i]=='I')
            {
                dp[i+1][j][0] = max(dp[i+1][j][0], dp[i][j][1]+1);
            }
            else
            {
                if(dp[i][j][0]>0) dp[i+1][j][1] = max(dp[i+1][j][1], dp[i][j][0]+1);
            }
        }

        if(j<n)
        {
            if(t[j]=='I')
            {
                dp[i][j+1][0] = max(dp[i][j+1][0], dp[i][j][1]+1);
            }
            else
            {
                if(dp[i][j][0]>0) dp[i][j+1][1] = max(dp[i][j+1][1], dp[i][j][0]+1);
            }
        }
    }

    int ans=0;
    rep(i,m+1)rep(j,n+1) ans = max(ans,dp[i][j][0]);
    printf("%d\n", ans);
    return 0;
}
