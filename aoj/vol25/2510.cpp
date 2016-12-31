#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

int dp[1000];

int main()
{
    int n;
    while(scanf(" %d", &n),n)
    {
        vector<pi> p(n);
        rep(i,n) scanf(" %d %d", &p[i].fi, &p[i].se);
        sort(all(p));

        if(n==1)
        {
            printf("%d\n", p[0].fi*2+p[0].se);
            continue;
        }

        int sum_r=0;
        rep(i,n) sum_r+=p[i].fi;

        if(sum_r - p[n-1].fi >= p[n-1].fi)
        {
            // 2人ともsum_rで読み切れる
            int ans=sum_r;
            rep(i,n) ans+=p[i].se;
            printf("%d\n", ans);
        }
        else
        {
            // 2*p[n-1].fiだけかかる
            memset(dp,0,sizeof(dp));

            // 0~n-2を読んだあとに、残されている時間
            int rem = p[n-1].fi - (sum_r-p[n-1].fi);

            // n-1冊の中から感想を書く方法を探す
            dp[0]=1;
            rep(i,n-1)
            {
                for(int j=rem; j>=0; --j)if(dp[j]) dp[j+p[i].se]=1;
            }

            int ok=0;
            rep(i,rem+1)if(dp[i]) ok=i;

            int sum_w=0;
            rep(i,n) sum_w+=p[i].se;

            printf("%d\n", 2*p[n-1].fi+sum_w-ok);
        }
    }
    return 0;
}
