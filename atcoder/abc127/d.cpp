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

using pl = pair<ll,ll>;

int main(){
    int n,m;
    cin >>n >>m;

    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    vector<pl> v;
    rep(i,m){
        ll b,c;
        cin >>b >>c;
        v.pb({c,b});
    }
    sort(all(v), greater<pl>());

    int ct = 0;
    for(const auto &p:v){
        ll val = p.fi, num = p.se;
        rep(i,num){
            a.pb(val);
            ++ct;
            if(ct == n) break;
        }
        if(ct == n) break;
    }

    sort(all(a), greater<ll>());

    ll ans = 0;
    rep(i,n) ans += a[i];
    cout << ans << "\n";
    return 0;
}
