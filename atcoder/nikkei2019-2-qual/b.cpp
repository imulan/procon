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

const ll mod = 998244353;

ll solve(){
    int n;
    cin >>n;
    vector<int> d(n);
    rep(i,n) cin >>d[i];

    if(d[0] != 0) return 0;
    for(int i=1; i<n; ++i)if(d[i] == 0) return 0;

    vector<ll> ct(n);
    int md = 0;
    rep(i,n){
        ++ct[d[i]];
        md = max(md, d[i]);
    }

    ll ret = 1;
    for(int i=1; i<=md; ++i){
        rep(j,ct[i]) (ret *= ct[i-1]) %= mod;
    }
    return ret;
}

int main(){
    cout << solve() << "\n";
    return 0;
}
