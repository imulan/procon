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

struct SegTree{
    int n; vector<ll> dat;
    // 初期化
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    // k番目(0-indexed)の値をaに変更
    void update(int k, ll a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=dat[2*k+1]+dat[2*k+2];
        }
    }
    // 内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;

        if(a<=l && r<=b) return dat[k];

        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }
    // [a,b)
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    int n,d,a;
    cin >>n >>d >>a;

    vector<pair<int,int>> v(n);
    vector<int> ux(n);
    rep(i,n){
        int x,h;
        cin >>x >>h;
        h = (h+a-1)/a;
        v[i] = {x,h};
        ux[i] = x;
    }
    sort(all(v));
    sort(all(ux));

    ll ans = 0;
    SegTree st(n);
    rep(i,n){
        int x = v[i].fi-2*d;
        int idx = lower_bound(all(ux),x) - ux.begin();

        ll add = max(0LL, v[i].se-st.query(idx,i));
        st.update(i,add);
        ans += add;
    }
    cout << ans << "\n";
    return 0;
}
