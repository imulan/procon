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

using P = pair<ll,int>;

const ll L = 1e9+7;
const ll INF = LLONG_MAX/3;

int main(){
    int n;
    cin >>n;

    vector<P> v;
    rep(i,n){
        int a;
        cin >>a;
        v.pb({a,i});
    }
    v.pb({L,n});
    sort(all(v));

    vector<ll> dp(n+1, INF);
    dp[0] = -v[0].fi;

    vector<int> par(n+1,-1);

    priority_queue<P, vector<P>, greater<P>> pq;
    for(int i=3; i<=n; ++i){
        pq.push({dp[i-3], i-3});

        P t = pq.top();
        par[i] = t.se;
        dp[i] = t.fi + v[i-1].fi - v[i].fi;
    }

    int k = 0;
    vector<int> g(n);
    int idx = n;
    while(idx>0){
        int p = par[idx];
        for(int i=p; i<idx; ++i) g[v[i].se] = k;

        ++k;
        idx = p;
    }

    cout << dp[n]+L << " " << k << "\n";
    rep(i,n) cout << g[i]+1 << " \n"[i==n-1];
    return 0;
}
