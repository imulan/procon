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

void test(int n){
    vector<int> p(n);
    rep(i,n) p[i] = i;

    vector<int> cr(n),cl(n);
    do{
        // dbg(p);
        vector<bool> rem(n+1,true);
        rep(i,n){
            int l = p[i];
            while(l>=0 && rem[l]) --l;
            ++l;

            int r = p[i];
            while(r<n && rem[r]) ++r;
            --r;

            // printf(" %d:  %d %d\n",i,l,r);
            cl[l]++;
            cr[r]++;

            rem[p[i]] = false;
        }
    }while(next_permutation(all(p)));
    dbg(cl);
    dbg(cr);
}

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

const int N = 100010;
ll f[N];

int main(){
    f[0] = 1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;

    int n;
    cin >>n;

    vector<ll> a(n+1);
    rep(i,n) cin >>a[i+1];

    vector<ll> s(n+1);
    for(int i=1; i<=n; ++i) s[i] = (s[i-1]+a[i])%mod;
    // dbg(s);
    // test(n);

    vector<ll> cr(n+1);
    for(int i=1; i<n; ++i){
        cr[i] = (f[n]*(1 - mod_inv(i+1) + mod))%mod;
    }
    for(int i=1; i<=n; ++i){
        (cr[n] += mod_inv(i)) %= mod;
    }
    (cr[n] *= f[n]) %= mod;
    // dbg(cr);

    vector<ll> cl(n+1);
    for(int i=1; i<=n; ++i) cl[n+1-i] = cr[i];
    // dbg(cl);

    ll ans = 0;
    for(int i=1; i<=n; ++i){
        (ans += cr[i]*s[i]) %= mod;
        ans = (ans - (cl[i]*s[i-1])%mod + mod)%mod;
    }
    cout << ans << endl;
    return 0;
}
