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
typedef pair<pi,int> p;

int dp[400][400];

int main()
{
    int n;
    while(scanf(" %d", &n),n)
    {
        vector<p> a(n);
        rep(i,n)
        {
            int x,y,w;
            scanf(" %d %d %d", &x, &y, &w);
            a[i] = p(pi(x,y),w);
        }
        sort(all(a));

        memset(dp,0,sizeof(dp));
        rep(i,n)
        {
            int start = a[i].fi.fi;
            int end = a[i].fi.se;
            int w = a[i].se;

            for(int x=366; x>0; --x)for(int y=x; y>0; --y)
            {
                if(start<y) continue;

                int min_v = min(end+1,x), max_v = max(end+1,x);
                dp[min_v][max_v] = max(dp[min_v][max_v], dp[y][x]+w);
            }
        }

        int ans=0;
        rep(i,400)rep(j,400) ans=max(ans,dp[i][j]);
        printf("%d\n", ans);
    }
    return 0;
}
