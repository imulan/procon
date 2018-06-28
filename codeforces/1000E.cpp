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

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    G = vector<vi>(n);

    vector<int> x(m),y(m);
    rep(i,m){
        scanf(" %d %d", &x[i], &y[i]);
        --x[i];
        --y[i];
        if(x[i]>y[i]) swap(x[i],y[i]);

        G[x[i]].pb(y[i]);
        G[y[i]].pb(x[i]);
    }

    vector<edge> bridge;
    vector<vi> bicomp;
    bridge_detect(bridge,bicomp);

    // dbg(bridge);
    // dbg(bicomp);

    int B = bicomp.size();

    vector<int> idx(n);
    rep(i,B){
        for(int j:bicomp[i]){
            idx[j] = i;
        }
    }

    vector<vi> g(B);
    rep(i,bridge.size()){
        int u = idx[bridge[i].fi], v = idx[bridge[i].se];
        g[u].pb(v);
        g[v].pb(u);
    }

    const int INF = 19191919;

    queue<int> que;
    vector<int> d(B,INF);
    d[0] = 0;
    que.push(0);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(int e:g[now]){
            if(d[e]>d[now]+1){
                d[e] = d[now]+1;
                que.push(e);
            }
        }
    }

    int farthest = 0;
    int md = 0;
    rep(i,B){
        if(md<d[i]){
            md = d[i];
            farthest = i;
        }
    }

    d = vector<int>(B,INF);
    d[farthest] = 0;
    que.push(farthest);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(int e:g[now]){
            if(d[e]>d[now]+1){
                d[e] = d[now]+1;
                que.push(e);
            }
        }
    }

    int ans = 0;
    rep(i,B) ans = max(ans,d[i]);
    printf("%d\n", ans);
    return 0;
}
