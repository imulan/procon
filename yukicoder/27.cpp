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

const int INF=12345;

int main()
{
    int v[4];
    rep(i,4) cin >>v[i];

    int ans=200;

    for(int a=1; a<=28; ++a)
    for(int b=a+1; b<=29; ++b)
    for(int c=b+1; c<=30; ++c)
    {
        int dp[31];
        fill(dp,dp+31,INF);
        dp[0]=0;
        rep(i,30)
        {
            if(i+a<=30) dp[i+a]=min(dp[i+a],dp[i]+1);
            if(i+b<=30) dp[i+b]=min(dp[i+b],dp[i]+1);
            if(i+c<=30) dp[i+c]=min(dp[i+c],dp[i]+1);
        }

        bool valid=true;
        rep(i,4) if(dp[v[i]]==INF) valid=false;

        if(valid)
        {
            int t=0;
            rep(i,4) t+=dp[v[i]];
            ans=min(ans,t);
        }
    }

    cout << ans << endl;
    return 0;
}
