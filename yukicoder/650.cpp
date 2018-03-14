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

const ll mod = 1e9+7;

using vl = vector<ll>;
using mat = vector<vl>;

const mat E({{1,0},{0,1}});

mat mul(const mat &A, const mat &B){
    mat C(2,vl(2));
    rep(i,2)rep(j,2){
        rep(k,2) (C[i][j] += A[i][k]*B[k][j]) %= mod;
    }
    return C;
}

struct MatSegTree{
    int n; vector<mat> dat;
    //初期化
    MatSegTree(){}
    MatSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<mat>(2*n-1,E);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, const mat &a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=mul(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    mat _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return E;

        if(a<=l && r<=b) return dat[k];

        mat ml=_query(a,b,2*k+1,l,(l+r)/2);
        mat mr=_query(a,b,2*k+2,(l+r)/2,r);
        return mul(ml,mr);
    }
    //[a,b)
    mat query(int a, int b){
        return _query(a,b,0,0,n);
    }
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
        bfs(root);
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

    void bfs(int root){
        int k = 0;
        queue<int> que({root});
        while(!que.empty()){
            int cur = que.front();
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
MatSegTree st;

mat query(int x, int y){
    mat ret = E;
    if(x!=y){
        while(1){
            if(hl.vid[x] > hl.vid[y]) swap(x,y);

            if(hl.head[x] == hl.head[y]){
                ret = mul(st.query(hl.vid[x]+1,hl.vid[y]+1), ret);
                break;
            }
            else{
                ret = mul(st.query(hl.vid[hl.head[y]],hl.vid[y]+1), ret);
                y = hl.par[ hl.head[y]];
            }
        }
    }
    return ret;
}

int main(){
    int n;
    scanf(" %d", &n);

    hl = HL_decomposition(n);
    st = MatSegTree(n);

    vector<int> a(n-1), b(n-1);
    rep(i,n-1){
        scanf(" %d %d", &a[i], &b[i]);
        hl.add_edge(a[i],b[i]);
    }
    hl.build();

    int q;
    scanf(" %d", &q);
    while(q--){
        char c;
        scanf(" %c", &c);
        if(c=='x'){
            int eid;
            scanf(" %d", &eid);
            mat m(2,vl(2));
            rep(i,2)rep(j,2) scanf(" %lld", &m[i][j]);

            // update value
            int u = a[eid], v = b[eid];
            // 辺に対するクエリだが、子の頂点で代用する
            if(hl.depth[u] > hl.depth[v]) swap(u,v);
            int idx = hl.vid[v];
            st.update(idx, m);
        }
        else{
            int u,v;
            scanf(" %d %d", &u, &v);
            // u is ancestor of v

            mat ans = query(u,v);
            rep(i,2)rep(j,2){
                if(i!=0 || j!=0) printf(" ");
                printf("%lld", ans[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
