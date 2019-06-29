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

using pi = pair<int,int>;
using pl = pair<ll,ll>;

pl frac(ll x, ll y){
    ll g = __gcd(x,y);
    x /= g;
    y /= g;
    return {x,y};
}

bool is_large(pl x, pl y){
    // x.fi/x.se > y.fi/y.se
    assert(x.fi*y.se >= 0);
    assert(y.fi*x.se >= 0);
    return x.fi*y.se > y.fi*x.se;
}

void solve(){
    int n;
    scanf(" %d", &n);

    vector<int> p(n),v(n);
    vector<pi> x(n);
    rep(i,n){
        scanf(" %d %d", &p[i], &v[i]);
        x[i] = {p[i],i};
    }

    sort(all(x), [](const pi &lh, const pi &rh){
        return (lh.fi == rh.fi) ? lh.se < rh.se : lh.fi > rh.fi;
    });


    ll sv = 0, d = 0;
    rep(i,n){
        sv += v[i];
        d += v[i]*p[i];
    }

    pl ans = frac(d,sv);
    int k = 0;
    rep(i,n){
        ++sv;
        d += p[x[i].se];

        pl tmp = frac(d,sv);
        if(is_large(tmp, ans)){
            ans = tmp;
            k = i+1;
        }
    }

    vector<int> idx(k);
    rep(i,k) idx[i] = x[i].se+1;
    sort(all(idx));

    printf("%lld/%lld\n", ans.fi, ans.se);
    printf("%d\n",k);
    rep(i,k){
        if(i) printf(" ");
        printf("%d", idx[i]);
    }
    printf("\n");
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(i,T) solve();
    return 0;
}
