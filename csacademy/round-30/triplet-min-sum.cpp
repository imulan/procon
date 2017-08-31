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
const int MAX_LOG_V = 18;
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

int d[MAX_V];
const int INF = 19191919;

inline int f(int x, int y)
{
    return d[x]+d[y]-2*d[lca(x,y)];
}

int main()
{
    int n,q;
    cin >>n >>q;
    rep(i,n-1)
    {
        int u,v;
        cin >>u >>v;
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    fill(d,d+n,INF);
    d[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        for(int e:G[v])
        {
            if(d[e]>d[v]+1)
            {
                d[e] = d[v]+1;
                que.push(e);
            }
        }
    }

    lca_init(n);

    while(q--)
    {
        int v[3];
        rep(i,3)
        {
            cin >>v[i];
            --v[i];
        }

        int sum = INF;
        int ans = -1;
        rep(i,3)
        {
            int D = lca(v[i],v[(i+1)%3]);

            int ts = 0;
            rep(j,3) ts += f(D,v[j]);
            if(ts<sum)
            {
                sum = ts;
                ans = D;
            }
        }

        printf("%d %d\n", ans+1, sum);
    }
    return 0;
}
