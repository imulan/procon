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

struct SCC{
    int V;
    vector<vector<int>> G, rG;
    vector<int> vs; // 帰りがけ順の並び
    vector<int> cmp; //属する強連結成分トポロジカル順序
    vector<bool> used;

    SCC(){}
    SCC(int n){
        V = n;
        G = vector<vector<int>>(n);
        rG = vector<vector<int>>(n);
    }

    void add_edge(int from, int to){
        G[from].push_back(to);
        rG[to].push_back(from);
    }

    void dfs(int v){
        used[v] = true;
        rep(i,G[v].size())if(!used[G[v][i]]) dfs(G[v][i]);
        vs.push_back(v);
    }

    void rdfs(int v, int k){
        used[v]=true;
        cmp[v]=k;
        rep(i,rG[v].size())if(!used[rG[v][i]]) rdfs(rG[v][i],k);
    }

    int scc(){
        used = vector<bool>(V,false);
        vs.clear();
        rep(i,V)if(!used[i]) dfs(i);

        used = vector<bool>(V,false);
        cmp = vector<int>(V);
        int num_scc = 0;
        for(int i=vs.size()-1; i>=0; --i)if(!used[vs[i]]) rdfs(vs[i],num_scc++);
        return num_scc;
    }
};

const int N = 5000;
vector<int> sg[N], rsg[N];

int main(){
    int n,m,s;
    scanf(" %d %d %d", &n, &m, &s);
    --s;

    vector<int> u(m), v(m);
    rep(i,m){
        scanf(" %d %d", &u[i], &v[i]);
        --u[i];
        --v[i];
    }

    SCC graph(n);
    rep(i,m) graph.add_edge(u[i], v[i]);

    int num = graph.scc();

    using pi = pair<int,int>;
    set<pi> E;
    rep(i,m){
        int from = graph.cmp[u[i]], to = graph.cmp[v[i]];
        if(from != to){
            assert(from<to);
            E.insert({from,to});
        }
    }

    for(const auto e:E){
        sg[e.fi].pb(e.se);
        rsg[e.se].pb(e.fi);
    }

    int capital = graph.cmp[s];
    vector<bool> vis(n);

    auto BFS = [&](int start){
        queue<int> que;
        vis[start] = true;
        que.push(start);
        while(!que.empty()){
            int now = que.front();
            que.pop();
            for(int nx:sg[now]){
                if(!vis[nx]){
                    vis[nx] = true;
                    que.push(nx);
                }
            }
        }
    };

    BFS(capital);

    int ans = 0;
    rep(i,num)if(!vis[i]){
        ++ans;
        BFS(i);
    }
    printf("%d\n", ans);
    return 0;
}
