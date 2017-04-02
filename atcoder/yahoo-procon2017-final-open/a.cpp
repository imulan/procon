#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=123456789;
int dp[100001][5];

int main()
{
    string y="yahoo";

    string s;
    cin >>s;

    int n=s.size();

    fill(dp[0],dp[100001],INF);
    dp[0][0]=0;

    rep(i,n)
    {
        rep(j,5)
        {
            // 挿入(1~4文字)
            for(int k=1; k<=4; ++k) dp[i][(j+k)%5] = min(dp[i][(j+k)%5], dp[i][j]+k);
        }

        rep(j,5)
        {
            // もともと来るべき文字なら放置でもいい
            if(s[i] == y[j]) dp[i+1][(j+1)%5] = min(dp[i+1][(j+1)%5], dp[i][j]);

            // 置換
            dp[i+1][(j+1)%5] = min(dp[i+1][(j+1)%5], dp[i][j]+1);

            // 除去
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+1);
        }
    }

    int ans=INF;
    rep(i,5) ans = min(ans,dp[n][i]+(5-i)%5);
    cout << ans << endl;
    return 0;
}
