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

const int INF=12345678;
int dp[1001][1001];

int main()
{
    int S,T;
    string s,t;
    cin >>S >>T;
    cin >>s >>t;

    fill(dp[0],dp[1001],INF);
    //初期化
    dp[0][0]=0;
    for(int i=1; i<=S; ++i) dp[i][0]=i;
    for(int i=1; i<=T; ++i) dp[0][i]=i;

    //sのi文字目,tのj文字目まで処理が終わっている時の最小の編集距離を計算
    for(int i=1; i<=S; ++i)for(int j=1; j<=T; ++j)
    {
        //変更
        if(s[i-1]==t[j-1]) dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
        else dp[i][j]=min(dp[i][j],dp[i-1][j-1]+1);

        //削除
        dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
        //挿入
        dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
    }

    cout << dp[S][T] << endl;
    return 0;
}
