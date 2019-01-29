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

using pl = pair<ll,ll>;

const ll INF = LLONG_MAX/3;

int main(){
    int n;
    scanf(" %d", &n);
    vector<pl> v(n);
    rep(i,n){
        ll a,b;
        scanf(" %lld %lld", &a, &b);
        v[i] = {a,b};
    }

    sort(all(v));

    vector<ll> preb(n);
    preb[0] = v[0].se;
    for(int i=1; i<n; ++i) preb[i] = preb[i-1]+v[i].se;

    ll sub = preb[n-2];
    ll ans = 0;

    ll mx = -INF;
    for(int i=n-1; i>=0; --i){
        mx = max(mx, preb[i]-v[i].fi);
        ans = max(ans, mx-sub+v[i].fi);
        if(i>0) sub -= v[i-1].se;
    }
    printf("%lld\n", ans);
    return 0;
}
