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

int main(){
    int n;
    cin >>n;
    vector<ll> l(n),r(n);
    rep(i,n) cin >>l[i] >>r[i];

    vector<ll> ux;
    rep(i,n){
        ux.pb(l[i]);
        ux.pb(r[i]+1);
    }
    sort(all(ux));
    ux.erase(unique(all(ux)), ux.end());

    int sz = ux.size();
    vector<ll> e(sz);
    rep(i,n){
        int lidx = lower_bound(all(ux), l[i]) - ux.begin();
        int ridx = lower_bound(all(ux), r[i]+1) - ux.begin();

        ++e[lidx];
        --e[ridx];
    }

    vector<ll> ans(n+1);
    ll t = e[0];
    for(int i=1; i<sz; ++i){
        ll L = ux[i]-ux[i-1];
        ans[t] += L;
        t += e[i];
    }

    for(int i=1; i<=n; ++i) cout << ans[i] << " \n"[i==n];
    return 0;
}
