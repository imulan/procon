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

const int L = 20;
const int N = 1000001;
int par[L][N]={};

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    SCC graph(n);
    vector<bool> leaf(n,true);
    leaf[0] = false;

    for(int i=1; i<n; ++i){
        int p;
        scanf(" %d", &p);
        --p;

        graph.add_edge(p,i);
        leaf[p] = false;
        par[0][i] = p;
    }

    for(int i=1; i<L; ++i)rep(j,n) par[i][j] = par[i-1][par[i-1][j]];

    for(int i=1; i<n; ++i)if(leaf[i]){
        int t = k;
        int now = i;
        for(int j=L-1; j>=0; --j){
            if(t-(1<<j) >= 0){
                now = par[j][now];
                t -= 1<<j;
            }
        }

        graph.add_edge(i,now);
    }

    int C = graph.scc();

    vector<vector<int>> g(C);
    rep(i,n)for(int j:graph.G[i]){
        int u = graph.cmp[i], v = graph.cmp[j];
        if(u==v) continue;

        g[u].pb(v);
    }

    vector<int> v(C);
    rep(i,n)if(leaf[i]) ++v[graph.cmp[i]];

    vector<int> dp(C);
    dp[0] = v[0];
    rep(i,C){
        for(int j:g[i]) dp[j] = max(dp[j], dp[i]+v[j]);
    }

    int ans = 0;
    for(int i:dp) ans = max(ans,i);
    printf("%d\n", ans);
    return 0;
}
