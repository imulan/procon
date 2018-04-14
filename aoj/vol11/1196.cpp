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

struct edge{ int to,cost; };

const int N = 800;
vector<edge> G[N];

const ll INF = LLONG_MAX/3;

ll dp[N][2];
ll dfs(int v, int par, int back){
    if(dp[v][back]>=0) return dp[v][back];

    ll c = 0;
    for(const auto &e:G[v])if(e.to != par){
        if(G[e.to].size()==1){
            // leaf
            c += e.cost;
        }
        else{
            c += 3*e.cost + dfs(e.to, v, 1);
        }
    }

    if(back) return dp[v][back] = c;

    ll ret = c;
    for(const auto &e:G[v])if(e.to != par){
        if(G[e.to].size()>1){
            ret = min(ret, c - e.cost - dfs(e.to,v,1) + dfs(e.to,v,0));
        }
    }

    return dp[v][back] = ret;
}

int main(){
    int n;
    while(scanf(" %d", &n),n){
        rep(i,N) G[i].clear();

        vector<int> p(n),d(n);
        for(int i=1; i<n; ++i) scanf(" %d", &p[i]);
        for(int i=1; i<n; ++i) scanf(" %d", &d[i]);

        for(int i=1; i<n; ++i){
            --p[i];
            G[p[i]].pb({i,d[i]});
            G[i].pb({p[i],d[i]});
        }

        ll ans = INF;
        rep(i,n){
            memset(dp,-1,sizeof(dp));
            ans = min(ans, dfs(i,-1,0));
        }

        printf("%lld\n", ans);
    }
    return 0;
}
