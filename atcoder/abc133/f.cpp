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

using pl = pair<ll,ll>;

struct SegTree{
    int n; vector<pl> dat;
    // 初期化
    SegTree(){}
    SegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<pl>(2*n-1,{0,0});
    }
    // k番目(0-indexed)の値をaに変更
    void update(int k, pl a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k].fi = dat[2*k+1].fi+dat[2*k+2].fi;
            dat[k].se = dat[2*k+1].se+dat[2*k+2].se;
        }
    }
    // 内部的に投げられるクエリ
    pl _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return {0,0};

        if(a<=l && r<=b) return dat[k];

        pl vl=_query(a,b,2*k+1,l,(l+r)/2);
        pl vr=_query(a,b,2*k+2,(l+r)/2,r);
        return {vl.fi+vr.fi, vl.se+vr.se};
    }
    // [a,b)
    pl query(int a, int b){
        return _query(a,b,0,0,n);
    }
};


// example
HL_decomposition hl;
SegTree st;

pl _QUERY(int p, int c){
    pl ret(0,0);
    while(1){
        if(hl.head[p] == hl.head[c]){
            pl add = st.query(hl.vid[p]+1, hl.vid[c]+1);
            ret = {ret.fi+add.fi, ret.se+add.se};
            break;
        }
        else{
            pl add = st.query(hl.vid[hl.head[c]], hl.vid[c]+1);
            ret = {ret.fi+add.fi, ret.se+add.se};
            c = hl.par[hl.head[c]];
        }
    }
    return ret;
}

pl QUERY(int u, int v){
    int x = hl.lca(u,v);
    pl L = _QUERY(x,u);
    pl R = _QUERY(x,v);
    return {L.fi+R.fi, L.se+R.se};
}

void UPDATE(int u, pl pp){
    st.update(hl.vid[u], pp);
}

const int INF = 1000000001;

int main(){
    int n,q;
    scanf(" %d %d", &n, &q);

    hl = HL_decomposition(n);

    vector<int> a(n),b(n),c(n),d(n);
    vector<vector<pair<int,int>>> graph(n);
    rep(i,n-1){
        scanf(" %d %d %d %d", &a[i], &b[i], &c[i], &d[i]);
        --a[i];
        --b[i];
        hl.add_edge(a[i],b[i]);
        graph[a[i]].pb({b[i],d[i]});
        graph[b[i]].pb({a[i],d[i]});
    }
    hl.build();

    vector<int> d0(n,INF);
    d0[0] = 0;
    queue<int> que({0});
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(const auto &e:graph[now]){
            if(d0[e.fi] > d0[now]+e.se){
                d0[e.fi] = d0[now]+e.se;
                que.push(e.fi);
            }
        }
    }

    vector<vector<int>> col_edge(n);
    rep(i,n-1){
        if(d0[a[i]] > d0[b[i]]) swap(a[i],b[i]);
        col_edge[c[i]].pb(i);
    }

    vector<int> x(q),y(q),u(q),v(q);
    vector<vector<int>> query(n);
    rep(i,q){
        scanf(" %d %d %d %d", &x[i], &y[i], &u[i], &v[i]);
        --u[i];
        --v[i];
        query[x[i]].pb(i);
    }

    st = SegTree(n);
    vector<int> ans(q);
    rep(col,n)if(!query[col].empty()){
        for(int i:col_edge[col]) UPDATE(b[i],{1,d[i]});

        for(int i:query[col]){
            pl res = QUERY(u[i], v[i]);
            // dbg(i);
            // dbg(res);
            // printf(" %d - %d :: lca %d\n",u[i],v[i],hl.lca(u[i],v[i]));
            ans[i] = d0[u[i]]+d0[v[i]]-2*d0[hl.lca(u[i],v[i])];
            ans[i] -= res.se;
            ans[i] += res.fi*y[i];
        }

        for(int i:col_edge[col]) UPDATE(b[i],{0,0});
    }
    rep(i,q) printf("%d\n", ans[i]);
    return 0;
}
