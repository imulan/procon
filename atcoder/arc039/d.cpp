#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> edge;

vector<vi> G;

void bridge_dfs(int now, int from, vector<edge> &bridge, vector<vi> &bicomp, stack<int> &roots, stack<int> &S, vb &inS, vi &preord, int &pre_ct){
    preord[now] = pre_ct++;
    S.push(now); inS[now]=true;
    roots.push(now);
    rep(i,G[now].size()){
        int to = G[now][i];
        if(preord[to] == -1) bridge_dfs(to,now,bridge,bicomp,roots,S,inS,preord,pre_ct);
        else if(from != to && inS[to]) while(preord[roots.top()] > preord[to]) roots.pop();
    }
    if(now == roots.top()){
        bridge.pb(edge(now,from));
        bicomp.pb(vi());
        while(1){
            int v=S.top(); S.pop(); inS[v]=false;
            bicomp.back().pb(v);
            if(now == v) break;
        }
        roots.pop();
    }
}

void bridge_detect(vector<edge> &bridge, vector<vi> &bicomp){
    const int n=G.size();
    vi preord(n,-1);
    vb inS(n,false);
    stack<int> roots,S;
    int pre_ct=0;
    rep(i,n)if(preord[i] == -1){
        bridge_dfs(i,n,bridge,bicomp,roots,S,inS,preord,pre_ct);
        bridge.pop_back();
    }
}

typedef pair<int,int> pi;
const int INF=12345678;

//ノードの個数
const int MAX_V =100000;
//ダブリングに必要なサイズ(log(MAX_V))
const int MAX_LOG_V = 18;
//木の隣接リスト表現
vector<int> bG[MAX_V];
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
    rep(i,bG[v].size()){
        if(bG[v][i]!=p){ //親でなければ子
            lca_dfs(bG[v][i], v, d+1);
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

int d[100000];
int calc(int x, int y)
{
    return d[x]+d[y]-2*d[lca(x,y)];
}

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    G = vector<vi>(n);
    rep(i,m)
    {
        int x,y;
        scanf(" %d %d", &x, &y);
        --x; --y;
        G[x].pb(y); G[y].pb(x);
    }

    vector<edge> bridge;
    vector<vi> bicomp;
    bridge_detect(bridge,bicomp);

    int B=bicomp.size();

    vector<int> gr(n);
    rep(i,B)rep(j,bicomp[i].size()) gr[bicomp[i][j]]=i;

    rep(i,bridge.size())
    {
        int a=gr[bridge[i].fi], b=gr[bridge[i].se];
        bG[a].pb(b); bG[b].pb(a);
    }

    priority_queue<pi,vector<pi>,greater<pi>> que;
    // dijkstra
    fill(d,d+B,INF);
    d[0]=0;
    que.push(pi(0,0));
    while(!que.empty())
    {
        pi p=que.top();
        que.pop();
        int v=p.se;
        if(d[v]<p.fi) continue;
        rep(i,bG[v].size())
        {
            int to=bG[v][i];
            if(d[to]>d[v]+1)
            {
                d[to]=d[v]+1;
                que.push(pi(d[to],to));
            }
        }
    }

    lca_init(B);

    int Q;
    scanf(" %d", &Q);
    while(Q--)
    {
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        a = gr[a-1];
        b = gr[b-1];
        c = gr[c-1];

        if(calc(a,c) == calc(a,b)+calc(b,c)) printf("OK\n");
        else printf("NG\n");
    }
    return 0;
}
