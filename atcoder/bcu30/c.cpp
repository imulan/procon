#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int e[300][300]={};
int dp[300][300]={};

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    rep(i,m)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        e[a][b]=1;
    }

    rep(i,n)rep(j,n)rep(k,n) dp[i][j]+=e[i][k]*e[j][k];

    ll ans = 0;
    rep(i,n)rep(j,n)rep(k,n)if(e[i][j] && e[i][k]) ans+=dp[j][k];

    printf("%lld\n", ans);
    return 0;
}
