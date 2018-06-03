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

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret *= x) %= mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x,mod-2);
}

const int F = 300030;
ll f[F];

ll C(ll n, ll r){
    if(n-r<0) return 0;

    ll ret = f[n];
    (ret *= mod_inv(f[r])) %= mod;
    (ret *= mod_inv(f[n-r])) %= mod;
    return ret;
}

int main(){
    f[0] = 1;
    for(int i=1; i<F; ++i) f[i] = (f[i-1]*i)%mod;

    ll N,A,B,K;
    cin >>N >>A >>B >>K;

    ll ans = 0;
    rep(x,N+1){
        ll p = K-A*x;

        if(p<0) break;
        if(p%B!=0) continue;

        ll y = p/B;

        ans += C(N,x)*C(N,y);
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}
