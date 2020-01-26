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

map<int,int> factorize(int n){
    map<int,int> d;
    int t = n;
    for(int i=2; i*i<=n; ++i){
        while(t%i == 0){
            ++d[i];
            t/=i;
        }
    }
    if(t>1) ++d[t];
    return d;
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
    return mod_pow(x,mod-2);
}

int main(){
    int n;
    cin >>n;

    vector<int> a(n);
    map<int,int> L;
    rep(i,n){
        cin >>a[i];

        map<int,int> d = factorize(a[i]);
        for(const auto &p:d){
            // printf("%d: ",i); dbg(p);
            if(!L.count(p.fi)) L[p.fi] = p.se;
            else L[p.fi] = max(L[p.fi], p.se);
        }
    }

    ll lcm = 1;
    for(const auto &p:L){
        // dbg(p);
        (lcm *= mod_pow(p.fi,p.se)) %= mod;
    }

    ll ans = 0;
    rep(i,n){
        ll b = (lcm*mod_inv(a[i]))%mod;
        (ans += b) %= mod;
    }
    cout << ans << "\n";
    return 0;
}
