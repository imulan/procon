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
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x,mod-2);
}

const int F = 300010;
ll f[F], invf[F];

ll C(ll n, ll r){
    if(r<0 || n-r<0) return 0;
    ll ret = f[n];
    (ret *= invf[r]) %= mod;
    (ret *= invf[n-r]) %= mod;
    return ret;
}

ll calc(ll m, ll p){
    ll ret = C(p+m,m);
    (ret *= (p+1-m))%=mod;
    (ret *= mod_inv(p+1))%=mod;
    return ret;
}

int main(){
    f[0] = 1;
    for(int i=1; i<F; ++i) f[i] = (f[i-1]*i)%mod;
    invf[F-1] = mod_inv(f[F-1]);
    for(int i=F-2; i>=0; --i) invf[i] = (invf[i+1]*(i+1))%mod;

    int n,m,k;
    cin >>n >>m >>k;

    ll ans = 0;
    rep(i,k+1){
        int mx = i, px = n+mx;
        int my = k-i, py = m+my;
        int X = mx+px, Y = my+py;
        // printf(" %d:: %d %d\n",i,X,Y);
        ll add = C(X+Y,Y);
        (add *= calc(mx,px)) %= mod;
        (add *= calc(my,py)) %= mod;

        (ans += add) %= mod;
        // dbg(add);
    }
    cout << ans << endl;
    return 0;
}
