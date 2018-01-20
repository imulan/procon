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

using pi = pair<int,int>;
const ll mod = 1e9+7;

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

int main(){
    int n;
    cin >>n;

    vector<pi> v;
    rep(i,n)
    {
        int a,b;
        cin >>a >>b;
        if(a>b) swap(a,b);
        v.pb({b,a});
    }
    sort(all(v));

    ll pw=1;
    rep(i,n-2) (pw*=2)%=mod;

    ll ans = 0;
    BIT bit(2*n);
    rep(i,n){
        int a=v[i].fi, b=v[i].se;
        (ans += (bit.sum(2*n)-bit.sum(a))*pw)%=mod;
        (ans += (bit.sum(2*n)-bit.sum(b))*pw)%=mod;
        bit.add(a,1);
        bit.add(b,1);
        // dbg(ans);
    }
    cout << ans << endl;
    return 0;
}
