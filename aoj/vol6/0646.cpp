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
        ++i;
        ll s = 0;
        while(i>0){
            s += bit[i];
            i -= i & -i;
        }
        return s;
    }
    // add x in i-th element
    void add(int i, ll x){
        ++i;
        while(i<=n){
            bit[i] += x;
            i += i & -i;
        }
    }
};

int main(){
    int n,K;
    ll L;
    cin >>n >>K >>L;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    // k番目の数がx以下である区間がいくつあるかを数える
    auto check = [&](int x){
        vector<bool> s(n);
        rep(i,n) s[i] = (a[i]<=x);

        int ct = 0;
        rep(i,K-1) ct += s[i];

        const int N = 200020;
        BIT b(N+10);
        vector<int> t(n);
        for(int i=K-1; i<n;++i){
            ct += s[i];
            t[i] = ct;
            b.add(t[i],1);
        }

        ct = 0;
        ll num = 0;
        rep(i,n-K+1){
            num += b.sum(N)-b.sum(K-1+ct);
            ct += s[i];
            b.add(t[i],-1);
        }

        // printf(" %d: %lld\n", x,num);
        return num >= L;
    };

    int l=0, r=n;
    while(r-l>1){
        int m = (l+r)/2;
        if(check(m)) r=m;
        else l=m;
    }
    cout << r << endl;
    return 0;
}
