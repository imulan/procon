#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
    int n;
    cin >>n;
    vector<vector<int>> h(n, vector<int>(3));
    rep(i,n)rep(j,3) cin >>h[i][j];

    vector<vector<int>> dp(n,vector<int>(3));
    rep(i,3) dp[0][i] = h[0][i];

    for(int i=1; i<n; ++i){
        rep(j,3){
            rep(pre,3)if(j != pre){
                dp[i][j] = max(dp[i][j], dp[i-1][pre]+h[i][j]);
            }
        }
    }

    int ans = 0;
    rep(i,3) ans = max(ans, dp[n-1][i]);
    cout << ans << "\n";
    return 0;
}
