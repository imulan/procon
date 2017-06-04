#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int dp[500][2];

string solve()
{
    int n;
    cin >>n;
    string s[2];
    rep(i,2) cin >>s[i];

    int l=0,r=n-1;
    while(l<n)
    {
        if(s[0][l]=='.' && s[1][l]=='.') ++l;
        else break;
    }
    while(r>=0)
    {
        if(s[0][r]=='.' && s[1][r]=='.') --r;
        else break;
    }

    memset(dp,0,sizeof(dp));
    rep(i,2) dp[l][i] = (s[i][l]=='#');
    for(int i=l+1; i<=r; ++i)
    {
        if(s[0][i]=='#' && s[1][i]=='#')
        {
            rep(j,2)if(dp[i-1][j]) dp[i][!j]=1;
        }
        else if(s[0][i]=='#')
        {
            if(dp[i-1][0]) dp[i][0]=1;
        }
        else if(s[1][i]=='#')
        {
            if(dp[i-1][1]) dp[i][1]=1;
        }
    }

    return (dp[r][0] || dp[r][1])?"yes":"no";
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
