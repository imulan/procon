#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

// 上からi桁目まで決定, 3を使ったらj=1, 3での剰余k
ull dp[21][2][3]={};

int main()
{
    int P;
    cin >>P;

    dp[0][0][0]=1;
    for(int i=1; i<=P; ++i)for(int num=0; num<=9; ++num)
    {
        if(num==3)
        {
            rep(j,2)rep(k,3) dp[i][1][k] += dp[i-1][j][k];
        }
        else
        {
            rep(j,2)rep(k,3) dp[i][j][(k+num)%3] += dp[i-1][j][k];
        }
    }
    // 0を排除
    --dp[P][0][0];

    ull ans=0;
    rep(j,2) ans+=dp[P][j][0];
    rep(k,3) ans+=dp[P][1][k];
    ans-=dp[P][1][0];
    cout << ans << endl;
    return 0;
}
