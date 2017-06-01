#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n;
int f[24][24];

const int N=1<<24;
int dp[N];
int dfs(int s)
{
    if(s == (1<<n)-1) return 0;
    if(dp[s]>=0) return dp[s];

    int ret=0;

    int i=0;
    while(s>>i&1) ++i;

    for(int j=i+1; j<n; ++j)if(!(s>>j&1))
    {
        int ns = s|(1<<i)|(1<<j);
        ret = max(ret,dfs(ns)+f[i][j]);
    }

    return dp[s]=ret;
}

int main()
{
    cin >>n;
    rep(i,n)rep(j,n) cin >>f[i][j];
    memset(dp,-1,sizeof(dp));
    cout << dfs(0) << endl;
    return 0;
}
