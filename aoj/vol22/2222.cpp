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

const ll mod = 1e9+7;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    SCC s(n);

    vector<int> u(m),v(m);
    rep(i,m){
        scanf(" %d %d", &u[i], &v[i]);
        --u[i];
        --v[i];
        s.add_edge(u[i],v[i]);
    }

    int sz = s.scc();
    vector<vector<int>> dag(sz), r_dag(sz);
    rep(i,m){
        int U = s.cmp[u[i]], V = s.cmp[v[i]];
        if(U != V){
            dag[U].pb(V);
            r_dag[V].pb(U);
        }
    }

    ll ans = 1;
    vector<vector<ll>> dp(sz, vector<ll>(2,1));
    rep(i,sz){
        for(int j:r_dag[i]){
            (dp[i][0] *= dp[j][0]) %= mod;
            (dp[i][1] *= dp[j][0]+dp[j][1]) %= mod;
        }

        // leaf
        if(dag[i].size() == 0){
            (ans *= dp[i][0]+dp[i][1]) %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}
