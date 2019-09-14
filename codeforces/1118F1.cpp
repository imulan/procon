#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using pi = pair<int,int>;

const int N = 300003;
int n;
int a[N];
pi e[N];

vector<int> G[N];
int par[N];
int ct[N][3] = {};

void dfs(int x, int p){
    par[x] = p;
    for(int nx:G[x])if(nx!=p){
        dfs(nx,x);
        rep(i,3) ct[x][i] += ct[nx][i];
    }
    ++ct[x][a[x]];
}

int main(){
    scanf(" %d", &n);
    rep(i,n) scanf(" %d", &a[i]);

    rep(i,n-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;

        e[i] = {u,v};
        G[u].pb(v);
        G[v].pb(u);
    }

    dfs(0,-1);

    int ans = 0;
    rep(i,n-1){
        int u = e[i].fi, v = e[i].se;
        if(par[u] == v) swap(u,v);
        assert(par[v] == u);

        if((ct[v][1]==ct[0][1] && ct[v][2]==0) || (ct[v][2]==ct[0][2] && ct[v][1]==0)) ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
