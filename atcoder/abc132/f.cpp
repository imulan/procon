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

int main(){
    ll n,k;
    cin >>n >>k;

    map<ll,ll> m;
    for(int i=1; i*i<=n; ++i){
       ll x = n/i;
       m[x] = i;
    }

    for(int x=2; (x-1)*(x-1)<=n; ++x){
        ll i = n/x + 1;

        if(!m.count(x-1)) m[x-1] = i;
        m[x-1] = min(m[x-1],i);
    }

    vector<int> v;
    for(const auto &p:m){
        v.pb(p.fi+1);
        v.pb(p.se);
    }
    v.pb(n+1);

    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int V = v.size();

    vector<ll> dp(V-1);
    rep(i,V-1) dp[i] = v[i+1]-v[i];

    rep(loop,k-1){
        vector<ll> pre(dp);
        for(int i=1; i<V-1; ++i) (pre[i] += pre[i-1]) %= mod;

        vector<ll> nx(V-1);

        rep(i,V-1){
            ll x = n/v[i];
            int idx = upper_bound(all(v), x) - v.begin();
            --idx;

            ll num = v[i+1]-v[i];
            nx[i] = (pre[idx]*num)%mod;
        }
        dp = nx;
    }

    ll ans = 0;
    for(ll i:dp) (ans += i) %= mod;
    cout << ans << endl;
    return 0;
}
