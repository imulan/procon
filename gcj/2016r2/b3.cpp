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
    int T;
    cin >>T;
    rep(t,T)
    {
        int n,k;
        double p[200];

        cin >>n >>k;
        rep(i,n) scanf(" %lf", &p[i]);
        sort(p,p+n);

        double ans=0;

        //左からi人，右からk-i人とる
        for(int i=0; i<=k; ++i)
        {
            vector<double> q;
            for(int j=0; j<i; ++j) q.pb(p[j]);
            for(int j=n-k+i; j<=n-1; ++j) q.pb(p[j]);

            //i人目まで投票終わり，Yes-No値j(200がevenとする)
            double dp[201][401]={0};
            //初期値
            dp[0][200]=1.0;

            rep(x,k)
            {
                for(int y=1; y<400; ++y)
                {
                    dp[x+1][y+1]+=dp[x][y]*q[x];
                    dp[x+1][y-1]+=dp[x][y]*(1.0-q[x]);
                }
            }

            //更新
            ans=max(ans,dp[k][200]);
        }

        printf("Case #%d: ", t+1);
        printf("%.10lf\n", ans);
    }
    return 0;
}
