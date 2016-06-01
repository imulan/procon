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
    int d;
    string n;
    cin >>d >>n;

    const int mod=1e9+7;

    //現在上からi桁目に注目，和をdでの剰余を取るとj,n未満が確定しているか
    int dp[10001][101][2]={0};

    dp[0][0][0]=1;
    rep(i,n.size())rep(j,d)
    {
        //printf("(%d, %d) -> %d, %d\n",i,j,dp[i][j][0],dp[i][j][1]);
        int lim=n[i]-'0';
        rep(k,lim)
        {
            int nx=(j+k)%d;
            dp[i+1][nx][1]+=dp[i][j][0];
            dp[i+1][nx][1]%=mod;
        }
        dp[i+1][(j+lim)%d][0]+=dp[i][j][0];
        dp[i+1][(j+lim)%d][0]%=mod;

        rep(k,10)
        {
            dp[i+1][(j+k)%d][1]+=dp[i][j][1];
            dp[i+1][(j+k)%d][1]%=mod;
        }
    }

    int ans=0;
    rep(i,2)
    {
        ans+=dp[n.size()][0][i];
        ans%=mod;
    }

    //0を数えてしまっているので除外する
    ans=(ans-1+mod)%mod;

    cout << ans << endl;
    return 0;
}
