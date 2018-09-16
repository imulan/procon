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

const ll INF = 1000010000;

int main(){
    int n;
    ll h;
    scanf(" %d %lld", &n, &h);

    vector<ll> l(n),r(n);
    rep(i,n) scanf(" %lld %lld", &l[i], &r[i]);

    vector<ll> a,w;
    rep(i,n-1){
        a.pb(r[i]-l[i]);
        w.pb(l[i+1]-r[i]);
    }
    a.pb(r[n-1]-l[n-1]);
    w.pb(INF);

    vector<ll> sa(a), sw(w);
    rep(i,n-1){
        sa[i+1] += sa[i];
        sw[i+1] += sw[i];
    }

    ll ans = 0;
    rep(i,n){
        ll W = 0;
        if(i>0) W = sw[i-1];

        int idx = lower_bound(all(sw), W+h) - sw.begin();

        ll t = sa[idx];
        if(i>0) t -= sa[i-1];
        ans = max(ans,t);
    }
    ans += h;

    printf("%lld\n", ans);
    return 0;
}
