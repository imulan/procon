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
    int n,k;
    cin >>n >>k;

    vector<ll> g[10];
    rep(i,n)
    {
        int genre;
        ll c;
        cin >>c >>genre;
        g[genre-1].pb(c);
    }
    rep(i,10) sort(all(g[i]),greater<int>());

    ll dp[11][2001]={0};
    rep(i,10)
    {
        //今本を売った数
        rep(j,k+1)
        {
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);

            ll add=0;
            //ジャンルiの本を売る数
            rep(x,g[i].size())
            {
                int nx=j+x+1;
                if(nx>k) break;

                add+=g[i][x];
                dp[i+1][nx]=max(dp[i+1][nx],dp[i][j]+add+x*(x+1));
            }
        }
    }

    cout << dp[10][k] << endl;
    return 0;
}
