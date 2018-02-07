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
    int n;
    vector<ll> dat;
    vector<int> lazy;
    //初期化
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
        lazy=vector<int>(2*n-1,0);
    }

    void setLazy(int k, int l, int r){
        lazy[k] ^= 1;
        dat[k] = (r-l) - dat[k];
    }

    void push(int k, int l, int r){
        if(lazy[k]){
            setLazy(2*k+1,l,(l+r)/2);
            setLazy(2*k+2,(l+r)/2,r);
        }
        lazy[k]=0;
    }

    void fix(int k, int l, int r){
        dat[k] = dat[2*k+1]+dat[2*k+2];
    }

    ll merge(ll x, ll y){
        return x+y;
    }

    //内部的に投げられるクエリ
    void _flip(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            setLazy(k,l,r);
            return;
        }

        push(k,l,r);
        _flip(a,b,2*k+1,l,(l+r)/2);
        _flip(a,b,2*k+2,(l+r)/2,r);

        fix(k,l,r);
    }
    //[a,b)
    void flip(int a, int b){
        return _flip(a,b,0,0,n);
    }

    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 0;
        if(a<=l && r<=b) return dat[k];

        push(k,l,r);
        ll vl=_query(a,b,2*k+1,l,(l+r)/2);
        ll vr=_query(a,b,2*k+2,(l+r)/2,r);
        return merge(vl,vr);
    }
    //[a,b)のsum
    ll query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

const int N = 200000;
vector<int> G[N];
vector<int> et;
vector<int> idx[N];

void dfs(int x){
    et.pb(x);
    for(int ch:G[x]) dfs(ch);
    et.pb(x);
}

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n;
    cin >>n;
    for(int i=1; i<n; ++i){
        int p;
        cin >>p;
        --p;
        G[p].pb(i);
    }

    dfs(0);

    int ET = et.size();
    rep(i,ET) idx[et[i]].pb(i);

    LazySegTree st(ET);
    rep(i,n){
        int t;
        cin >>t;
        if(t==1){
            rep(j,2){
                int X = idx[i][j];
                st.flip(X,X+1);
            }
        }
    }

    int Q;
    cin >>Q;
    while(Q--){
        string op;
        int v;
        cin >>op >>v;
        --v;

        int l=idx[v][0], r=idx[v][1];
        if(op=="get") cout << st.query(l,r+1)/2 << endl;
        else st.flip(l,r+1);
    }
    return 0;
}
