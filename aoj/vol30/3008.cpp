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

using vi = vector<int>;
const int M = 10;

const vi ZERO(M,0);
vi I(M);

struct LazySegTree{
    int n;
    vector<vi> dat,lazy;
    //初期化
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<vi>(2*n-1,ZERO);
        lazy=vector<vi>(2*n-1,I);

        rep(i,_n) dat[i+(n-1)][0] = 1;
        for(int i=n-2; i>=0; --i) dat[i][0] = dat[2*i+1][0]+dat[2*i+2][0];
    }
    void setLazy(int k, const vi &f){
        if(k >= 2*n-1) return;

        vi inv[M];
        rep(i,M) inv[lazy[k][i]].pb(i);

        rep(i,M){
            int nx = f[i];
            for(int j:inv[i]) lazy[k][j] = nx;
        }
    }
    void push(int k, int l, int r){
        if(lazy[k] != I){
            setLazy(2*k+1,lazy[k]);
            setLazy(2*k+2,lazy[k]);
        }

        vi n_dat(ZERO);
        rep(i,M) n_dat[lazy[k][i]] += dat[k][i];
        dat[k] = n_dat;

        lazy[k] = I;
    }
    void fix(int k, int l, int r){
        push(2*k+1,l,r);
        push(2*k+2,l,r);
        rep(i,M) dat[k][i] = dat[2*k+1][i]+dat[2*k+2][i];
    }
    //内部的に投げられるクエリ
    void _change(int a, int b, int k, int l, int r,int x, int y){
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            vi f(I);
            f[x] = y;
            setLazy(k,f);
            return;
        }
        push(k,l,r);

        _change(a,b,2*k+1,l,(l+r)/2,x,y);
        _change(a,b,2*k+2,(l+r)/2,r,x,y);

        fix(k,l,r);
    }
    //[a,b)
    void change(int a, int b, int x, int y){
        return _change(a,b,0,0,n,x,y);
    }
    //内部的に投げられるクエリ
    int _count(int a, int b, int k, int l, int r, int x, int y){
        if(r<=a || b<=l) return 0;
        if(a<=l && r<=b){
            push(k,l,r);
            int ret = 0;
            for(int i=x; i<=y; ++i) ret += dat[k][i];
            return ret;
        }
        push(k,l,r);

        int vl=_count(a,b,2*k+1,l,(l+r)/2,x,y);
        int vr=_count(a,b,2*k+2,(l+r)/2,r,x,y);
        return vl+vr;
    }
    //[a,b)
    int count(int a, int b, int x, int y){
        return _count(a,b,0,0,n,x,y);
    }
};


const int N = 100010;
vector<int> G[N];

int L[N],R[N];
int sz = 0;

void dfs(int v, int p){
    L[v] = sz++;
    for(int e:G[v])if(e!=p) dfs(e,v);
    R[v] = sz++;
}

int main(){
    rep(i,M) I[i] = i;

    int n,q;
    scanf(" %d %d", &n, &q);

    rep(i,n-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }

    dfs(0,-1);

    LazySegTree s(sz);
    rep(i,q){
        int t,r,x,y;
        scanf(" %d %d %d %d", &t, &r, &x, &y);

        if(t==1) printf("%d\n", s.count(L[r],R[r]+1,x,y)/2);
        else s.change(L[r],R[r]+1,x,y);
    }
    return 0;
}
