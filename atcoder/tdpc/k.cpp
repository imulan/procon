#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=202020202;
typedef pair<int,int> pi;

const int N=100005;
int dp[N];

int main()
{
    int n;
    scanf(" %d", &n);

    vector<pi> p(n);
    rep(i,n)
    {
        int x,r;
        scanf(" %d %d", &x, &r);
        p[i] = pi(-(x-r), -(x+r));
    }

    sort(all(p));

    fill(dp,dp+N,INF);
    dp[0] = -p[0].se;
    for(int i=1; i<n; ++i)
    {
        int a = -p[i].se;
        int idx = lower_bound(dp,dp+N,a) - dp;
        dp[idx] = a;
    }

    int ans=N-1;
    while(ans>0 && dp[ans]==INF) --ans;
    printf("%d\n", ans+1);
    return 0;
}
