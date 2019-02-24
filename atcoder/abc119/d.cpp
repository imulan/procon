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

int main(){
    int sz[2];
    rep(i,2) cin >>sz[i];

    int q;
    cin >>q;

    vector<ll> v[2];
    rep(i,2){
        v[i] = vector<ll>(sz[i]);
        rep(j,sz[i]) cin >>v[i][j];
    }

    vector<ll> x(q);
    rep(i,q) cin >>x[i];

    auto G = [&](int vid, ll p){
        int idx = lower_bound(all(v[vid]),p) - v[vid].begin();
        ll ret = INF;
        for(int i=-1; i<=1; ++i){
            int j = idx+i;
            if(0<=j && j<sz[vid]) ret = min(ret, abs(p-v[vid][j]));
        }
        return ret;
    };

    auto F = [&](int vid, ll p){
        int idx = lower_bound(all(v[vid]),p) - v[vid].begin();
        ll ret = INF;
        for(int i=-1; i<=1; ++i){
            int j = idx+i;
            if(0<=j && j<sz[vid]){
                ll np = v[vid][j];
                ret = min(ret, abs(p-np)+G(!vid,np));
            }
        }
        return ret;
    };

    for(ll z:x){
        ll ans = INF;
        rep(j,2) ans = min(ans, F(j,z));
        cout << ans << "\n";
    }
    return 0;
}
