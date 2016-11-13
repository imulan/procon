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

edge e[400000];
int edge_used[400000]={0};
vector<vector<pi>> dG;

void dfs(int v)
{
    rep(i,G[v].size())
    {
        int to = dG[v][i].fi;
        int e_id = dG[v][i].se;
        if(!edge_used[e_id])
        {
            e[e_id]=edge(to,v);
            edge_used[e_id]=1;
            dfs(to);
        }
    }
}

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    G = vector<vi>(n);
    dG = vector<vector<pi>>(n);

    rep(i,m)
    {
        int u,v;
        scanf(" %d %d", &u, &v);
        --u; --v;
        if(u>v) swap(u,v);

        G[u].pb(v); G[v].pb(u);
        dG[u].pb(pi(v,i)); dG[v].pb(pi(u,i));
        e[i]=edge(u,v);
    }

    vector<edge> bridge;
    vector<vi> bicomp;
    bridge_detect(bridge, bicomp);

    int ans=0;
    int largest_group_id=-1;
    vector<int> group(n);
    rep(i,bicomp.size())
    {
        int B=bicomp[i].size();
        if(ans<B)
        {
            ans=B;
            largest_group_id=i;
        }
        rep(j,B) group[bicomp[i][j]]=i;
    }

    // printf("bridge\n");
    // rep(i,bridge.size()) printf(" %d %d\n", bridge[i].fi+1, bridge[i].se+1);

    dfs(bicomp[largest_group_id][0]);


    printf("%d\n", ans);
    rep(i,m)
    {
        if(group[e[i].fi]!=group[e[i].se] &&  group[e[i].fi]==largest_group_id) swap(e[i].fi, e[i].se);
        printf("%d %d\n", e[i].fi+1, e[i].se+1);
    }
    return 0;
}
