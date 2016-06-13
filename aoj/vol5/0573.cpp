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

//店iまで行くか決めた,現在時刻j
int dp[3010][3010]={0};

int main()
{
    int n,t,s;
    cin >>n >>t >>s;
    vector<int> a(n),b(n);
    rep(i,n) cin >>a[i] >>b[i];


    rep(i,n)
    {
        rep(j,t+1)
        {
            //遊ばない
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            //遊ぶ
            int nx=j+b[i];
            if(nx>t || (j<s && s<nx)) continue;
            dp[i+1][nx]=max(dp[i+1][nx],dp[i][j]+a[i]);
        }
    }

    int ans=0;
    rep(i,t+1) ans=max(ans,dp[n][i]);
    cout << ans << endl;
    return 0;
}
