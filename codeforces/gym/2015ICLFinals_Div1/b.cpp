#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0; i<(int)n; ++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#define MOD 1000000009

long long dp[305][610][2] = {0};

int main()
{
    int n,k;
    cin>>n>>k;

    if(k==0){
        cout << 1 << endl;
        return 0;
    }

    fill(dp[0][0], dp[302][0], 0);

    dp[0][0][0] = 1;

    rep(i,n) {
        rep(j,k+1){
            rep(x,2){
                // insert )
                if(j>0) dp[i+1][j-1][x] += dp[i][j][x];
                // insert 0
                dp[i+1][j][x] += dp[i][j][x];
                // insert (
                if(j<k) dp[i+1][j+1][x|(j+1==k)] += dp[i][j][x];
            }
        }
        rep(j,k+1)rep(x,2) dp[i+1][j][x] %= MOD;
        // rep(x,2)rep(j,k+1) cout<< dp[i+1][j][x] << ",";
        // cout<<endl;
    }

    cout << dp[n][0][1]%MOD << endl;

}
