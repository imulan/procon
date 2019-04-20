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

const int MAX_V = 100010;
const int MAX_LOG_V = 19;
vector<int> G[MAX_V];
int root = 0;
int parent[MAX_LOG_V][MAX_V];
int depth[MAX_V];

void lca_dfs(int v, int p, int d){
    parent[0][v] = p;
    depth[v] = d;
    rep(i,G[v].size())if(G[v][i]!=p) lca_dfs(G[v][i], v, d+1);
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

int sz[MAX_V];
void dfs(int x, int p){
    sz[x] = 1;
    for(int e:G[x])if(e!=p){
        dfs(e,x);
        sz[x] += sz[e];
    }
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(case_num,T){
        int n,q,r;
        scanf(" %d %d %d", &n, &q, &r);
        --r;

        rep(i,MAX_V) G[i].clear();

        rep(i,n-1){
            int u,v;
            scanf(" %d %d", &u, &v);
            --u;
            --v;
            G[u].pb(v);
            G[v].pb(u);
        }

        lca_init(n);

        memset(sz,0,sizeof(sz));
        dfs(0,-1);

        // rep(i,n) dbg(sz[i]);

        printf("Case #%d:\n", case_num+1);
        rep(i,q){
            int s,u;
            scanf(" %d %d", &s, &u);
            --u;
            if(s==0) r = u;
            else{
                int ans = -1;
                if(r==u) ans = n;
                else{
                    int LCA = lca(u,r);
                    if(LCA == u){
                        int c = r;
                        for(int j=MAX_LOG_V-1; j>=0; --j){
                            if(depth[c] - (1<<j) > depth[u]) c = parent[j][c];
                        }
                        ans = n-sz[c];
                    }
                    else ans = sz[u];
                }
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
