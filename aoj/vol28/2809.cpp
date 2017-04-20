#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

// 0:Rの個数を最大化, 1:Lの個数を最大化
int dp[2001][2001][2];
const string LR="LR";

void calc(string s, int K)
{
    int S=s.size();
    memset(dp,0,sizeof(dp));
    rep(i,S)rep(j,K+1)rep(k,2)
    {
        // 魔法使わない
        dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]+(s[i]==LR[(j%2+k+1)%2]));
        // 魔法使う
        if(j<K) dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k]+(s[i]==LR[(j%2+k)%2]));
    }
}

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    string s;
    int K;
    cin >>s >>K;

    string x="",y="";
    rep(i,s.size())
    {
        if(s[i]=='L' || s[i]=='R') x+=s[i];
        else y+=(s[i]=='U')?'L':'R';
    }

    int X=x.size(), Y=y.size();
    // 0:Rの個数を最大化, 1:Lの個数を最大化
    int dx[2001]={};
    // 0:Dの個数を最大化, 1:Uの個数を最大化
    int dy[2001]={};

    calc(x,K);
    rep(i,K+1) dx[i]=max(2*dp[X][i][0]-X, 2*dp[X][i][1]-X);
    calc(y,K);
    rep(i,K+1) dy[i]=max(2*dp[Y][i][0]-Y, 2*dp[Y][i][1]-Y);

    int ans=0;
    rep(i,K+1)rep(j,K+1)if(i+j<=K) ans=max(ans,dx[i]+dy[j]);

    cout << ans << endl;
    return 0;
}
