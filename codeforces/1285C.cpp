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

map<ll,int> factorize(ll x){
    map<ll,int> ret;
    ll t = x;
    for(ll i=2; i*i<=x; ++i){
        while(t%i==0){
            ++ret[i];
            t/=i;
        }
    }
    if(t>1) ++ret[t];

    return ret;
}

int main(){
    ll x;
    cin >>x;

    map<ll,int> m = factorize(x);
    vector<ll> v;
    for(const auto &p:m){
        ll t = 1;
        rep(i,p.se) t *= p.fi;
        v.pb(t);
    }

    // 2*3*5*7*11*13*17*19*23*29*31*37 = 7,420,738,134,810 > 10^{12}
    // up to 12 differnt elements
    int V = v.size();

    ll a = 1, b = x;
    rep(mask,1<<V){
        ll ta = 1, tb = 1;
        rep(i,V){
            if(mask>>i&1) ta *= v[i];
            else tb *= v[i];
        }

        if(ta > tb) swap(ta,tb);
        if(tb < b){
            a = ta;
            b = tb;
        }
    }
    cout << a << " " << b << "\n";
    return 0;
}
