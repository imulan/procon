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

//ノードの個数
const int MAX_V = 2002;
//ダブリングに必要なサイズ(log(MAX_V))
const int MAX_LOG_V = 11;
//木の隣接リスト表現
vector<int> G[MAX_V];
//根のノード番号
int root = 0;

//親を2^k回辿って到達するノード(根を通り過ぎる場合,-1)
int parent[MAX_LOG_V][MAX_V];
//根からの深さ
int depth[MAX_V];

//現在vに注目、親はp、深さd
void lca_dfs(int v, int p, int d){
    parent[0][v]=p;
    depth[v]=d;
    rep(i,G[v].size()){
        if(G[v][i]!=p){ //親でなければ子
            lca_dfs(G[v][i], v, d+1);
        }
    }
}

//初期化
void lca_init(int V){
    //parent[0]とdepthの初期化
    lca_dfs(root, -1, 0);
    //parentの初期化
    for(int k=0; k+1<MAX_LOG_V; ++k){
        for(int v=0; v<V; ++v){
            if(parent[k][v] < 0) parent[k+1][v]=-1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

//uとvのLCAを求める
int lca(int u, int v){
    //uとvの深さが同じになるまで親を辿る
    if(depth[u] > depth[v]) swap(u,v);
    for(int k=0; k<MAX_LOG_V; ++k){
        if((depth[v]-depth[u])>>k & 1) v = parent[k][v];
    }
    if(u==v) return u;
    //二分探索でLCAを求める
    for(int k=MAX_LOG_V-1; k>=0; --k){
        if(parent[k][u] != parent[k][v]){
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}

const int N = 2002;
int n;
int c[N];

// dist from root
int d[N];
void calc_dist(int v, int par){
    for(int e:G[v])if(e!=par){
        d[e] = d[v]+c[e];
        calc_dist(e,v);
    }
}

const int B = 10000;
const int SZ = 100;

int main(){
    scanf(" %d", &n);
    rep(i,n) scanf(" %d", &c[i]);

    rep(i,n-1){
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    lca_init(n);

    int q;
    scanf(" %d", &q);

    vector<pair<int,int>> upd;
    rep(i,B){
        for(const auto &p:upd) c[p.fi] += p.se;
        upd.clear();

        d[root] = c[root];
        calc_dist(root, -1);

        rep(j,SZ){
            if(i*SZ + j == q) return 0;

            int type,x,y;
            scanf(" %d %d %d", &type, &x, &y);
            if(type == 0){
                // move x -> y
                --x;
                --y;
                int l = lca(x,y);
                if(l == y) swap(x,y);

                int ans = d[x]+d[y]-c[l];
                int par_l = parent[0][l];
                if(par_l != -1) ans -= 2*d[par_l];

                for(const auto &p:upd){
                    int v = p.fi;
                    int val = p.se;

                    bool on_path = false;
                    int vx = lca(v,x), vy = lca(v,y);
                    if(l == x){
                        if(vy==v && vx==x) on_path = true;
                    }
                    else{
                        if(v==l) on_path = true;
                        else{
                            if(vx != vy){
                                if(vx==l && vy==v) on_path = true;
                                if(vx==v && vy==l) on_path = true;
                            }
                        }
                    }

                    if(on_path) ans += val;
                }

                printf("%d\n", ans);
            }
            else{
                // update c[x] <- y
                --x;
                upd.pb({x,y});
            }
        }
    }


    return 0;
}
