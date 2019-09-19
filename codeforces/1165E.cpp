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

using P = pair<ll,int>;
const ll mod = 998244353;

ll f(const vector<ll> &a, const vector<ll> &b){
    int n = a.size();
    ll ret = 0;
    rep(i,n){
        ll x = a[i]%mod;
        (x *= b[i]) %= mod;
        (ret += x) %= mod;
    }
    return ret;
}

int main(){
    int n;
    scanf(" %d", &n);

    vector<ll> a(n),b(n);
    vector<P> v(n);

    rep(i,n){
        scanf(" %lld", &a[i]);
        a[i] *= i+1;
        a[i] *= n-i;
        v[i] = {a[i],i};
    }
    rep(i,n) scanf(" %lld", &b[i]);

    sort(all(v));
    sort(all(b));

    vector<ll> z(n);
    rep(i,n){
        int idx = v[i].se;
        z[idx] = b[n-1-i];
    }
    printf("%lld\n", f(a,z));
    return 0;
}
