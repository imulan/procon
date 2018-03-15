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

struct HL_decomposition{
    int n;
    vector<vector<int>> G;
    vector<int> vid, inv, depth, par, heavy, head, sub;
    /*
    vid : HL分解後のグラフでの頂点ID
    inv : HL分解前のグラフでのvid[i]の頂点ID
    depth : rootからの距離
    par : 根付き木上での親
    heavy : heavy-path上における頂点iの次の頂点ID
    head : 頂点iが属するheavy-pathの先頭の頂点ID
    sub : 部分木のサイズ
    */

    HL_decomposition(){}
    HL_decomposition(int sz) : n(sz), G(n), vid(n), inv(n), depth(n), par(n), heavy(n,-1), head(n), sub(n) {}

    void add_edge(int u, int v){
        G[u].push_back(v);
        G[v].push_back(u);
    }

    void build(int root = 0){
        dfs(root, -1);
        dfs2(root);
    }

    void dfs(int cur, int pre){
        par[cur] = pre;
        sub[cur] = 1;
        int max_sub = 0;
        for(int nx:G[cur])if(nx != pre){
            depth[nx] = depth[cur] + 1;
            dfs(nx, cur);

            sub[cur] += sub[nx];
            if(max_sub < sub[nx]){
                max_sub = sub[nx];
                heavy[cur] = nx;
            }
        }
    }

    void dfs2(int root){
        int k = 0;
        stack<int> que({root});
        while(!que.empty()){
            int cur = que.top();
            que.pop();
            // curを先頭とするheavy-pathを処理
            for(int i=cur; i!=-1; i=heavy[i]){
                vid[i] = k++;
                inv[vid[i]] = i;
                head[i] = cur;
                // heavy-pathの先頭になるなら、queにpushする
                for(int nx:G[i])if(nx != par[i] && nx != heavy[i]){
                    que.push(nx);
                }
            }
        }
    }

    int lca(int u, int v){
        while(1){
            if(vid[u] > vid[v]) swap(u,v);
            if(head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
};

// 区間add, 区間sum
struct LazySegTree{
    int n; vector<ll> dat,lazy;
    //初期化
    LazySegTree(){}
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
            setLazy(2*k+1,lazy[k]/2);
            setLazy(2*k+2,lazy[k]/2);
        }
        lazy[k]=0;
    }

    void fix(int k, int l, int r){
        dat[k]=dat[2*k+1]+dat[2*k+2];
    }

    ll merge(ll x, ll y){
        return x+y;
    }

    //内部的に投げられるクエリ
    void _add(int a, int b, ll x, int k, int l, int r){
        if(r<=a || b<=l) return;
        if(a<=l && r<=b){
            setLazy(k,x*(r-l));
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

HL_decomposition hl;
LazySegTree st;

ll LEN(int u, int v){
    ll ret = 0;
    while(1){
        if(hl.vid[u] > hl.vid[v]) swap(u,v);

        if(hl.head[u] == hl.head[v]){
            ret += st.query(hl.vid[u]+1, hl.vid[v]+1);
            break;
        }
        else{
            ret += st.query(hl.vid[hl.head[v]], hl.vid[v]+1);
            v = hl.par[hl.head[v]];
        }
    }
    return ret;
}

ll DIST(int u, int v){
    int a = hl.lca(u,v);
    return LEN(a,u)+LEN(a,v);
}

void ADD(int v, int x){
    int sz = hl.sub[v];
    st.add(hl.vid[v]+1, hl.vid[v]+sz, x);
}

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    hl = HL_decomposition(n);
    st = LazySegTree(n);

    rep(i,n-1){
        int a,b;
        scanf(" %d %d", &a, &b);
        hl.add_edge(a,b);
    }
    hl.build();
    // rep(i,n) printf(" %d -> %d\n", i, hl.vid[i]);

    while(q--){
        int c,x,y;
        scanf(" %d %d %d", &c, &x, &y);
        if(c==0) printf("%lld\n", DIST(x,y));
        else ADD(x,y);
    }

    return 0;
}
