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

// void test(int n){

//     vector<int> p(n-1);
//     rep(i,n-1) p[i] = i;

//     vector<ll> ct(n-1);
//     do{

//         vector<bool> alive(n,true);
//         rep(i,n-1){
//             int t = p[i];
//             alive[t] = false;
//             while(!alive[t]){
//                 ++ct[t];
//                 ++t;
//             }

//         }

//     }while(next_permutation(all(p)));

//     dbg(ct);
// }

const int N = 100010;
ll f[N];

int main(){
    f[0] = 1;
    for(int i=1;i<N;++i) f[i] = (f[i-1])*i%mod;

    int n;
    cin >>n;

    vector<ll> x(n);
    rep(i,n) cin >>x[i];

    vector<ll> a(n-1);
    a[0] = f[n-1];

    ll pre = 1;
    for(int i=1; i<n-1; ++i){
        ll t = pre*(i+1)%mod;
        (t += f[i]) %= mod;

        pre = t;

        a[i] = pre*f[n-1]%mod;
        (a[i] *= mod_inv(f[i+1])) %= mod;
    }

    ll ans = 0;
    rep(i,n-1){
        ll d = x[i+1]-x[i];
        ans += (a[i]*d)%mod;
        ans %= mod;
    }

    cout << ans << "\n";
    return 0;
}
