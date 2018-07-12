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

const int N = 200020;

int main(){
    int n,m;
    cin >>n >>m;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    auto f = [&](int X){
        ll ret = 0;

        vector<bool> small(n);
        rep(i,n) small[i] = (a[i]<X);

        BIT b(2*N+10);
        int ct = 0;
        rep(i,n){
            if(small[i]) ++ct;
            else --ct;
            b.add(N+ct,1);
        }


        ct = 0;
        rep(i,n){
            ret += b.sum(N+ct-1);

            if(small[i]) ++ct;
            else --ct;
            b.add(N+ct,-1);
        }

        return ret;
    };

    cout << f(m) - f(m+1) << endl;
    return 0;
}
