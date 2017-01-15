#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n,m,k;
int s[5001],d[5001];

ll const INF=123456789012345LL;
ll dist[100][100];

ll dp[5005][3][2];
ll dfs(int ld, int dl, int last)
{
    if(ld==k && dl==0) return 0;
    if(dp[ld][dl][last]>=0) return dp[ld][dl][last];

    ll ret=INF;

    int start=s[ld];
    if(last==1) start=d[ld-dl];

    // 次の荷物を取りに行く
    if(dl<2 && ld<k)
    {
        ret = min(ret, dfs(ld+1,dl+1,0)+dist[start][s[ld+1]]);
    }

    // 積んでる荷物を降ろしに行く
    if(dl>0)
    {
        ret = min(ret, dfs(ld,dl-1,1)+dist[start][d[ld-dl+1]]);
    }

    // printf("%d %d %d -> %lld\n", ld,dl,last,ret);
    return dp[ld][dl][last]=ret;
}

ll solve()
{
    cin >>n >>m >>k;

    fill(dist[0],dist[100],INF);
    rep(i,n) dist[i][i]=0;

    rep(i,m)
    {
        int a,b;
        ll g;
        cin >>a >>b >>g;
        --a;
        --b;
        dist[a][b] = min(dist[a][b], g);
        dist[b][a] = min(dist[b][a], g);
    }

    rep(c,n)rep(i,n)rep(j,n) dist[i][j] = min(dist[i][j], dist[i][c]+dist[c][j]);

    s[0]=0;
    d[0]=0;
    for(int i=1; i<=k; ++i)
    {
        cin >>s[i] >>d[i];
        --s[i];
        --d[i];
    }

    memset(dp,-1,sizeof(dp));
    ll ans=dfs(0,0,0);
    if(ans==INF) return -1;
    return ans;
}

int main()
{
    int T;
    cin >>T;
    rep(cases,T) printf("Case #%d: %lld\n", cases+1, solve());
    return 0;
}
