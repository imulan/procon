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

using pi = pair<int,int>;

const ll mod = 1000000007;

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret*=x) %= mod;
        (x*=x) %= mod;
        n>>=1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x,mod-2);
}

const int F = 200010;
ll f[F], invf[F];
ll C(int n, int r){
    ll ret = f[n];
    (ret *= invf[r]) %= mod;
    (ret *= invf[n-r]) %= mod;
    return ret;
}

const int N = 3003;
ll dp[N][2];

int main(){
    f[0] = 1;
    for(int i=1; i<F; ++i) f[i] = (f[i-1]*i)%mod;

    invf[F-1] = mod_inv(f[F-1]);
    for(int i=F-2; i>=0; --i) invf[i] = (invf[i+1]*(i+1))%mod;

    int h,w,n;
    cin >>h >>w >>n;

    vector<pi> b(n);
    rep(i,n){
        int r,c;
        cin >>r >>c;
        b[i] = {r-1, c-1};
    }
    b.pb({0,0});
    b.pb({h-1,w-1});
    sort(all(b));

    auto ok = [&](int from, int to){
        pi p = b[from], q = b[to];
        return p.fi<=q.fi && p.se<=q.se;
    };

    n += 2;
    dp[0][1] = 1;
    rep(i,n)rep(j,2)if(dp[i][j]){
        for(int k=i+1; k<n; ++k)if(ok(i,k)){
            int r = b[k].fi - b[i].fi;
            int c = b[k].se - b[i].se;
            (dp[k][!j] += dp[i][j]*C(r+c,r)) %= mod;
        }
    }

    ll ans = (dp[n-1][0] - dp[n-1][1] + mod) % mod;
    cout << ans << endl;
    return 0;
}
