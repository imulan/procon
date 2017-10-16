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

using vi = vector<int>;

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

struct TwoSat{
    int v;
    SCC graph;

    // v literals
    // 0~v-1: true
    // v~2v-1: false

    TwoSat(int num_literal){
        v = num_literal;
        graph = SCC(2*v);
    }

    inline int num(int id, bool b){
        if(!b) return id+v;
        return id;
    }

    void add_clause(int x, bool X, int y, bool Y){
        graph.add_edge(num(x,!X), num(y,Y));
        graph.add_edge(num(y,!Y), num(x,X));
    }

    // 割り当てが可能か調べる
    bool calc(){
        graph.scc();
        rep(i,v)if(graph.cmp[i]==graph.cmp[v+i]) return false;
        return true;
    }

    // 真偽値bのリテラルを返す
    vector<int> get_literals(bool b = true){
        assert(calc());
        vector<int> res;
        rep(i,v){
            if(b == (graph.cmp[i]>graph.cmp[v+i])) res.pb(i);
        }
        return res;
    }
};

int main()
{
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<vi> w(n);
    rep(i,n)
    {
        int L;
        scanf(" %d", &L);
        w[i] = vi(L);
        rep(j,L)
        {
            scanf(" %d", &w[i][j]);
            --w[i][j];
        }
    }

    // 0~m-1: small
    // m~2m-1:large
    TwoSat g(m);

    rep(i,n-1)
    {
        // dbg(i);
        int L = min(w[i].size(), w[i+1].size());

        int idx = 0;
        while(idx<L && w[i][idx]==w[i+1][idx]) ++idx;

        if(idx==L)
        {
            if(w[i].size()>w[i+1].size())
            {
                printf("No\n");
                return 0;
            }
        }
        else
        {
            if(w[i][idx]>w[i+1][idx])
            {
                // ~w[i][idx] ^ w[i+1][idx]

                // ~w[i][idx] v ~w[i+1][idx]
                g.add_clause(w[i][idx], false, w[i+1][idx], false);
                // ~w[i][idx] v w[i+1][idx]
                g.add_clause(w[i][idx], false, w[i+1][idx], true);
                // w[i][idx] v w[i+1][idx]
                g.add_clause(w[i][idx], true, w[i+1][idx], true);
            }
            else
            {
                // ~w[i][idx] v w[i+1][idx]
                g.add_clause(w[i][idx], false, w[i+1][idx], true);
            }
        }
    }

    if(!g.calc())
    {
        printf("No\n");
        return 0;
    }

    vector<int> ans = g.get_literals(false);
    int A = ans.size();
    printf("Yes\n%d\n",A);
    rep(i,A) printf("%d%c", ans[i]+1, (i==A-1)?'\n':' ');
    return 0;
}
