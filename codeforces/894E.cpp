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

const int N = 1000000;
const ll INF = LLONG_MAX/3;
ll dp[N];
ll cc[N]={};

struct edge{int to,cost;};
vector<edge> dag[N];

inline ll f(ll x){
    return x*(x+1)/2;
}

inline ll ff(ll x){
    ll ret = x*(x+1)*(2*x+1)/6 + x*(x+1)/2;
    ret /= 2;
    return ret;
}

// 初期値wの時に得られるキノコの個数
inline ll calc(ll w){
    int l = 0, r = w;
    while(r-l>1){
        int m = (l+r)/2;
        if(w-f(m)>0) l=m;
        else r=m;
    }
    // printf(" %lld, %lld", w, l);
    return w*(l+1)-ff(l);
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    SCC g(n);
    vector<int> from(m),to(m),w(m);
    rep(i,m){
        scanf(" %d %d %d", &from[i], &to[i], &w[i]);
        --from[i];
        --to[i];
        g.add_edge(from[i], to[i]);
    }

    int start;
    scanf(" %d", &start);
    --start;

    g.scc();

    rep(i,m){
        int x = from[i], y = to[i];
        int cx = g.cmp[x], cy = g.cmp[y];

        if(cx == cy){
            cc[cx] += calc(w[i]);
        }
        else{
            dag[cx].pb({cy, w[i]});
        }
    }

    fill(dp,dp+N,-INF);
    dp[g.cmp[start]] = cc[g.cmp[start]];

    rep(i,N){
        for(const auto &e:dag[i]){
            dp[e.to] = max(dp[e.to], dp[i]+e.cost+cc[e.to]);
        }
    }

    ll ans = 0;
    rep(i,N) ans = max(ans, dp[i]);
    printf("%lld\n", ans);
    return 0;
}
