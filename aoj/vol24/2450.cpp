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

HL_decomposition hl;

struct Seg{
    // 左端 / 右端になる時のbest
    ll l,r;
    // 全体の和
    ll w;

    // 部分和の最大値
    ll mx;
    // mxが0になる時、空にならないためマシな値を持つ
    ll nb;

    // 区間内の要素数
    int sz;

    Seg(){
        sz = 0;
    }
    Seg(int val){
        sz = 1;
        w = val;

        l = r = mx = 0;
        if(val>=0) l = r = mx = val;

        nb = val;
    }

    void show(){
        printf("l,r,w %lld %lld %lld  mx %lld  nb %lld, sz(%d)\n",l,r,w,mx,nb,sz);
    }
};

Seg MERGE(Seg lh, Seg rh){
    if(lh.sz == 0) return rh;
    if(rh.sz == 0) return lh;

    Seg ret;
    ret.sz = lh.sz + rh.sz;

    ret.l = max(rh.l, lh.l + rh.w);
    if(ret.l < 0) ret.l = 0;

    ret.r = max(lh.r, lh.w + rh.r);
    if(ret.r < 0) ret.r = 0;

    ret.w = lh.w + rh.w;

    ret.mx = max({lh.mx, rh.mx, lh.l+rh.r});
    ret.nb = max(lh.nb, rh.nb);
    return ret;
}

Seg REV(Seg s){
    swap(s.l, s.r);
    return s;
}

ll INF = 19191919;
struct LazySegTree{
    int n;
    vector<ll> lazy;
    vector<Seg> dat;

    //初期化
    LazySegTree(){}
    LazySegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat = vector<Seg>(2*n-1);
        lazy = vector<ll>(2*n-1,INF);
    }

    void init(const vector<int> &w){
        int sz = w.size();
        rep(i,sz){
            int idx = hl.vid[i] + n-1;
            dat[idx] = Seg(w[i]);
        }
        for(int i=n-2; i>=0; --i) dat[i] = MERGE(dat[2*i+1],dat[2*i+2]);
    }

    void setLazy(int k, ll v){
        lazy[k] = v;

        dat[k].w = v*dat[k].sz;

        if(v>=0){
            dat[k].l = dat[k].r = dat[k].mx = dat[k].nb = dat[k].w;
        }
        else{
            dat[k].l = dat[k].r = dat[k].mx = 0;
            dat[k].nb = v;
        }
    }

    void push(int k, int l, int r){
        if(lazy[k]!=INF){
            setLazy(2*k+1,lazy[k]);
            setLazy(2*k+2,lazy[k]);
        }
        lazy[k]=INF;
    }

    void fix(int k, int l, int r){
        dat[k] = MERGE(dat[2*k+1],dat[2*k+2]);
    }

    Seg merge(Seg x, Seg y){
        return MERGE(x,y);
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
    //[a,b)をxに更新
    void update(int a, int b, ll x){
        return _update(a,b,x,0,0,n);
    }

    //内部的に投げられるクエリ
    Seg _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return Seg();
        if(a<=l && r<=b) return dat[k];

        push(k,l,r);
        Seg vl=_query(a,b,2*k+1,l,(l+r)/2);
        Seg vr=_query(a,b,2*k+2,(l+r)/2,r);
        return merge(vl,vr);
    }
    //[a,b)
    Seg query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

LazySegTree st;

void _UPDATE(int p, int c, int val){
    while(1){
        if(hl.head[p] == hl.head[c]){
            st.update(hl.vid[p], hl.vid[c]+1, val);
            break;
        }
        else{
            st.update(hl.vid[hl.head[c]], hl.vid[c]+1, val);
            c = hl.par[hl.head[c]];
        }
    }
}

void UPDATE(int u, int v, int val){
    int lca = hl.lca(u,v);
    _UPDATE(lca,u,val);
    _UPDATE(lca,v,val);
}

ll QUERY(int u, int v){
    int p = hl.lca(u,v);

    Seg sl,sr;

    // printf(" u -> p  %d %d\n",u,p);
    int c = u;
    while(1){
        if(hl.head[p] == hl.head[c]){
            Seg as = st.query(hl.vid[p], hl.vid[c]+1);
            as = REV(as);
            sl = MERGE(sl, as);

            // printf(" (%d %d)\n", p, c);
            // as.show();
            // sl.show();
            break;
        }
        else{
            Seg as = st.query(hl.vid[hl.head[c]], hl.vid[c]+1);
            as = REV(as);
            sl = MERGE(sl, as);

            // printf(" (%d %d)\n", hl.head[c], c);
            // as.show();
            // sl.show();
            c = hl.par[hl.head[c]];
        }
    }

    // printf(" v -> p  %d %d\n",v,p);
    c = v;
    while(1){
        if(hl.head[p] == hl.head[c]){
            Seg as = st.query(hl.vid[p]+1, hl.vid[c]+1);
            sr = MERGE(as, sr);

            // printf(" (%d %d)\n", p, c);
            // sr.show();
            break;
        }
        else{
            Seg as = st.query(hl.vid[hl.head[c]], hl.vid[c]+1);
            sr = MERGE(as, sr);

            // printf(" (%d %d)\n", hl.head[c], c);
            // sr.show();
            c = hl.par[hl.head[c]];
        }
    }

    Seg res = MERGE(sl,sr);
    // res.show();
    ll ans = res.mx;
    if(ans == 0) ans = res.nb;
    return ans;
}

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    hl = HL_decomposition(n);
    st = LazySegTree(n);

    vector<int> w(n);
    rep(i,n) scanf(" %d", &w[i]);

    rep(i,n-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        hl.add_edge(u,v);
    }

    hl.build();
    st.init(w);

    rep(i,q){
        int t,a,b,c;
        scanf(" %d %d %d %d", &t, &a, &b, &c);
        --a;
        --b;
        if(t==1) UPDATE(a,b,c);
        else printf("%lld\n", QUERY(a,b));
    }
    return 0;
}
