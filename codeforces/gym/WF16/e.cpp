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

bool check(ll y, ll b, ll l){
    vector<ll> d;
    while(y){
        d.pb(y%b);
        y /= b;
    }
    reverse(all(d));

    int sz = d.size();
    string s = "";
    rep(i,sz){
        if(d[i]>=10) return false;
        s += d[i]+'0';
    }

    if(stoll(s) < l) return false;

    return true;
}

ll find_b(ll y, ll z){
    vector<ll> a;
    while(z){
        a.pb(z%10);
        z /= 10;
    }

    ll lb = 0, rb = -1;
    int A = a.size();
    if(A == 2) rb = 1000000000000000000LL + 1;
    else if(A == 3) rb = 1000000000LL + 1;
    else if(A == 4) rb = 1000000LL + 1;
    assert(rb>0);

    auto f = [&](ll b){
        ll ret = 0;
        ll p = 1;
        rep(i,A){
            ret += a[i]*p;
            if(i<A-1) p *= b;
        }
        return ret;
    };

    while(rb-lb > 1){
        ll mb = (lb+rb)/2;

        if(f(mb) <= y) lb = mb;
        else rb = mb;
    }

    // dbg(lb);dbg(f(lb));
    if(f(lb) == y) return lb;
    return -1;
}

const int LIM = 10000;

int main(){
    ll y,l;
    cin >>y >>l;

    ll ans = 10;
    if(l<LIM){
        for(int i=l; i<LIM; ++i){
            // printf(" check %d :: b %lld\n", i,find_b(y,i));
            ans = max(ans, find_b(y,i));
        }
    }

    ll okb = 1, ngb = 35000;
    while(ngb-okb > 1){
        ll mb = (okb+ngb)/2;

        ll t = 1;
        rep(i,4) t *= mb;

        if(t <= y) okb = mb;
        else ngb = mb;
    }

    for(ll b=10; b<=okb; ++b){
        // dbg(b);
        ll t = y;
        if(check(y,b,l)) ans = max(ans, b);
    }

    cout << ans << "\n";
    return 0;
}
