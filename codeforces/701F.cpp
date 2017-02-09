#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=2020202020;

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> edge;

typedef pair<edge,int> weighted_edge;
typedef pair<int,int> pi;

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

void solve()
{
    int n,m,s,t;
    scanf(" %d %d", &n, &m);
    scanf(" %d %d", &s, &t);
    --s;
    --t;

    G = vector<vi>(n);

    map<edge,vector<pi>> e_count;
    vector<int> x(m),y(m),w(m);
    rep(i,m)
    {
        scanf(" %d %d %d", &x[i], &y[i], &w[i]);
        --x[i];
        --y[i];
        e_count[edge(x[i],y[i])].pb(pi(i,w[i]));
        e_count[edge(y[i],x[i])].pb(pi(i,w[i]));

        G[x[i]].pb(y[i]);
        G[y[i]].pb(x[i]);
    }

    // もとのグラフでsとtが繋がっているかチェック
    queue<int> que;
    vector<bool> vis(n,false);
    vector<int> par(n,-1);
    vis[s]=true;
    que.push(s);
    while(!que.empty())
    {
        int v = que.front();
        que.pop();
        rep(i,G[v].size())
        {
            int nx = G[v][i];
            if(!vis[nx])
            {
                vis[nx]=true;
                par[nx]=v;
                que.push(nx);
            }
        }
    }

    // 繋がっていなければ終わり
    if(!vis[t])
    {
        printf("0\n0\n");
        return;
    }

    int ans = INF;
    int c = -1;
    vector<int> ans_edge;

    vector<edge> bridge;
    vector<vi> bicomp;
    bridge_detect(bridge,bicomp);

    // 1つの辺を削除する場合
    set<edge> B;
    rep(i,bridge.size()) B.insert(bridge[i]);

    vector<edge> one_path;
    int now = t;
    while(now!=s)
    {
        int P = par[now];
        edge E = edge(now,P);

        one_path.pb(E);

        if(B.count(E) || B.count(edge(P,now)))
        {
            if(e_count[E].size()<=2)
            {
                int W=0;
                rep(i,e_count[E].size()) W+=e_count[E][i].se;

                if(W<ans)
                {
                    ans = W;
                    c = e_count[E].size();
                    ans_edge.clear();
                    rep(i,e_count[E].size()) ans_edge.pb(e_count[E][i].fi+1);
                }
            }
        }
        now = P;
    }

    // 2つの辺を削除する場合
    rep(i,one_path.size())
    {
        edge PATH = one_path[i];
        if(e_count[PATH].size()>1) continue;

        G = vector<vi>(n);
        rep(j,m)
        {
            if(PATH == edge(x[j],y[j]) || PATH == edge(y[j],x[j])) continue;

            G[x[j]].pb(y[j]);
            G[y[j]].pb(x[j]);
        }

        vis = vector<bool>(n,false);
        par = vector<int>(n,-1);
        que.push(s);
        vis[s]=true;
        while(!que.empty())
        {
            int v = que.front();
            que.pop();
            rep(j,G[v].size())
            {
                int nx = G[v][j];
                if(!vis[nx])
                {
                    vis[nx]=true;
                    par[nx]=v;
                    que.push(nx);
                }
            }
        }

        // 橋であるような状況は考慮済みなのでスキップ
        if(!vis[t]) continue;

        bridge.clear();
        bicomp.clear();
        bridge_detect(bridge,bicomp);

        B.clear();
        rep(j,bridge.size()) B.insert(bridge[j]);

        now = t;
        while(now!=s)
        {
            int P = par[now];
            edge E = edge(now,P);

            if(B.count(E) || B.count(edge(P,now)))
            {
                if(e_count[E].size()==1)
                {
                    int W = e_count[PATH][0].se + e_count[E][0].se;

                    if(W<ans)
                    {
                        ans = W;
                        c = 2;
                        ans_edge.clear();
                        ans_edge.pb(e_count[PATH][0].fi+1);
                        ans_edge.pb(e_count[E][0].fi+1);
                    }
                }
            }
            now = P;
        }
    }

    // output
    if(ans == INF) printf("-1\n");
    else
    {
        printf("%d\n%d\n", ans, c);
        rep(i,ans_edge.size())
        {
            if(i) printf(" ");
            printf("%d", ans_edge[i]);
        }
        printf("\n");
    }
}

int main()
{
    solve();
    return 0;
}
