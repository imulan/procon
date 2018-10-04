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

// 区間add, 区間min
struct LazySegTree{
    int n; vector<ll> dat,lazy;
    //初期化
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
        lazy=vector<ll>(2*n-1,0);
    }

    void setLazy(int k, ll v){
        lazy[k] += v;
        dat[k] += v;
    }

    void push(int k, int l, int r){
        if(lazy[k]!=0){
            setLazy(2*k+1,lazy[k]);
            setLazy(2*k+2,lazy[k]);
        }
        lazy[k]=0;
    }

    void fix(int k, int l, int r){
        dat[k]=min(dat[2*k+1],dat[2*k+2]);
    }

    ll merge(ll x, ll y){
        return min(x,y);
    }

    //内部的に投げられるクエリ
    void _add(int a, int b, ll x, int k, int l, int r){
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            setLazy(k,x);
            return;
        }

        push(k,l,r);
        _add(a,b,x,2*k+1,l,(l+r)/2);
        _add(a,b,x,2*k+2,(l+r)/2,r);

        fix(k,l,r);
    }
    //[a,b)に+x
    void add(int a, int b, ll x){
        return _add(a,b,x,0,0,n);
    }

    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return LLONG_MAX/2;
        if(a<=l && r<=b) return dat[k];

        push(k,l,r);
        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return merge(vl,vr);
    }
    //[a,b)の最小値
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

int main(){
    cin.tie(0);ios::sync_with_stdio(false);

    int n,Q;
    string s;
    cin >>n >>Q >>s;

    LazySegTree st(n);

    vector<int> a(n);
    set<int> r;
    rep(i,n){
        if(s[i] == '(') a[i] = 1;
        else{
            a[i] = -1;
            r.insert(i);
        }
        st.add(i,n+1,a[i]);
    }

    rep(i,Q){
        int q;
        cin >>q;
        --q;

        int ans = -1;
        if(a[q] == 1){
            st.add(q,n+1,-2);

            r.insert(q);
            ans = *r.begin();
            r.erase(ans);

            st.add(ans,n+1,2);
        }
        else{
            st.add(q,n+1,2);

            int ok=n-1, ng=0;
            while(ok-ng>1){
                int mid = (ok+ng)/2;
                if(st.query(mid,n+1)>=2) ok = mid;
                else ng = mid;
            }
            ans = ok;

            r.erase(q);
            r.insert(ans);
            st.add(ans,n+1,-2);
        }

        a[q] *= -1;
        a[ans] *= -1;
        printf("%d\n", ans+1);
    }

    return 0;
}
