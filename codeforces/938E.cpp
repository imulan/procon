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
        n>>=1;
    }
    return ret;
}

ll mod_inv(ll x){
    return mod_pow(x,mod-2);
}

const int N = 1000010;
ll f[N], inv_f[N];

ll C(int n, int r){
    ll ret = f[n];
    (ret *= inv_f[r]) %= mod;
    (ret *= inv_f[n-r]) %= mod;
    return ret;
}

int s[N]={};

int main(){
    f[0] = 1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;
    inv_f[N-1] = mod_inv(f[N-1]);
    for(int i=N-2; i>=0; --i) inv_f[i] = (inv_f[i+1]*(i+1))%mod;

    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);
    sort(all(a));

    vector<int> v(a);
    v.erase(unique(all(v)), v.end());

    vector<int> idx(n);
    rep(i,n){
        idx[i] = lower_bound(all(v), a[i]) - v.begin();
        ++s[idx[i]];
    }

    for(int i=N-2; i>=0; --i) s[i] += s[i+1];

    ll ans = 0;
    rep(i,n)if(a[i]!=a[n-1]){
        // a[i]以上の要素を並べる
        ll m = f[s[idx[i]]-1];

        // a[i]未満の要素を並べる
        (m *= f[n-s[idx[i]]]) %= mod;

        // a[i]未満の要素の位置
        (m *= C(n,s[idx[i]])) %= mod;

        (ans += m*a[i]) %= mod;
    }

    printf("%lld\n", ans);
    return 0;
}
