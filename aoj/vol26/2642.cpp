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
    ll p,q;
    cin >>n >>p >>q;

    vector<ll> c(n);
    rep(i,n) cin >>c[i];

    ll ans = 0;
    ll now = q;
    vector<ll> jisui(n);
    rep(i,n){
        jisui[i] = p*now;
        ans += jisui[i];
        ++now;
    }
    dbg(ans);

    ll sub = 0;
    for(int i=n-1; i>=0; --i){
        ll diff = c[i] - jisui[i] - sub;
        if(diff>=0) ans += diff;
        else sub += 2*p;
    }

    cout << ans << endl;
    return 0;
}
