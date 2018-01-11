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

const ll mod = 1000000007;

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

const int N = 6006;
ll f[N];
ll C(ll n, ll r){
    if(n<r) return 0;
    ll ret = f[n];
    (ret*=mod_inv(f[r]))%=mod;
    (ret*=mod_inv(f[n-r]))%=mod;
    return ret;
}

ll solve(){
    int n,r,g,b;
    cin >>n >>r >>g >>b;
    int S = r+g+b;

    if(S==0) return 1;
    if(S>n) return 0;

    ll ans = 0;
    // 2個の塊の個数
    rep(i,S){
        // 1個の塊の個数
        int O = S - 2*i;
        if(O<0) continue;
        // 最低でも必要な空白
        int sp = i+O-1;
        if(2*i + O + sp > n) continue;

        // 自由に挿入できる空白の個数
        int rsp = n - (2*i+O+sp);

        // 1個の塊と2個の塊の枠の配置方法
        ll t = C(i+O,i);
        // 残った空白の挿入方法
        (t *= C(i+O+rsp,rsp)) %= mod;
        // 2個の塊は、各セルごとに入れ替えられる
        (t *= mod_pow(2,i)) %= mod;

        rep(j,i+1){
            int rem_r = r-j;
            if(rem_r<0) continue;
            if(rem_r>O) continue;

            ll tt = t;
            // 2個の塊に赤を割り当てる
            (tt *= C(i,j)) %= mod;
            // 1個の塊に赤を割り当てる
            (tt *= C(O,rem_r)) %= mod;

            int rem_g = g-(i-j), rem_b = b-(i-j);
            if(rem_g<0 || rem_b<0) continue;
            // 残りのマスに2色を割り当てる
            (tt *= C(rem_g+rem_b,rem_g)) %= mod;

            (ans += tt) %= mod;
        }
    }
    return ans;
}

int main(){
    f[0] = 1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;

    cout << solve() << endl;
    return 0;
}
