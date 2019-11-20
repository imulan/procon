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

const int N = 300003;
const ll mod = 998244353;

ll f[N];

int main(){
    f[0] = 1;
    for(int i=1; i<N; ++i) f[i] = (f[i-1]*i)%mod;

    int n;
    scanf(" %d", &n);
    vector<int> a(n),b(n);
    rep(i,n){
        scanf(" %d %d", &a[i], &b[i]);
        --a[i];
        --b[i];
    }

    auto one_bad = [&](const vector<int> &v){
        vector<int> ct(n);
        for(int i:v) ++ct[i];

        ll ret = 1;
        rep(i,n) (ret *= f[ct[i]]) %= mod;
        return ret;
    };

    ll ans = f[n];
    ans = (ans - one_bad(a) + mod)%mod;
    ans = (ans - one_bad(b) + mod)%mod;

    // count a is sorted && b is sorted
    vector<vector<int>> B(n);
    rep(i,n) B[a[i]].pb(b[i]);

    ll both = 1;
    int prev_max = -1;
    rep(i,n){
        if(B[i].empty()) continue;

        int mn = n, mx = -1;
        map<int,int> ct;
        for(int j:B[i]){
            ++ct[j];
            mn = min(mn,j);
            mx = max(mx,j);
        }

        if(prev_max > mn){
            both = 0;
            break;
        }

        for(const auto &p:ct) (both *= f[p.se]) %= mod;
        prev_max = mx;
    }

    (ans += both) %= mod;
    printf("%lld\n", ans);
    return 0;
}
