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

//注目している電球i，機械の使用状態(使う前0,今使ってる1,使い終わり2)
int dp[100001][3];

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    rep(i,n)rep(j,3) dp[i][j]=1;

    //i個目の電球に注目
    for(int i=1; i<n; ++i)
    {
        if(a[i]!=a[i-1])
        {
            dp[i][0]=max(dp[i][0],dp[i-1][0]+1);
            dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
            dp[i][2]=max(dp[i][2],dp[i-1][2]+1);
        }
        else
        {
            dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
            dp[i][2]=max(dp[i][2],dp[i-1][1]+1);
        }
    }

    int ans=0;
    rep(i,n)rep(j,3) ans=max(ans,dp[i][j]);
    cout << ans << endl;
    return 0;
}
