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

    vector<int> solve(){
        int num = scc();
        vector<vector<int>> cc(num);
        rep(i,V) cc[cmp[i]].pb(i);

        vector<int> ret(V);
        rep(i,V) ret[i]=i;

        rep(i,num){
            bool ok = true;
            for(int v:cc[i]){
                for(int nx:G[v]) ok &= (cmp[v]==cmp[nx]);
            }

            if(ok && cc[i].size() < ret.size()) ret = cc[i];
        }
        return ret;
    }
};

void solve(){
    int n,m,h;
    scanf(" %d %d %d", &n, &m, &h);

    vector<int> u(n);
    rep(i,n) scanf(" %d", &u[i]);

    SCC scc(n);
    rep(i,m){
        int x,y;
        scanf(" %d %d", &x, &y);
        --x; --y;

        if((u[x]+1)%h == u[y]) scc.add_edge(x,y);
        if((u[y]+1)%h == u[x]) scc.add_edge(y,x);
    }

    vector<int> ans = scc.solve();
    int sz = ans.size();
    printf("%d\n",sz);
    rep(i,sz) printf("%d%c", ans[i]+1, " \n"[i==sz-1]);
}

int main(){
    solve();
    return 0;
}
