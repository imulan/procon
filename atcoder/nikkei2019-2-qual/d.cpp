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

const ll INF = LLONG_MAX/3;

int main(){
    int n,m;
    cin >>n >>m;

    vector<int> L(m),R(m),C(m);
    rep(i,m){
        cin >>L[i] >>R[i] >>C[i];
        --L[i];
        --R[i];
    }

    vector<vector<int>> B(n);
    rep(i,m){
        B[L[i]].pb(i);
    }

    vector<ll> dp(n,INF);
    dp[0] = 0;

    vector<vector<ll>> drop(n);
    multiset<ll> s;
    for(int i=1; i<n; ++i){
        for(int idx:B[i-1]){
            ll val = dp[i-1]+C[idx];
            s.insert(val);
            drop[R[idx]].pb(val);
        }
        // dbg((vector<ll>(all(s))));

        if(!s.empty()) dp[i] = min(dp[i], *s.begin());

        for(ll v:drop[i]) s.erase(s.find(v));
    }

    ll ans = dp[n-1];
    if(ans == INF) ans = -1;
    cout << ans << "\n";
    return 0;
}
