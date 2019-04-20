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

struct edge{ int to; ll cost; };

const int N = 500000;
vector<edge> G[N];

int col[N];

const ll INF = LLONG_MAX/3;

ll dp[N][2];
ll dfs(int v, int c, int par){
    if(dp[v][c]>=0) return dp[v][c];
    if(col[v]!=-1){
        if(col[v] != c) return INF;
    }

    ll ret = 0;
    for(const auto &e:G[v])if(e.to != par){
        ll add = INF;
        rep(i,2){
            ll cc = 0;
            if(c != i) cc = e.cost;
            add = min(add, dfs(e.to,i,v)+cc);
        }

        assert(add < INF);
        ret += add;
    }

    return dp[v][c] = ret;
}

int main(){
    int n,x,y;
    scanf(" %d %d %d", &n, &x, &y);

    rep(i,n-1){
        int a,b;
        ll v;
        scanf(" %d %d %lld", &a, &b, &v);
        --a;
        --b;
        G[a].pb({b,v});
        G[b].pb({a,v});
    }

    memset(col,-1,sizeof(col));
    rep(i,x){
        int a;
        scanf(" %d", &a);
        --a;
        col[a] = 0;
    }

    rep(i,y){
        int a;
        scanf(" %d", &a);
        --a;
        col[a] = 1;
    }

    ll ans = INF;
    memset(dp,-1,sizeof(dp));
    rep(i,2) ans = min(ans, dfs(0,i,-1));
    cout << ans << endl;
    return 0;
}
