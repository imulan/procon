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

const ll mod = 1e9+7;

ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n >>= 1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x,mod-2);
}

const int N = 1000010;
ll f[N];

int main(){
    f[0] = 1;
    rep(i,N-1) f[i+1] = f[i]*(i+1)%mod;

    ll n,k;
    cin >>n >>k;

    vector<ll> sp(k+2);
    rep(i,k+1) sp[i+1] = (sp[i]+mod_pow(i+1,k))%mod;

    auto F = [&](ll x){
        if(x<=k+1) return sp[x];

        ll P = 1;
        rep(i,k+2) (P *= x-i+mod) %= mod;

        ll ret = 0;
        rep(i,k+2){
            ll p = P*mod_inv(x-i)%mod;

            ll q = f[i]*f[k+1-i]%mod;
            if((k+1-i)%2 == 1) q = mod-q;

            ll add= p*mod_inv(q)%mod;
            (add *= sp[i]) %= mod;
            (ret += add) %= mod;
        }
        return ret;
    };

    cout << F(n) << "\n";
    return 0;
}
