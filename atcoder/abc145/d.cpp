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
    return mod_pow(x,mod-2);
}

const int N = 2222222;
ll f[N];
ll invf[N];
ll C(int n, int m){
    ll ret = f[n];
    (ret*=invf[m])%=mod;
    (ret*=invf[n-m])%=mod;
    return ret;
}

int main(){
    f[0] = 1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;
    rep(i,N) invf[i] = mod_inv(f[i]);

    int x,y;
    cin >>x >>y;

    ll ans = 0;
    rep(i,x+1){
        int rx = x-i, ry = y-2*i;
        if(2*ry == rx){
            (ans += C(i+ry,i)) %= mod;
        }
    }
    cout << ans << "\n";
    return 0;
}
