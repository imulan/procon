#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
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

const ll div2 = mod_inv(2);

int main(){
    ll n,m,a;
    cin >>n >>m >>a;

    vector<ll> b(m);
    rep(i,m) cin >>b[i];

    ll ans = mod_pow(a, n - 2*b[m-1]);

    for(int i=m-1; i>0; --i) b[i] -= b[i-1];
    rep(i,m){
        ll w = b[i];

        ll pw = mod_pow(a,w);
        ll mul = pw + ((pw*(pw-1+mod))%mod*div2)%mod;

        (ans *= mul) %= mod;
    }

    cout << ans << "\n";
    return 0;
}
