#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N = 300003;
const int M = 11;
const int INF =  19191919;

int dp[N][M];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> x(n);
    rep(i,n) scanf(" %d", &x[i]);

    rep(i,N)rep(j,M) dp[i][j]=-INF;
    dp[0][m] = 0;

    rep(i,n){
        dp[i+1][m-1] = max(dp[i+1][m-1], dp[i][0]+x[i]);

        dp[i+1][0] = max(dp[i+1][0], dp[i][0]);
        for(int j=1; j<=m; ++j){
            dp[i+1][j-1] = max(dp[i+1][j-1], dp[i][j]);
        }
    }

    int ans = 0;
    rep(i,m) ans = max(ans,dp[n][i]);
    printf("%d\n", ans);
    return 0;
}