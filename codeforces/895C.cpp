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

bool prime(int n){
    for(int i=2; i*i<=n; ++i)if(n%i==0) return false;
    return true;
}

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

const int F = 100001;
ll f[F], inv_f[F];
ll C(ll n, ll r){
    ll ret = f[n];
    (ret *= inv_f[r]) %= mod;
    (ret *= inv_f[n-r]) %= mod;
    return ret;
}

const int N = 70;
int idx[N];
vector<int> p;

ll dp[1<<11];
ll solve1(const vector<int> &v){
    map<int,int> ct;
    for(int i:v) ++ct[i];

    dp[0] = 1;
    for(const auto &pp:ct){
        int mask = 0;
        int t = pp.fi;
        rep(j,11){
            int ap = 0;
            while(t%p[j]==0){
                t /= p[j];
                ++ap;
            }
            ap %= 2;
            mask |= ap<<j;
        }

        ll nx[1<<11]={};
        rep(j,1<<11){
            (nx[j^mask] += dp[j]*mod_pow(2,pp.se-1))%=mod;
            (nx[j] += dp[j]*mod_pow(2,pp.se-1))%=mod;
        }
        rep(j,1<<11) dp[j] = nx[j];
    }
    return dp[0];
}

// 37以上の素数について
ll solve2(const vector<int> &u){
    map<int,int> ct;
    for(int i:u) ++ct[i];

    ll ret = 1;
    for(const auto &pp:ct){
        ll add = mod_pow(2,pp.se-1);
        (ret *= add) %= mod;
    }
    return ret;
}

int main(){
    f[0] = 1;
    for(int i=1; i<F; ++i) f[i] = (f[i-1]*i)%mod;
    inv_f[F-1] = mod_inv(f[F-1]);
    for(int i=F-2; i>=0; --i) inv_f[i] = (inv_f[i+1]*(i+1))%mod;

    for(int i=2; i<=N; ++i){
        if(prime(i)) p.pb(i);
    }
    int P = p.size();
    rep(i,P) idx[p[i]] = i;

    vector<int> v,u;
    int n;
    cin >>n;
    rep(i,n){
        int a;
        cin >>a;
        if(a>=37 && prime(a)) u.pb(a);
        else v.pb(a);
    }

    cout << (solve1(v)*solve2(u) - 1 + mod)%mod << endl;
    return 0;
}
