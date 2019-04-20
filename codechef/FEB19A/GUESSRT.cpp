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

ll mod_inv(ll x){
    return mod_pow(x, mod-2);
}

ll solve(){
    int n,k,m;
    scanf(" %d %d %d", &n, &k, &m);

    ll x = (m+1)/2;

    ll pw = mod_pow(n,x);
    ll pww = mod_pow(n-1,x);

    ll q = pw;
    ll p = (pw - pww + mod)%mod;

    ll ans = (p*mod_inv(q))%mod;

    if(m%2 == 0){
        p = pww;
        q = (pw*(n+k))%mod;

        ans += (p*mod_inv(q))%mod;
        ans %= mod;
    }

    return ans;
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) printf("%lld\n", solve());
    return 0;
}
