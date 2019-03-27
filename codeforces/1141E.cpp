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

ll solve(){
    ll H;
    int n;
    cin >>H >>n;

    vector<ll> d(n);
    rep(i,n) cin >>d[i];

    vector<ll> pre(d);
    for(int i=1; i<n; ++i) pre[i] += pre[i-1];

    ll mn=0;
    rep(i,n) mn = min(mn, pre[i]);
    if(mn>=0) return -1;

    // mn<0

    ll s = pre[n-1];
    if(s>=0){
        ll now = H;
        rep(i,n){
            now += d[i];
            if(now<=0) return i+1;
        }
        return -1;
    }

    // mn<0, s<0
    // H + x*s <= abs(mn)
    // x <= (abs(mn)-H)/s
    ll x = max((abs(mn)-H)/s, 0LL);

    ll ans = x*n;
    ll now = H + x*s;

    rep(loop,3){
        rep(i,n){
            now += d[i];
            ++ans;
            if(now<=0) return ans;
        }
    }
    assert(false);
    return -2;
}

int main(){
    cout << solve() << '\n';
    return 0;
}
