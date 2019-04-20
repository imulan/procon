#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int MAX_V = 1000010;
const int MAX_LOG_V = 20;
vector<int> G[MAX_V];
int root = 0;

int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void add_edge(int u, int v){
//    printf("ADD %d %d\n",u,v);
    G[u].pb(v);
    G[v].pb(u);
}

void lca_dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    rep(i,G[v].size()){
        if(G[v][i]!=p){
            lca_dfs(G[v][i], v, d+1);
        }
    }
}

void lca_init(int V){
    lca_dfs(root,-1,0);
    for(int k=0; k+1<MAX_LOG_V; ++k){
        rep(v,V){
            if(parent[k][v] < 0) parent[k+1][v] = -1;
            else parent[k+1][v] = parent[k][parent[k][v]];
        }
    }
}

int lca(int u, int v){
    if(depth[u] > depth[v]) swap(u,v);
    rep(k,MAX_LOG_V){
        if( (depth[v]-depth[u])>>k & 1 ) v = parent[k][v];
    }
    if(u==v) return u;
    for(int k=MAX_LOG_V-1; k>=0; --k){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}

int DIST(int u, int v){
    int L = lca(u,v);
    return depth[u]+depth[v]-2*depth[L];
}

using pi = pair<int,int>;

string READ(){
    string s;
    getline(cin, s);
    return s;
}

int main(){
    int h,w;
    cin >>h >>w;
    cin.ignore();

    READ();

    vector<string> v(h);
    rep(i,h) v[i] = READ();
    rep(i,h) assert(v[i].size() == 2*w+1);

    int m;
    cin >>m;
    vector<pi> p(m);
    rep(i,m){
        int y,x;
        cin >>y >>x;
        p[i] = {y-1, x-1};
    }

    auto ID = [&](int y, int x){
        return y*w + x;
    };

    rep(i,h){
        for(int j=1; j<=2*w; ++j){
            if(j%2==0){
                if(v[i][j]==' '){
                    int lx = (j-1)/2, rx = lx+1;
                    add_edge(ID(i,lx), ID(i,rx));
                }
            }
            else{
                if(v[i][j]==' '){
                    int x = j/2;
                    add_edge(ID(i,x), ID(i+1,x));
                }
            }
        }
    }

    lca_init(h*w);

    ll ans = 0;
    rep(i,m-1){
        ans += DIST(ID(p[i].fi,p[i].se), ID(p[i+1].fi,p[i+1].se));
    }
    cout << ans << "\n";
    return 0;
}

