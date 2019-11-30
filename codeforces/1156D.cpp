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

struct edge{ int to,c; };

const int N = 200002;
vector<edge> G[N];
int par[N];
ll dp[N][2];
void dfs(int v){
    dp[v][0] = 1;

    for(const auto &e:G[v])if(e.to != par[v]){
        par[e.to] = v;
        dfs(e.to);

        if(e.c == 0) dp[v][1] += dp[e.to][0]+dp[e.to][1];
        else dp[v][0] += dp[e.to][0];
    }
}

ll ans = 0;
void dfs2(int v, ll x0, ll x1){
    ll add = dp[v][0]+dp[v][1]+x0+x1;
    ans += add;
    // printf(" %d (%lld %lld): ADD %lld\n",v+1,x0,x1,add);

    ll t[2]={};
    t[0] = x0+dp[v][0];
    t[1] = x1+dp[v][1];

    for(const auto &e:G[v])if(e.to != par[v]){
        if(e.c == 0) dfs2(e.to, 0, t[0]+t[1]-dp[e.to][0]-dp[e.to][1]);
        else dfs2(e.to, t[0]-dp[e.to][0], 0);
    }
}


int main(){
    int n;
    scanf(" %d", &n);
    rep(i,n-1){
        int u,v,w;
        scanf(" %d %d %d", &u, &v, &w);
        --u;
        --v;
        G[u].pb({v,w});
        G[v].pb({u,w});
    }

    par[0] = -1;
    dfs(0);
    // rep(i,n) printf("%d :: %lld  %lld\n", i+1 ,dp[i][0], dp[i][1]);
    dfs2(0,0,0);

    printf("%lld\n", ans-n);
    return 0;
}
