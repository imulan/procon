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

//ノードの個数
const int MAX_V = 300003;
//ダブリングに必要なサイズ(log(MAX_V))
const int MAX_LOG_V = 19;
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

const int N = MAX_V;
const ll mod = 998244353;
int n,k;
int a[N];

int L[N];
bool invalid = false;

ll dp[N][2]={};
int dfs(int x, int par){
    map<int,int> m;
    for(int e:G[x])if(e!=par){
        int res = dfs(e,x);
        if(res != 0) m[e] = res;
    }

    if(m.empty()){
        int idx = (a[x]!=0);
        dp[x][idx] = 1;

        if(L[a[x]] == x) return -1;
        return a[x];
    }

    unordered_set<int> s;
    vector<int> ch;
    for(const auto &p:m){
        ch.pb(p.fi);
        if(p.se != -1) s.insert(p.se);
    }

    if(s.size() > 1){
        invalid = true;
        return 0;
    }

    if(a[x]==0 && s.size()==0){
        dp[x][0] = 1;
        for(int v:ch) (dp[x][0] *= (dp[v][0]+dp[v][1])) %= mod;

        int C = ch.size();
        vector<ll> pre(C),suf(C);
        rep(i,C) pre[i] = suf[i] = (dp[ch[i]][0]+dp[ch[i]][1])%mod;

        rep(i,C-1) (pre[i+1] *= pre[i]) %= mod;
        for(int i=C-1; i>0; --i) (suf[i-1] *= suf[i]) %= mod;

        dp[x][1] = 0;
        rep(i,C){
            ll mul = 1;
            if(i!=0) (mul *= pre[i-1]) %= mod;
            if(i!=C-1) (mul*= suf[i+1]) %= mod;

            ll add = (mul*dp[ch[i]][1])%mod;
            (dp[x][1] += add) %= mod;
        }

        return -1;
    }
    else{
        int col = a[x];
        if(!s.empty()){
            assert(s.size()==1);
            int h = *s.begin();
            if(col!=0 && col!=h){
                invalid = true;
                return 0;
            }
            col = h;
        }

        dp[x][1] = 1;
        for(int v:ch){
            if(m[v]==-1) (dp[x][1] *= (dp[v][0]+dp[v][1])) %= mod;
            else (dp[x][1] *= dp[v][1]) %= mod;
        }

        return (x==L[col])?-1:col;
    }
}

int main(){
    scanf(" %d %d", &n, &k);

    vector<vector<int>> col(k+1);
    rep(i,n){
        scanf(" %d", &a[i]);
        col[a[i]].pb(i);
    }
    rep(i,n-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    lca_init(n);
    for(int i=1; i<=k; ++i){
        int x = col[i][0];
        for(int j:col[i]) x = lca(x,j);

        if(a[x]!=0 && a[x]!=i) invalid = true;
        a[x] = i;
        L[i] = x;
    }

    dfs(0,-1);
    printf("%lld\n", invalid?0:dp[0][1]);
    return 0;
}
