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

ll a,k;
ll mod;

ll mod_pow(ll x, ll n){
    n %= mod-1;
    ll ret = 1;
    while(n){
        if(n&1) (ret*=x)%=mod;
        (x*=x)%=mod;
        n>>=1;
    }
    return ret;
}

int main(){
    cin >>a >>mod >>k;
    --k;
    a %= mod;

    ll x = 1;
    set<ll> s;
    vector<ll> v;
    while(1){
        v.pb(x);
        s.insert(x);
        x = mod_pow(a,x);
        if(s.count(x)) break;
    }
    // dbg(x);
    // dbg(v);

    int idx = 0;
    int V=v.size();
    rep(i,V)if(v[i]==x) idx = i;
    // dbg(idx);

    ll ans = 0;
    if(k<V){
        rep(i,k) (ans += v[i]) %= mod;
    }
    else{
        rep(i,idx) (ans += v[i]) %= mod;
        k -= idx;

        ll cycle = 0;
        for(int i=idx; i<V; ++i) (cycle += v[i]) %= mod;
        int sz = V-idx;
        // dbg(sz);

        ll loop = (k/sz)%mod;
        (ans += (cycle*loop)%mod)%=mod;
        k %= sz;

        // dbg(k);
        for(int i=idx; i<V; ++i){
            if(k==0) break;
            (ans += v[i]) %= mod;
            --k;
        }
    }
    cout << ans << endl;
    return 0;
}
