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

const ll LIM = LLONG_MAX/3;

vector<ll> div(ll x){
    vector<ll> ret;
    for(ll i=1; i*i<=x; ++i){
        if(x%i==0) ret.pb(i);
    }
    return ret;
}

int main(){
    ll a,b;
    cin >>a >>b;

    vector<ll> cand = div(a+b);
    vector<ll> da = div(a), db = div(b);

    auto valid = [&](ll h){
        ll w = (a+b)/h;

        auto ita = upper_bound(all(da), h);
        if(ita != da.begin()) --ita;
        ll ah = *ita;
        ll aw = a/ah;

        if(ah<=h && aw<=w) return true;

        auto itb = upper_bound(all(db), h);
        if(itb != db.begin()) --itb;

        ll bh = *itb;
        ll bw = b/bh;

        if(bh<=h && bw<=w) return true;

        return false;
    };

    ll ans = LIM;
    for(ll h:cand){
        if(valid(h)){
            ll w = (a+b)/h;
            ans = min(ans, (h+w)*2);
        }
    }
    cout << ans << endl;
    return 0;
}
