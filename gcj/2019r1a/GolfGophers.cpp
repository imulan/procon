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

const int SZ = 18;

ll query(ll mod){
    rep(i,SZ){
        cout << mod;
        if(i<SZ-1) cout << " ";
    }
    cout << endl;

    ll ret = 0;
    vector<int> res(SZ);
    rep(i,SZ){
        cin >>res[i];
        if(res[i] == -1) return -1;
        ret += res[i];
    }
    return ret%mod;
}

bool ans(int G){
    cout << G << endl;
    int res;
    cin >>res;
    return res == 1;
}

int main(){
    int T,n,m;
    cin >>T >>n >>m;
    rep(ttt,T){
        vector<ll> x({4,3,5,7,11,13,17}), y;

        ll L = 1;
        rep(i,7) L *= x[i];

        rep(i,7){
            ll r = query(x[i]);
            assert(r != -1);
            y.pb(r);
        }

        auto check = [&](ll z){
            rep(i,7)if(z%x[i] != y[i]) return false;
            return true;
        };

        ll a = 1;
        for(int i=1; i<=m; ++i) if(check(i)) a = i;
        assert(ans(a));
    }
    return 0;
}
