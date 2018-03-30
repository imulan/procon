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

struct LazySegTree{
    int n; vector<int> dat,lazy;
    //初期化
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<int>(2*n-1,0);
        lazy=vector<int>(2*n-1,0);
    }

    void setLazy(int k, int v){
        lazy[k] = v;
        dat[k] = v;
    }

    void push(int k, int l, int r){
        if(lazy[k]!=0){
            setLazy(2*k+1,lazy[k]);
            setLazy(2*k+2,lazy[k]);
        }
        lazy[k]=0;
    }

    void fix(int k, int l, int r){
        dat[k] = dat[2*k+1]&dat[2*k+2];
    }

    int merge(int x, int y){
        return x&y;
    }

    //内部的に投げられるクエリ
    void _update(int a, int b, int x, int k, int l, int r){
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            setLazy(k,x);
            return;
        }

        push(k,l,r);
        _update(a,b,x,2*k+1,l,(l+r)/2);
        _update(a,b,x,2*k+2,(l+r)/2,r);

        fix(k,l,r);
    }
    //[a,b)をxに更新
    void update(int a, int b, int x){
        return _update(a,b,x,0,0,n);
    }

    //内部的に投げられるクエリ
    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 1;
        if(a<=l && r<=b) return dat[k];

        push(k,l,r);
        int vl=_query(a,b,2*k+1,l,(l+r)/2);
        int vr=_query(a,b,2*k+2,(l+r)/2,r);
        return merge(vl,vr);
    }
    //[a,b)
    int query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

const int N = 200000;
vector<int> C[N],Q[N];

int main(){
    int n,m,q;
    scanf(" %d %d %d", &n, &m, &q);

    vector<int> d(m),a(m),b(m);
    rep(i,m) scanf(" %d %d %d", &d[i], &a[i], &b[i]);

    vector<int> e(q),s(q),t(q);
    rep(i,q) scanf(" %d %d %d", &e[i], &s[i], &t[i]);

    vector<int> v;
    rep(i,m) v.pb(d[i]);
    rep(i,q) v.pb(e[i]);
    sort(all(v));
    v.erase(unique(all(v)), v.end());
    int V = v.size();

    rep(i,m){
        int idx = lower_bound(all(v), d[i])-v.begin();
        C[idx].pb(i);
    }
    rep(i,q){
        int idx = lower_bound(all(v), e[i])-v.begin();
        Q[idx].pb(i);
    }

    LazySegTree st(n);
    vector<bool> ans(q);
    rep(i,V){
        for(int &ID:Q[i]) ans[ID] = st.query(s[ID], t[ID]);
        for(int &ID:C[i]) st.update(a[ID], b[ID], 1);
    }
    rep(i,q) printf("%s\n", (ans[i]?"Yes":"No"));
    return 0;
}
