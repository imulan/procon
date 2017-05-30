#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=62;
int X[N];
int bit[N];
ll dp[N][2];

ll dfs(int d, int s)
{
    if(d==N) return 1;
    if(dp[d][s]>=0) return dp[d][s];

    ll ret=0;
    if(X[d])
    {
        // 1を選ばないとダメ
        if(bit[d]) ret+=dfs(d+1,s);
        else
        {
            if(s) ret+=dfs(d+1,s);
        }
    }
    else
    {
        // 0か1か選べる
        if(bit[d])
        {
            ret += dfs(d+1,1);
            ret += dfs(d+1,s);
        }
        else
        {
            ret += dfs(d+1,s);
            if(s) ret+=dfs(d+1,s);
        }
    }

    return dp[d][s]=ret;
}

ll solve()
{
    ll a,b,x;
    scanf(" %lld %lld %lld", &a, &b, &x);
    --a;

    rep(i,N) X[i] = (x>>(N-1-i))&1;

    ll ret = 0;

    rep(i,N) bit[i] = (a>>(N-1-i))&1;
    memset(dp,-1,sizeof(dp));
    ret -= dfs(0,0);

    rep(i,N) bit[i] = (b>>(N-1-i))&1;
    memset(dp,-1,sizeof(dp));
    ret += dfs(0,0);

    return ret;
}

int main()
{
    int Q;
    scanf(" %d", &Q);
    while(Q--) printf("%lld\n", solve());
    return 0;
}
