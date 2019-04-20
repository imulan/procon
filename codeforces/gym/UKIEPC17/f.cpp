#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using D = long double;

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<D> dp(n+1,0);
    dp[0] = 1;
    rep(turn,k){
        vector<D> nx(n+1,0);

        rep(i,n){
            nx[i] += dp[i]*0.5;
            nx[i+1] += dp[i]*0.5;
        }

        nx[n-1] += dp[n]*0.5;
        nx[n] += dp[n]*0.5;

        dp = nx;
    }

    D ans = 0;
    for(int i=1; i<=n; ++i) ans += i*dp[i];
    printf("%.10Lf\n", ans);
    return 0;
}