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

using pi = pair<int,int>;

const ll INF = LLONG_MAX/3;

struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N):n(N), d(N,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int X,int Y){
        X=root(X); Y=root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};

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

// 区間update, 区間min
struct LazySegTree{
    int n; vector<ll> dat,lazy;
    //初期化
    LazySegTree(){}
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,INF);
        lazy=vector<ll>(2*n-1,INF);
    }

    void setLazy(int k, ll v){
        lazy[k] = v;
        dat[k] = v;
    }

    void push(int k, int l, int r){
        if(lazy[k]!=INF){
            setLazy(2*k+1,lazy[k]);
            setLazy(2*k+2,lazy[k]);
        }
        lazy[k]=INF;
    }

    void fix(int k, int l, int r){
        dat[k]=min(dat[2*k+1],dat[2*k+2]);
    }

    ll merge(ll x, ll y){
        return min(x,y);
    }

    //内部的に投げられるクエリ
    void _update(int a, int b, ll x, int k, int l, int r){
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
    //[a,b)をx
    void update(int a, int b, ll x){
        return _update(a,b,x,0,0,n);
    }

    //内部的に投げられるクエリ
    ll _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return INF;
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


HL_decomposition hl;
LazySegTree st;

void _UPDATE(int p, int c, ll w){
    while(1){
        if(hl.head[p] == hl.head[c]){
            st.update(hl.vid[p]+1, hl.vid[c]+1, w);
            break;
        }
        else{
            st.update(hl.vid[hl.head[c]], hl.vid[c]+1, w);
            c = hl.par[hl.head[c]];
        }
    }
}

void UPDATE(int u, int v, ll w){
    int x = hl.lca(u,v);
    _UPDATE(x,u,w);
    _UPDATE(x,v,w);
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> a(m),b(m),w(m);
    rep(i,m){
        scanf(" %d %d %d", &a[i], &b[i], &w[i]);
        --a[i];
        --b[i];
        if(a[i]>b[i]) swap(a[i], b[i]);
    }

    vector<ll> ans(m,INF);

    // MST
    vector<pi> e;
    vector<bool> is_MST_edge(m,false);
    ll mst_cost = 0;

    rep(i,m) e.pb({w[i],i});
    sort(all(e));

    UF uf(n);
    rep(i,m){
        int idx = e[i].se;
        int u = a[idx], v = b[idx];
        if(!uf.same(u,v)){
            uf.unite(u,v);
            is_MST_edge[idx] = true;
            mst_cost += e[i].fi;
        }
    }

    // cannot construct MST
    if(uf.size(0) != n){
        rep(i,m) printf("-1\n");
        return 0;
    }

    rep(i,m)if(!is_MST_edge[i]) ans[i] = mst_cost;

    hl = HL_decomposition(n);
    rep(i,m)if(is_MST_edge[i]) hl.add_edge(a[i],b[i]);
    hl.build();

    st = LazySegTree(n);

    for(int i=m-1; i>=0; --i){
        int idx = e[i].se;
        int u = a[idx], v = b[idx];
        if(is_MST_edge[idx]) continue;

        UPDATE(u,v,e[i].fi);
    }

    map<pi,int> e2id;
    rep(i,m) e2id[{a[i],b[i]}] = i;

    for(int i=1; i<n; ++i){
        int p = hl.par[i];
        int idx = e2id[{min(i,p), max(i,p)}];

        ll val = st.query(hl.vid[i], hl.vid[i]+1);
        if(val == INF) continue;

        ans[idx] = val - w[idx] + mst_cost;
    }

    rep(i,m) printf("%lld\n", ans[i]==INF?-1:ans[i]);
    return 0;
}
