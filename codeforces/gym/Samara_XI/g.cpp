#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct SegTree{
    int n;
    vector<ll> dat;
    SegTree(){}
    SegTree(int _n){
        n = 1;
        while(n<_n) n*=2;
        dat = vector<ll>(2*n-1,0);
    }

    void update(int k, ll a){
        k += n-1;
        dat[k] = a;
        while(k>0){
            k = (k-1)/2;
            dat[k] = dat[2*k+1] + dat[2*k+2];
        }
    }

    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;
        if(a<=l && r<=b) return dat[k];

        int mid = (l+r)/2;
        ll vl = _query(a,b,2*k+1,l,mid);
        ll vr = _query(a,b,2*k+2,mid,r);
        return vl+vr;
    }

    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

using P = pair<ll,int>;

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<ll> a(n);
    rep(i,n) scanf(" %lld", &a[i]);

    SegTree st[2],ct[2];
    rep(i,2){
        st[i] = SegTree(n);
        ct[i] = SegTree(n);
    }
    rep(i,n){
        st[i%2].update(i,a[i]);
        ct[i%2].update(i,1);
    }

    vector<P> v(n);
    rep(i,n) v[i]={a[i],i};
    sort(all(v));

    int w = k-1;
    ll ans = 0;
    rep(i,n) {
        int idx = v[i].se;
        int oe = (idx + w) % 2;

        int L = idx, R = n - 1 - idx;
        int xl = max(0, k - 1 - L), xr = min(k - 1, R);
        if (xl <= xr) {
            int l = idx-w+xl*2 , r = idx-w+xr*2;
            ll num = ct[oe].query(l, r + 1);
            ll sum = st[oe].query(l, r + 1);

//            printf(" idx : %d\n", idx);
//            printf("SUM %lld, num %lld\n", sum,num);
            ans += sum - num * a[idx];
        }

        ct[idx%2].update(idx,0);
        st[idx%2].update(idx,0);
    }

    printf("%lld\n", ans);
    return 0;
}