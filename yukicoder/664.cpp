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

const int N = 400, M = 25;
ll dp[N][M]={};

int main(){
    int n,m,start;
    cin >>n >>m >>start;
    vector<int> a(n+1);
    rep(i,n+1) cin >>a[i];

    dp[0][0] = start;
    // buy at i
    rep(i,n){
        // sell at j
        for(int j=i+1; j<n+1; ++j){
            rep(k,m){
                ll money = dp[i][k];
                ll num = dp[i][k]/a[i];
                money -= a[i]*num;
                money += a[j]*num;
                dp[j][k+1] = max(dp[j][k+1], money);
            }
        }
        // no action
        rep(k,m+1) dp[i+1][k] = max(dp[i+1][k], dp[i][k]);
    }

    ll ans = 0;
    rep(i,N)rep(j,M) ans = max(ans,dp[i][j]);
    cout << ans << endl;
    return 0;
}
