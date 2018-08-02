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
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x, mod-2);
}

int main(){
    ll x,k;
    cin >>x >>k;

    if(x==0){
        cout << 0 << endl;
        return 0;
    }

    x %= mod;
    ll r = (x*mod_pow(2,k))%mod;
    ll l = (r-mod_pow(2,k)+1+mod)%mod;
    // printf("%lld %lld\n", l,r);

    ll p = r*(r+1)%mod - (l-1)*l%mod + mod;
    p %= mod;
    ll ans = (p*mod_inv(mod_pow(2,k)))%mod;
    cout << ans << endl;
    return 0;
}
