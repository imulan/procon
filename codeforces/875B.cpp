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
    scanf(" %d", &n);
    vector<int> p(n);
    rep(i,n) scanf(" %d", &p[i]);

    vector<bool> out(n+1,true);
    int r = n;

    BIT bit(n);

    vector<int> a(n+1);
    a[0]=1;
    rep(i,n-1)
    {
        out[p[i]] = false;
        bit.add(p[i],1);
        while(r>=0 && !out[r]) --r;
        a[i+1] = bit.sum(r)+1;
    }
    a[n] = 1;

    rep(i,n+1) printf("%d%c", a[i],(i==n)?'\n':' ');
    return 0;
}
