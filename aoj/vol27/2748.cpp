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

int main(){
    int n;
    while(scanf(" %d", &n),n){
        vector<double> p(n);
        SCC s(n);

        rep(i,n){
            scanf(" %lf", &p[i]);

            int m;
            scanf(" %d", &m);
            rep(j,m){
                int a;
                scanf(" %d", &a);
                --a;
                s.add_edge(i,a);
            }
        }

        int sz = s.scc();

        vector<vector<int>> cc(sz);
        vector<bool> have_inedge(sz,false);
        rep(i,n){
            cc[s.cmp[i]].pb(i);
            for(int e:s.G[i]){
                int v = s.cmp[e];
                if(s.cmp[i] != v) have_inedge[v] = true;
            }
        }

        double ans = 1;
        rep(i,sz)if(!have_inedge[i]){
            // グループ内の誰か一人が起きる
            double all_sleep = 1;
            for(int j:cc[i]) all_sleep *= p[j];
            ans *= (1 - all_sleep);
        }
        printf("%.10f\n", ans);
    }
    return 0;
}
