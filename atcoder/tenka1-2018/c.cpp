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
    vector<ll> a(n);
    rep(i,n) cin >>a[i];
    sort(all(a));

    ll ans = 0;

    // pat.1
    int idx = (n-1)/2;
    vector<ll> v;
    v.pb(a[idx]);

    int l = 0, r = n-1;
    rep(i,n/2){
        if(r==idx) break;
        v.pb(a[r]);
        --r;

        if(l==idx) break;
        v.pb(a[l]);
        ++l;
    }

    ll t = 0;
    rep(i,n-1) t+=abs(v[i]-v[i+1]);
    ans = max(ans, t);

    // pat.2
    idx = n/2;
    v.clear();
    v.pb(a[idx]);

    l = 0;
    r = n-1;
    rep(i,n/2){
        if(l==idx) break;
        v.pb(a[l]);
        ++l;

        if(r==idx) break;
        v.pb(a[r]);
        --r;
    }

    t = 0;
    rep(i,n-1) t+=abs(v[i]-v[i+1]);
    ans = max(ans, t);

    cout << ans << endl;
    return 0;
}
