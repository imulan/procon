#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl;

using pl = pair<ll,ll>;

bool comp(const pl &l, const pl &r){
    return l.se-l.fi < r.se-r.fi;
}

const ll INF = 200000000000000LL;

int main(){
    int n;
    scanf(" %d", &n);

    vector<pl> d(n);
    rep(i,n){
        ll a,b;
        scanf(" %lld %lld", &a, &b);
        d[i] = {a,b};
    }
    sort(all(d), comp);

    auto check = [&](ll x){
        rep(i,n){
            ll a=d[i].fi, b=d[i].se;
            if(x<a) return false;
            x -= b;
        }
        return true;
    };

    ll ng=0, ok=INF;
    while(ok-ng>1){
        ll mid = (ng+ok)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    printf("%lld\n", ok);
    return 0;
}