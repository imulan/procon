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

int dp[101][101];

int main()
{
    int Gx,Gy,N,F;
    cin >>Gx >>Gy >>N >>F;

    fill(dp[0],dp[101],INF);
    dp[0][0]=0;

    while(N--)
    {
        int x,y,c;
        cin >>x >>y >>c;

        for(int i=Gy; i>=0; --i)for(int j=Gx; j>=0; --j)
        {
            int nx=j+x, ny=i+y;
            if(ny>Gy || nx>Gx) continue;

            dp[ny][nx] = min(dp[ny][nx], dp[i][j]+c);
        }
    }

    int ans = INF;
    rep(i,Gy+1)rep(j,Gx+1) ans = min(ans, dp[i][j]+F*(Gy-i+Gx-j));
    cout << ans << endl;
    return 0;
}
