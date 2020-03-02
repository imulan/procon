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
    vector<ll> x(3);
    ll d;
    rep(i,3) cin >>x[i];
    cin >>d;

    sort(all(x));

    ll ans = 0;
    rep(i,2){
        ll w = x[i+1]-x[i];
        if(w<d) ans += d-w;
    }
    cout << ans << "\n";
    return 0;
}
