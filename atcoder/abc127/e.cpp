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

const int N = 200002;
ll f[N];

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

ll C(int n, int r){
    ll ret = f[n];
    (ret *= mod_inv(f[r])) %= mod;
    (ret *= mod_inv(f[n-r])) %= mod;
    return ret;
}


int main(){
    f[0] = 1;
    rep(i,N-1) f[i+1] = f[i]*(i+1)%mod;

    int h,w,k;
    cin >>h >>w >>k;

    ll now = 0;
    rep(i,h)rep(j,w) (now += i+j) %= mod;

    ll s = 0;
    rep(i,h){
        ll tmp = now;
        rep(j,w){
            (s += now) %= mod;

            ll p = j+1, m = w-p;
            now = (now + (p-m)*h + mod)%mod;
        }

        now = tmp;
        ll p = i+1, m = h-p;
        now = (now + (p-m)*w + mod)%mod;
    }
    (s *= mod_inv(2)) %= mod;

    cout << s*C(h*w-2, k-2)%mod << "\n";
    return 0;
}
