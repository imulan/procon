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

const int N = 17;
ll pw[N];

// [l,r]
ll sum(ll l, ll r){
    // printf(" %lld -- %lld\n",l,r);
    auto F = [&](ll x){
        return x*(x+1)/2;
    };
    return F(r)-F(l-1);
}

ll f(ll x){
    if(x == 0) return 0;

    ll ret = 0;
    rep(i,N-1){
        ll d = i+1;
        if(pw[i]<=x && x<pw[i+1]){
            ret += d*sum(1, x-pw[i]+1);
            return ret;
        }

        ret += d*sum(x-pw[i+1]+2, x-pw[i]+1);
    }
}

ll g(ll x){
    if(x == 0) return 0;

    ll ret = 0;
    rep(i,N-1){
        ll d = i+1;
        if(pw[i]<=x && x<pw[i+1]){
            ret += d*(x-pw[i]+1);
            return ret;
        }

        ret += d*(pw[i+1]-pw[i]);
    }
}


int main(){
    pw[0] = 1;
    rep(i,N-1) pw[i+1] = pw[i]*10;

    int q;
    cin >>q;
    while(q--){
        ll k;
        cin >>k;

        // f(500000000) > 10**18
        const int R = 500000000;
        ll ok = 0, ng = R;
        while(ng-ok>1){
            ll mid = (ok+ng)/2;
            if(f(mid) < k) ok = mid;
            else ng = mid;
        }

        // dbg(ok); dbg(f(ok));
        k -= f(ok);

        ok = 0;
        ng = R;
        while(ng-ok>1){
            ll mid = (ok+ng)/2;
            if(g(mid) < k) ok = mid;
            else ng = mid;
        }

        k -= g(ok);

        string s = to_string(ok+1);
        // dbg(s); dbg(k);
        cout << s[k-1] << "\n";
    }
    return 0;
}
