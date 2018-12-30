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

const ll mod = 1e9+7;

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

const int N = 100010;
ll dp[N][2];
ll ct[2];

int main(){
    int n,m;
    cin >>n >>m;

    dp[0][0] = dp[0][1] = 1;
    rep(i,n){
        (ct[0] += dp[i][0]) %= mod;
        (ct[1] += dp[i][1]) %= mod;
        if(i+1-m>=0) (ct[1] += mod-dp[i+1-m][1]) %= mod;

        // dbg(ct[0]);dbg(ct[1]);
        dp[i+1][1] = ct[0];
        dp[i+1][0] = ct[1];
    }
    // rep(i,n+1)rep(j,2) printf(" dp[%d][%d] = %lld\n",i,j,dp[i][j]);

    ll ans = mod_pow(2,n);
    rep(i,2) ans = (ans - dp[n][i] + mod) % mod;
    cout << ans << endl;
    return 0;
}
