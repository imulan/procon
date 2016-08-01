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
    int n,m;
    cin >>n >>m;

    int s[14][14]={0};
    rep(i,m)
    {
        int x,y,score;
        cin >>x >>y >>score;
        s[x][y]=score;
    }

    int dp[1<<14]={0};
    rep(mask,1<<n)
    {
        rep(i,n)
        {
            if(mask>>i&1) continue;

            int add=0;
            rep(j,n) if(mask>>j&1) add+=s[j][i];

            int nx=mask+(1<<i);
            dp[nx]=max(dp[nx], dp[mask]+add);
        }
    }
    cout << dp[(1<<n)-1] << endl;
    return 0;
}
