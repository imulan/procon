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
const ll LIM = 1000000000000000001LL;

ll SIN(ll t);
ll COS(ll t);

inline ll mod_pow(ll x, ll n){
    ll ret = 1;
    while(n){
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

inline ll mod_inv(ll x){
    return mod_pow(x, mod-2);
}

map<ll,ll> s;
ll SIN(ll t){
    if(s.count(t)) return s[t];

    ll pw = 1;
    while(pw*2<=t) pw *= 2;
    ll a=pw, b=t-pw;

    ll ret = ((SIN(a)*COS(b))%mod + (COS(a)*SIN(b))%mod)%mod;

    return s[t] = ret;
}

map<ll,ll> c;
ll COS(ll t){
    if(c.count(t)) return c[t];

    ll ret = -1;
    if(t%2==0){
        ret = 2*COS(t/2)*COS(t/2) - 1 + mod;
        ret %= mod;
    }
    else{
        ll pw = 1;
        while(pw*2<=t) pw *= 2;
        ll a=pw, b=t-pw;

        ll mul = (1 - (COS(1)*COS(1))%mod + mod)%mod;
        ret = ((COS(a)*COS(b))%mod - ((SIN(a)*SIN(b))%mod*mul)%mod + mod)%mod;
    }
    assert(ret>=0);
    return c[t] = ret;
}

ll solve(){
    ll l,d,t;
    cin >>l >>d >>t;

    s.clear();
    c.clear();
    c[1] = (d*mod_inv(l))%mod;
    s[1] = 1;
    for(ll i=2; i<LIM; i*=2){
        c[i] = (2*COS(i/2)*COS(i/2) - 1 + mod)%mod;
        s[i] = (2*SIN(i/2)*COS(i/2))%mod;
    }

    return (l*COS(t))%mod;
}

int main(){
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
