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

int dp[301][301][301]={0};

int main()
{
    int X,Y,n;
    scanf(" %d %d %d", &X, &Y, &n);
    vector<int> t(n),h(n);
    rep(i,n) scanf(" %d %d", &t[i],&h[i]);

    rep(i,n)
    {
        rep(x,X+1)rep(y,Y+1)
        {
            dp[i+1][x][y]=dp[i][x][y];

            int s=x+y+t[i];
            if(s>X+Y) continue;

            //できるだけスペシャルチケットを使う量を抑える
            int by=min(Y,y+t[i]-1);
            int bx=s-by;

            if(bx<=X)
            {
                dp[i+1][x][y]=max(dp[i+1][x][y],dp[i][bx][by]+h[i]);
            }
        }

    }

    int ans=0;
    rep(i,X+1)rep(j,Y+1) ans=max(ans,dp[n][i][j]);

    cout << ans << endl;
    return 0;
}
