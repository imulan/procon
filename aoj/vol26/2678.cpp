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
    ll x,y,z,a,b,c,n;
    cin >>x >>y >>z >>a >>b >>c >>n;

    auto dist = [&](ll p, ll q, ll r){
        return (abs(p-a)+abs(q-b)+abs(r-c))%n;
    };

    vector<ll> ct(n);
    rep(i,x) ++ct[dist(i,0,0)];

    vector<ll> ct_y(n);
    int diff = 0;
    rep(i,y){
        ++ct_y[diff];
        if(i<b) diff = (diff-1+n)%n;
        else diff = (diff+1)%n;
    }

    vector<ll> ct_z(n);
    diff = 0;
    rep(i,z){
        ++ct_z[diff];
        if(i<c) diff = (diff-1+n)%n;
        else diff = (diff+1)%n;
    }

    auto shift = [&](const vector<ll> &v){
        vector<ll> ret(n);
        rep(i,n-1) ret[i+1] = v[i];
        ret[0] = v[n-1];
        return ret;
    };

    auto make_ct = [&](vector<ll> f, vector<ll> m){
        vector<ll> nct(n);
        rep(i,n){
            rep(j,n) nct[j] += m[i]*f[j];
            f = shift(f);
        }
        return nct;
    };

    ct = make_ct(ct, ct_y);
    ct = make_ct(ct, ct_z);

    rep(i,n) cout << ct[i] << " \n"[i==n-1];
    return 0;
}
