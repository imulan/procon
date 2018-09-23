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

vector<int> divisor(int x){
    vector<int> ret;
    for(int i=1; i*i<=x; ++i){
        if(x%i==0){
            ret.pb(i);
            if(x/i != i) ret.pb(x/i);
        }
    }
    sort(all(ret),greater<int>());
    return ret;
}

const ll mod = 1e9+7;

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
    return mod_pow(x,mod-2);
}

const int F = 100010;
ll f[F];

ll C(int n, int r){
    ll ret = f[n];
    (ret *= mod_inv(f[r])) %= mod;
    (ret *= mod_inv(f[n-r])) %= mod;
    return ret;
}

int n,m;
vector<int> d;
int D;

const int MD = 1000;
const int N = 50;
map<ll,ll> dp[MD][N];
ll dfs(int dep, int cr_n, int re_m){
    // printf(" CALL(%d %d %d) \n", dep,cr_n,re_m);
    if(dep == D-1) return re_m==1;
    if(dp[dep][cr_n].count(re_m)) return dp[dep][cr_n][re_m];

    ll ret = 0;
    int tmp = re_m;
    int i = 0;
    while(1){
        if(cr_n + i > n) break;
        // printf(" d[dep] %d , i %d\n",d[dep],i);
        ret += (dfs(dep+1, cr_n+i, tmp)*C(n-cr_n,i))%mod;
        ret %= mod;

        if(tmp%d[dep]!=0) break;
        tmp /= d[dep];
        ++i;
    }

    // printf(" (%d %d %d) %lld\n", dep,cr_n,re_m,ret);
    dp[dep][cr_n][re_m] = ret;
    return ret;
}

int main(){
    f[0] = 1;
    for(int i=1; i<F; ++i) f[i] = (f[i-1]*i)%mod;

    cin >>n >>m;

    d = divisor(m);
    D = d.size();

    cout << dfs(0,0,m) << endl;
    return 0;
}
