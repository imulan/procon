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
const int MAX_V = 100000;
//ダブリングに必要なサイズ(log(MAX_V))
const int MAX_LOG_V = 17;
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

const int X = 250;

const int N = 100000;
int ct[N]={};
int b[N],a[N];

vector<int> v[N][2];

ll dp[N][2];
void dfs(int x, int p, int col){
    if(p!=-1){
        rep(i,2) dp[x][i] = dp[p][i];
    }
    if(a[x] == col) ++dp[x][b[x]];

    for(int e:G[x])if(e!=p){
        dfs(e,x,col);
    }
}

inline bool on_path(int p, int q, int x){
    int lu = lca(p,x);
    int lv = lca(q,x);
    int LCA = lca(p,q);

    return ((lu == x && lv == LCA) || (lv == x && lu == LCA));
}

int main(){
    int n;
    scanf(" %d", &n);

    rep(i,n) scanf(" %d", &b[i]);
    rep(i,n) scanf(" %d", &a[i]);

    rep(i,n-1){
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        G[x].pb(y);
        G[y].pb(x);
    }
    lca_init(n);

    int q;
    scanf(" %d", &q);
    vector<int> x(q),y(q);
    vector<int> LCA(q);
    rep(i,q){
        scanf(" %d %d", &x[i], &y[i]);
        --x[i];
        --y[i];
        LCA[i] = lca(x[i],y[i]);
    }

    vector<int> sa(a, a+n);
    sort(all(sa));
    sa.erase(unique(all(sa)), sa.end());
    rep(i,n){
        a[i] = lower_bound(all(sa), a[i]) - sa.begin();
        ++ct[a[i]];
    }

    vector<int> small,large;
    rep(i,N)if(ct[i]>0){
        if(ct[i]<=X) small.pb(i);
        else large.pb(i);
    }

    rep(i,n) v[a[i]][b[i]].pb(i);

    // if(n==100000){
    //     if(large.size()>100){
    //         dbg(large.size());
    //         return 0;
    //     }
    // }

    vector<ll> LL(q);
    rep(i,large.size()){
        int col = large[i];
        memset(dp,0,sizeof(dp));
        dfs(0,-1,col);

        // printf(" --- col %d ---\n", col);
        rep(i,q){
            ll zero = dp[x[i]][0]+dp[y[i]][0]-2*dp[LCA[i]][0];
            ll one = dp[x[i]][1]+dp[y[i]][1]-2*dp[LCA[i]][1];
            if(a[LCA[i]] == col){
                if(b[LCA[i]]==0) ++zero;
                else ++one;
            }
            // printf(" col %d,  i %d  %lld * %lld\n", col,i,zero,one);
            LL[i] += zero*one;
        }
    }


    rep(qid,q){
        ll res = LL[qid];
        for(int i:small){
            int sz = v[i][0].size();
            int szz = v[i][1].size();

            rep(j,sz){
                if(!on_path(x[qid],y[qid],v[i][0][j])) continue;
                rep(k,szz){
                    if(on_path(x[qid],y[qid],v[i][1][k])) ++res;
                }
            }
        }
        printf("%lld\n", res);
    }

    return 0;
}
