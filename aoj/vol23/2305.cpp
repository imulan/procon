#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=200000;
double dp[20][N+1];

inline double cost(int before, int after)
{
    return fabs(before-after)/before;
}

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    fill(dp[0],dp[20],1e10);
    for(int i=1; i<=N; ++i) dp[0][i]=cost(a[0],i);
    for(int i=1; i<n; ++i)for(int j=1; j<=N; ++j)for(int k=j; k<=N; k+=j) dp[i][k]=min(dp[i][k],max(dp[i-1][j],cost(a[i],k)));
    
    double ans=1e10;
    for(int i=1; i<=N; ++i) ans=min(ans,dp[n-1][i]);
    printf("%.10f\n", ans);
    return 0;
}
