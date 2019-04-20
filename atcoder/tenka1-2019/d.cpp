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

const ll mod = 998244353;

const int N = 303;
const int M = 90003;
ll dp[N][M][2][2];

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret *= x) %= mod;
        (x *= x) %= mod;
        n >>= 1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x,mod-2);
}

const ll DIV = mod_inv(2);
int main(){
    int n;
    cin >>n;
    vector<int> a(n);
    int sa = 0;
    rep(i,n){
        cin >>a[i];
        sa += a[i];
    }

    dp[0][0][0][0] = 1;
    rep(i,n)rep(j,M)rep(x,2)rep(y,2)if(dp[i][j][x][y]){
        int nx = j+a[i];
        if(nx < M) (dp[i+1][nx][x][y] += dp[i][j][x][y]) %= mod;

        (dp[i+1][j][x|1][y] += dp[i][j][x][y]) %= mod;
        (dp[i+1][j][x][y|1] += dp[i][j][x][y]) %= mod;
    }

    ll sub = 0;
    rep(i,M)rep(x,2)rep(y,2){
        if(sa-i <= i){
            if(sa-i==i && (x==0 || y==0)) sub += dp[n][i][x][y]*DIV;
            else sub += dp[n][i][x][y];
            sub %= mod;
        }
    }
    sub *= 3;
    sub %= mod;

    ll ans = mod_pow(3,n) - sub + mod;
    ans %= mod;
    cout << ans << endl;
    return 0;
}
