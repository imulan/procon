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

int n,k;
double p[200];

vector<double> q;
double dp[201][401];
double rec(int x,int y)
{
    if(dp[x][y]>0) return dp[x][y];

    if(x==k)
    {
        if(y==200) return 1.0;
        else return 0;
    }

    double ret=rec(x+1,y+1)*q[x]+rec(x+1,y-1)*(1.0-q[x]);
    
    return dp[x][y]=ret;
}

int main()
{
    int T;
    cin >>T;
    rep(t,T)
    {
        cin >>n >>k;
        rep(i,n) scanf(" %lf", &p[i]);

        double ans=0;
        rep(mask,1<<n)
        {
            int ct=__builtin_popcount(mask);
            if(ct!=k) continue;

            q.clear();
            rep(i,n)
            {
                if(mask>>i&1) q.pb(p[i]);
            }

            memset(dp,0,sizeof(dp));
            ans=max(ans,rec(0,200));
        }

        printf("Case #%d: ", t+1);
        printf("%.10lf\n", ans);
    }
    return 0;
}
