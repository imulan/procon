#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using ll = __int128;

const ll LIM = 1000000000000LL;

ll lcm(ll x, ll y){
    ll g = __gcd(x,y);
    return x/g*y;
}

ll extgcd(ll a, ll b, ll &x, ll &y){
    ll g = a;
    x = 1;
    y = 0;
    if(b!=0) g = extgcd(b,a%b,y,x), y -= (a/b)*x;
    return g;
}

// a^(-1) mod m
// aとmは互いに素でなければならない
ll mod_inverse(ll a, ll m){
    assert(__gcd(a,m)==1);
    ll x,y;
    ll g = extgcd(a,m,x,y);
    while(x<0) x+=m;
    return x%m;
}

// 中国剰余定理を計算((mod,reminder)を渡す)
ll solveCRT(const vector<ll> &mods, const vector<ll> &rems){
    int SZ = mods.size();
    ll P = 1;
    rep(i,SZ) P *= mods[i];

    ll ret = 0;
    rep(i,SZ){
        ll pp = P/mods[i];
        // dbg((long)mods[i]);
        // dbg((long)pp);
        ret += (rems[i]*mod_inverse(pp,mods[i]))%P * pp;
        ret %= P;
    }
    return ret;
}

bool prime(int x){
    if(x==1) return false;
    for(int i=2; i<x; ++i)if(x%i==0) return false;
    return true;
}

const string NG = "invalid";

int main(){
    // test();

    ll G = 2;
    for(int i=2; i<=30; ++i)if(prime(i)){
        G = lcm(G,i);
    }
    // dbg((long)G);

    int a[33];
    for(int i=2; i<=30; ++i) cin >>a[i];

    vector<ll> mods,rems;
    for(int i=2; i<=30; ++i)if(prime(i-1)){
        mods.pb(i-1);
        rems.pb(a[i]%(i-1));
    }

    ll x = solveCRT(mods,rems);
    // dbg((long)x);

    while(x<=LIM){
        bool ok = true;
        for(int i=2; i<=30; ++i){
            long tmp = x;
            int ds = 0;
            while(tmp){
                ds += tmp%i;
                tmp /= i;
            }
            if(a[i] != ds) ok = false;
        }
        if(ok){
            cout << (long)x << endl;
            return 0;
        }

        x += G;
    }

    cout << NG << endl;
    return 0;
}
