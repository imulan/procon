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

    inline int num(int id, bool b){return id+(!b)*v;}

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
