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

const int N = 222;
ll f[N], invf[N];

ll C(int n, int r){
    if(n<r) return 0;
    ll ret = f[n];
    (ret *= invf[r]) %= mod;
    (ret *= invf[n-r]) %= mod;
    return ret;
}

int main(){
    f[0] = 1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;
    rep(i,N) invf[i] = mod_inv(f[i]);

    int v,e;
    cin >>v >>e;

    vector<int> a(e), b(e);
    rep(i,e){
        cin >>a[i] >>b[i];
        --a[i];
        --b[i];
    }

    vector<int> num_v(1<<v), num_e(1<<v);
    rep(mask,1<<v){
        num_v[mask] = __builtin_popcount(mask);
        rep(i,e){
            if( (mask>>a[i]&1) && (mask>>b[i]&1) ) ++num_e[mask];
        }
    }

    vector<ll> dp(1<<v);
    for(int mask=1; mask<(1<<v); ++mask){
        dp[mask] = C(num_e[mask], num_v[mask]-1);

        int cand = 0;
        while(1){
            if(mask>>cand&1) break;
            ++cand;
        }

        dbg(mask);

        for(int sub=mask-1; sub>0; --sub){
            sub &= mask;
            if(sub>>cand&1){
                int rem = sub^mask;

                // dbg(sub);
                // dbg((dp[sub]*C(num_e[rem],num_v[rem]))%mod);

                dp[mask] -= (dp[sub]*C(num_e[rem],num_v[rem]))%mod;
                dp[mask] += mod;
                dp[mask] %= mod;
            }
        }

        dbg(dp[mask]);
    }

    cout << dp[(1<<v)-1] << endl;
    return 0;
}
