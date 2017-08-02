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

int main()
{
    int n;
    string s;
    cin >>n >>s;

    vector<int> r(n),c(n);
    rep(i,n) cin >>r[i];
    rep(i,n) cin >>c[i];

    ll ans = 0;

    BIT bit(n+1);
    rep(i,n)
    {
        int v = (s[i]-'0'+bit.sum(i+1))%2;
        if(v==0) continue;

        ans += c[i];
        bit.add(i+1,1);
        bit.add(r[i]+1,-1);
    }
    cout << ans << endl;
    return 0;
}
