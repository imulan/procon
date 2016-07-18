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

int dp[16][10001]={0};

int main()
{
    int t,n;
    cin >>t >>n;
    vector<int> c(n),v(n);
    rep(i,n) cin >>c[i];
    rep(i,n) cin >>v[i];

    rep(i,n)
    {
        //アトラクションiにj回乗る時に得られる満足度
        int sumv[10]={0};
        int nowv=v[i];
        for(int j=1; j<10; ++j)
        {
            sumv[j]+=sumv[j-1]+nowv;
            nowv/=2;
        }

        //残り時間j
        rep(j,t+1)
        {
            //k回乗る(10回以上はあらゆるアトラクションの満足度が0になるのでムダ)
            rep(k,10)
            {
                int nj=j-k*c[i];
                if(nj<0) break;
                dp[i+1][nj]=max(dp[i+1][nj],dp[i][j]+sumv[k]);
            }
        }
    }

    int ans=0;
    rep(i,t+1) ans=max(ans,dp[n][i]);
    cout << ans << endl;
    return 0;
}
