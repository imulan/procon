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
    return mod_pow(x, mod-2);
}

int main(){
    int n;
    cin >>n;
    vector<ll> x(n);
    rep(i,n) cin >>x[i];

    sort(all(x));

    ll sx = x[1];
    ll pw = 1;
    ll t = 1;
    rep(i,n-2){
        (t *= 2) %= mod;

        (sx += x[i+2]*t) %= mod;
        (pw += t) %= mod;
    }

    ll INV = mod_inv(2);
    ll ans = 0;
    rep(i,n-1){
        ll sub = (x[i]*pw)%mod;

        ll add = (sx - sub + mod) % mod;;
        (ans += add) %= mod;

        sx = (sx - x[i+1] + mod) % mod;
        (sx *= INV) %= mod;

        pw = (pw-1+mod) % mod;
        (pw *= INV)%=mod;
    }
    cout << ans << endl;
    return 0;
}
