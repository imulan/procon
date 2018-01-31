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

// nの約数におけるメビウス関数の値 O(sqrt(n))
map<int,int> moebius(int n){
    vector<int> primes;
    // nの素因数を列挙
    for(int i=2; i*i<=n; ++i){
        if(n%i==0) primes.push_back(i);
        while(n%i==0) n/=i;
    }
    if(n>1) primes.push_back(n);

    map<int,int> ret;
    int SZ = primes.size();
    // 2^SZ通りを試す(nの約数の個数よりは少ない)
    rep(i,1<<SZ){
        int mu = 1, d = 1;
        rep(j,SZ){
            if(i>>j&1){
                mu *= -1;
                d *= primes[j];
            }
        }
        ret[d] = mu;
    }
    return ret;
}

map<ll,ll> m1;
ll solve1(ll n){
    if(m1.count(n)) return m1[n];

    ll ret = mod_pow(2,n-1);
    for(int i=1; i*i<=n; ++i){
        if(n%i==0){
            if(i!=n) ret = (ret - solve1(i) + mod)%mod;
            if(n/i!=n && n/i!=i) ret = (ret - solve1(n/i) + mod)%mod;
        }
    }
    return m1[n] = ret;
}

ll solve2(ll n){
    ll ret = 0;
    map<int,int> m = moebius(n);
    for(int i=1; i*i<=n; ++i){
        if(n%i==0){
            (ret += m[n/i]*mod_pow(2,i-1)+mod) %= mod;
            if(n/i!=i) (ret += m[i]*mod_pow(2,n/i-1)+mod) %= mod;
        }
    }
    return ret;
}

int main(){
    ll x,y;
    cin >>x >>y;

    ll ans = 0;
    if(y%x==0){
        // ans = solve1(y/x);
        ans = solve2(y/x);
    }
    cout << ans << endl;
    return 0;
}
