#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int dp[1002][1002][12][2]={0};

int main()
{
    int n,m,k;
    string s,t;
    cin >>n >>m >>k >>s >>t;

    rep(i,n+1)rep(j,m+1)rep(ct,k+1)
    {
        if(i<n && j<m && s[i]==t[j])
        {
            // 前の部分文字列の継続
            if(ct>0) dp[i+1][j+1][ct][1] = max(dp[i+1][j+1][ct][1], dp[i][j][ct][1]+1);
            // 新たな部分文字列
            rep(end,2) dp[i+1][j+1][ct+1][1] = max(dp[i+1][j+1][ct+1][1], dp[i][j][ct][end]+1);
        }

        rep(end,2)
        {
            // sを1文字すすめる
            if(i<n) dp[i+1][j][ct][0] = max(dp[i+1][j][ct][0], dp[i][j][ct][end]);
            // tを1文字すすめる
            if(j<m) dp[i][j+1][ct][0] = max(dp[i][j+1][ct][0], dp[i][j][ct][end]);
        }
    }

    cout << max(dp[n][m][k][0], dp[n][m][k][1]) << endl;
    return 0;
}
