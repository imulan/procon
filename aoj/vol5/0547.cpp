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
    const int mod=100000;
    int w,h;
    //現在位置，左0/下1から来た，曲がっていい1
    int dp[100][100][2][2];

    while(cin >>w >>h,w|h)
    {
        memset(dp,0,sizeof(dp));

        dp[0][0][0][0]=1;
        dp[0][0][1][0]=1;

        rep(i,w)rep(j,h)
        {
            //左から来て，曲がれない時
            //そのまま右に進む(先で曲がれる)
            if(i+1<w)
            {
                dp[i+1][j][0][1]+=dp[i][j][0][0];
                dp[i+1][j][0][1]%=mod;
            }

            //左から来て，曲がれる時
            //そのまま右に進む(先で曲がれる)
            if(i+1<w)
            {
                dp[i+1][j][0][1]+=dp[i][j][0][1];
                dp[i+1][j][0][1]%=mod;
            }
            //曲がって上に行く(先で曲がれない)
            if(j+1<h)
            {
                dp[i][j+1][1][0]+=dp[i][j][0][1];
                dp[i][j+1][1][0]%=mod;
            }

            //下から来て，曲がれない時
            //そのまま上に行く(先で曲がれる)
            if(j+1<h)
            {
                dp[i][j+1][1][1]+=dp[i][j][1][0];
                dp[i][j+1][1][1]%=mod;
            }

            //下から来て，曲がれる時
            //そのまま上に行く(先で曲がれる)
            if(j+1<h)
            {
                dp[i][j+1][1][1]+=dp[i][j][1][1];
                dp[i][j+1][1][1]%=mod;
            }
            //曲がって右に行く(先で曲がれない)
            if(i+1<w)
            {
                dp[i+1][j][0][0]+=dp[i][j][1][1];
                dp[i+1][j][0][0]%=mod;
            }
        }

        int ans=0;
        rep(x,2)rep(y,2)
        {
            ans+=dp[w-1][h-1][x][y];
            ans%=mod;
        }

        cout << ans << endl;
    }
    return 0;
}
