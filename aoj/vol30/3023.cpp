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

struct P{
    int x,y;
    void READ(){
        cin >>x >>y;
    }
};

double calc_dist(P p, P q){
    double X = abs(p.x-q.x);
    double Y = abs(p.y-q.y);
    return sqrt(X*X + Y*Y);
}

const int N = 15;
const double INF = 1e6;

double dist[N][N];

double d[N][N];
double dp[1<<N][N];
double D[200][2][200][2];

void calc(int start, int n){
    fill(dp[0],dp[1<<N],INF);
    dp[1<<start][start] = 0;
    rep(mask,1<<n)rep(i,n)if(mask>>i&1){
        rep(j,n)if(!(mask>>j&1)){
            int nmask = mask|(1<<j);
            dp[nmask][j] = min(dp[nmask][j], dp[mask][i]+dist[i][j]);
        }
    }
    rep(i,n) d[start][i] = dp[(1<<n)-1][i];
}


int main(){
    int n,m;
    cin >>n >>m;

    vector<vector<P>> store(n,vector<P>(2));
    vector<P> factory(m);
    rep(i,n)rep(j,2) store[i][j].READ();
    rep(i,m) factory[i].READ();

    rep(i,m)rep(j,m) dist[i][j] = calc_dist(factory[i], factory[j]);
    rep(i,m) calc(i,m);

    rep(i,n)rep(j,i)rep(ii,2)rep(jj,2){
        double tt = INF;
        rep(from,m)rep(to,m){
            double tmp = calc_dist(store[i][ii], factory[from]) + d[from][to] + calc_dist(factory[to], store[j][jj]);
            tt = min(tt,tmp);
        }
        D[i][ii][j][jj] = tt;
    }

    auto valid = [&](double lim){
        TwoSat solver(n);
        rep(i,n)rep(j,i)rep(ii,2)rep(jj,2){
            if(D[i][ii][j][jj]>lim) solver.add_clause(i,!ii,j,!jj);
        }
        return solver.calc();
    };

    double l=0, r=INF;
    rep(_,50){
        double mid=(l+r)/2;
        if(valid(mid)) r=mid;
        else l=mid;
    }
    printf("%.10f\n", r);
    return 0;
}
