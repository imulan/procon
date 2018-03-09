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

const int N = 10010;
ll f[N];
ll invf[N];
ll C(ll n, ll r){
    ll ret = f[n];
    (ret*=invf[r])%=mod;
    (ret*=invf[n-r])%=mod;
    return ret;
}

ll b[N];
void B(int k){
    b[0] = 1;
    for(int i=1; i<=k; ++i){
        b[i] = 0;
        rep(j,i) (b[i] += C(i+1,j)*b[j]) %= mod;
        (b[i] *= mod_inv(i+1)) %= mod;
        b[i] = (mod - b[i])%mod;
    }
}

int main(){
    f[0] = 1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;
    rep(i,N) invf[i] = mod_inv(f[i]);

    ll n;
    int k;
    cin >>n >>k;
    n%=mod;

    B(k+1);

    ll ans = 0;
    rep(i,k+1){
        ll add = mod_pow(n+1,k+1-i);
        (add *= C(k+1,i)) %= mod;
        (add *= b[i]);

        (ans += add) %= mod;
    }

    (ans*=mod_inv(k+1))%=mod;
    cout << ans << endl;
    return 0;
}
