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

int main(){
    int n;
    ll k;
    cin >>n >>k;

    vector<ll> a(n),f(n);
    rep(i,n) cin >>a[i];
    rep(i,n) cin >>f[i];

    sort(all(a));
    sort(all(f), greater<ll>());

    auto check = [&](ll x){
        ll ct = 0;
        rep(i,n){
            ll A = x/f[i];
            ct += max(0LL, a[i]-A);
        }
        return ct<=k;
    };

    ll ng=-1, ok=LLONG_MAX/3;
    while(ok-ng>1){
        ll mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << "\n";
    return 0;
}
