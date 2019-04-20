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

struct BIT{
    // [1,n]
    int n; vector<ll> bit;
    // 初期化
    BIT(int _n){
        n = _n;
        bit = vector<ll>(n+1,0);
    }
    // sum of [1,i]
    ll sum(int i){
        ll s = 0;
        while(i>0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    // add x in i-th element
    void add(int i, ll x){
        while(i<=n){
            bit[i] += x;
            i += i & -i;
        }
    }
};

using pi = pair<int,int>;

int main(){
    int n,m;
    cin >>n >>m;

    vector<int> t(m),p(m);
    rep(i,m){
        cin >>t[i] >>p[i];
        --t[i];
    }

    vector<pi> v(n,{0,0});
    vector<pi> uv;
    uv.pb({-1,0});
    uv.pb({0,0});
    rep(i,m){
        ++v[t[i]].fi;
        v[t[i]].se -= p[i];
        uv.pb(v[t[i]]);
    }

    sort(all(uv));
    uv.erase(unique(all(uv)), uv.end());
    int UV = uv.size();

    map<pi,int> idx;
    rep(i,UV) idx[uv[i]] = i;

    BIT bit(UV);
    bit.add(1,n);
    v = vector<pi>(n,{0,0});
    rep(i,m){
        bit.add(idx[v[t[i]]], -1);

        ++v[t[i]].fi;
        v[t[i]].se -= p[i];

        bit.add(idx[v[t[i]]], 1);
        cout << n - bit.sum(idx[v[0]]) + 1 << '\n';
    }
    return 0;
}
