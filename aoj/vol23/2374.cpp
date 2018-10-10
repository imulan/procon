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

const int INF = 19191919;

struct LazySegTree{
    int n; vector<int> mx,mn,lazy;
    //初期化
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        mx = vector<int>(2*n-1,0);
        mn = vector<int>(2*n-1,0);
        lazy=vector<int>(2*n-1,0);
    }

    void init(const vector<int> &v){
        int V = v.size();
        rep(i,V){
            int idx = i + n-1;
            mx[idx] = v[i];
            mn[idx] = v[i];
        }
        for(int i=n-2; i>=0; --i){
            mx[i] = mx[2*i+1];
            mn[i] = mn[2*i+2];
        }
    }

    void setLazy(int k, int v){
        lazy[k] += v;
        mx[k] += v;
        mn[k] += v;
    }

    void push(int k, int l, int r){
        if(lazy[k]!=0){
            setLazy(2*k+1,lazy[k]);
            setLazy(2*k+2,lazy[k]);
        }
        lazy[k]=0;
    }

    void fix(int k, int l, int r){
        mx[k] = mx[2*k+1];
        mn[k] = mn[2*k+2];
    }

    int merge(int x, int y){
        return min(x,y);
    }

    //内部的に投げられるクエリ
    void _add(int a, int b, int x, int k, int l, int r){
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
    void add(int a, int b, int x){
        return _add(a,b,x,0,0,n);
    }

    //内部的に投げられるクエリ
    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return INF;
        if(a<=l && r<=b) return mn[k];

        push(k,l,r);
        int vl=_query(a,b,2*k+1,l,(l+r)/2);
        int vr=_query(a,b,2*k+2,(l+r)/2,r);
        return merge(vl,vr);
    }
    //[a,b)の最小値
    int query(int a, int b){
        return _query(a,b,0,0,n);
    }

    int _lb(int v, int k, int l, int r){
        if(r-l==1){
            if(mn[k]>=v) return l;
            return -1;
        }
        push(k,l,r);
        // printf(" k %d (%d %d)  mx[2*k+2] = %d\n",k,l,r,mx[2*k+2]);
        if(mx[2*k+2] >= v) return _lb(v,2*k+2,(l+r)/2,r);
        else return _lb(v,2*k+1,l,(l+r)/2);
    }

    int lb_idx(int v){
        return _lb(v,0,0,n);
    }
};

int main(){
    int M,N,m0,md,n0,nd;
    cin >>M >>N >>m0 >>md >>n0 >>nd;

    vector<int> m(M),n(N);
    m[0] = m0;
    for(int i=1; i<M; ++i) m[i] = (m[i-1]*58 + md)%(N+1);
    n[0] = n0;
    for(int i=1; i<N; ++i) n[i] = (n[i-1]*58 + nd)%(M+1);

    sort(all(n), greater<int>());
    // dbg(m); dbg(n);

    LazySegTree st(N);
    st.init(n);

    ll ans = 0;
    rep(i,M){
        // 何個取れるか
        int num = min(m[i], st.lb_idx(1)+1);
        // dbg(num);
        if(num <= 0) continue;

        int val = st.query(num-1,num);
        int lidx = st.lb_idx(val+1);
        int ridx = st.lb_idx(val);
        // dbg(val); dbg(lidx); dbg(ridx);

        int rem = num - (lidx+1);
        st.add(0,lidx+1,-1);
        st.add(ridx-rem+1,ridx+1,-1);

        ans += num;

        // printf("--- now\n");
        // rep(j,N) printf(" %d", st.query(j,j+1));
        // puts("");
    }
    cout << ans << endl;
    return 0;
}
