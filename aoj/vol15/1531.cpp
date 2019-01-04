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
    int n,m;
    cin >>n >>m;
    vector<ll> a(n),b(m);
    rep(i,n) cin >>a[i];
    rep(i,m) cin >>b[i];

    ll g = a[0];
    rep(i,n) g = __gcd(g,a[i]);

    ll ans = 0;

    auto check = [&](ll x){
        rep(i,m)if(x%b[i] != 0) return;
        ++ans;
    };

    for(ll i=1; i*i<=g; ++i){
        if(g%i == 0){
            check(i);
            if(g/i != i) check(g/i);
        }
    }

    cout << ans << endl;
    return 0;
}
