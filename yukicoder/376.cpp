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

const ll INF = LLONG_MAX/3;

vector<ll> divisor(ll n){
    vector<ll> ret;
    for(ll i=1; i*i<=n; ++i){
        if(n%i == 0){
            ret.pb(i);
            if(n/i != i) ret.pb(n/i);
        }
    }
    sort(all(ret));
    return ret;
}

int main(){
    ll n;
    cin >>n;

    vector<ll> d = divisor(n);
    int D = d.size();

    ll ans = INF;
    rep(i,D){
        ll a = d[i];

        ll x = n/a;
        rep(j,i+1){
            ll b = d[j];
            if(x%b != 0) continue;
            ll c = x/b;

            ans = min(ans, a+b+c-3);
        }
    }

    cout << ans << " " << n-1 << "\n";
    return 0;
}
