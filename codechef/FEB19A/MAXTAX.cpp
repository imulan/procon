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


const ll mod = 1e9+21;

ll solve(){
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);

    vector<ll> b(n);
    rep(i,n) scanf(" %lld", &b[i]);

    SCC s(n);
    vector<int> u(m),v(m);
    rep(i,m){
        scanf(" %d %d", &u[i], &v[i]);
        --u[i];
        --v[i];
        s.add_edge(u[i],v[i]);
    }

    int C = s.scc();

    vector<vector<ll>> cc(C);
    rep(i,n) cc[s.cmp[i]].pb(b[i]);

    rep(i,C) sort(all(cc[i]));

    vector<vector<int>> cG(C);
    rep(i,m){
        int cu = s.cmp[u[i]], cv = s.cmp[v[i]];
        if(cu != cv) cG[cu].pb(cv);
    }

    vector<vector<ll>> dp(C, vector<ll>(k+1));
    rep(i,C){
        int sz = cc[i].size();
        rep(j,k+1){
            int idx = 0;
            for(int x=sz; x>=1; --x){
                ll add = cc[i][idx]*x;
                int pj = j+(sz-x);
                if(pj>k) break;

                dp[i][j] = max(dp[i][j], dp[i][pj]+add);
                ++idx;
            }
        }

        for(int to:cG[i]){
            rep(j,k+1) dp[to][j] = max(dp[to][j], dp[i][j]);
        }
    }

    ll ret = 0;
    rep(i,C)rep(j,k+1) ret = max(ret, dp[i][j]);
    return ret%mod;
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(_,T) printf("%lld\n", solve());
    return 0;
}
