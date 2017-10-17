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

    inline int num(int id, bool b){return id+(b?0:v);}

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

    // リテラルの真偽値を返す
    vector<bool> get_literals(){
        assert(calc());
        vector<bool> res(v);
        rep(i,v) res[i] = (graph.cmp[i]>graph.cmp[v+i]);
        return res;
    }
};

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin >>n;
    vector<string> u(n);
    rep(i,n) cin >>u[i];

    map<string,int> ct;
    rep(i,n) ++ct[u[i]];

    if(n>52)
    {
        cout << "Impossible" << endl;
        return 0;
    }

    for(const auto &p:ct)
    {
        if(p.se>2)
        {
            cout << "Impossible" << endl;
            return 0;
        }
    }

    map<string,vector<pair<int,int>>> ap;
    vector<string> s;
    rep(i,n)rep(j,2)
    {
        string x = u[i].substr(0,j+1), y = u[i].substr(j+1);
        ap[x].pb({i,j});
        ap[y].pb({i,j});
        s.pb(x);
        s.pb(y);
    }

    sort(all(s));
    s.erase(unique(all(s)),s.end());

    TwoSat solver(n);
    for(string w:s)
    {
        vector<pair<int,int>> v = ap[w];
        int V = v.size();
        rep(i,V)rep(j,i)if(v[i].fi!=v[j].fi)
        {
            solver.add_clause(v[i].fi, !v[i].se, v[j].fi, !v[j].se);
        }
    }

    if(!solver.calc())
    {
        cout << "Impossible" << endl;
        return 0;
    }

    vector<bool> tf = solver.get_literals();
    rep(i,n)
    {
        int L = (tf[i]?2:1);
        cout << u[i].substr(0,L) << " " << u[i].substr(L) << endl;
    }
    return 0;
}
