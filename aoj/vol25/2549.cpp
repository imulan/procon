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

using pi = pair<int,int>;
using P = pair<pi,int>;

int main(){
    int n,s;
    cin >>n >>s;
    --s;

    vector<P> v(n);
    rep(i,n){
        int l,r;
        cin >>l >>r;
        v[i] = {{r,l},i};
    }
    sort(all(v));

    vector<vector<ll>> w(n,vector<ll>(n));
    rep(i,n)rep(j,n) cin >>w[i][j];

    rep(k,n)rep(i,n)rep(j,n) w[i][j] = min(w[i][j], w[i][k]+w[k][j]);

    const ll INF = LLONG_MAX/3;
    vector<ll> dp(n,-INF);
    rep(i,n){
        int to = v[i].se;
        ll d = w[s][to];
        ll l = v[i].fi.se, r = v[i].fi.fi;

        ll a = r-max(l,d);
        dp[i] = max(dp[i],a);
    }

    rep(i,n){
        int u = v[i].se;
        ll R = v[i].fi.fi;

        for(int j=i+1; j<n; ++j){
            int to = v[j].se;
            ll d = w[u][to];
            ll l = v[j].fi.se, r = v[j].fi.fi;

            ll a = r-max(l,R+d);
            if(a>=0) dp[j] = max(dp[j], dp[i]+a);
        }
    }

    ll ans = 0;
    rep(i,n) ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
