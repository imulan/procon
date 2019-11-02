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

const int N = 202;

int n,k;
int a[N];
vector<int> G[N];

int dp[N][N];
void dfs(int v, int p){
    for(int c:G[v])if(c!=p) dfs(c,v);

    dp[v][0] = a[v];
    for(int c:G[v])if(c!=p){
        dp[v][0] += dp[c][k];

        for(int i=1; i<N; ++i){
            int t = dp[c][i-1];
            for(int u:G[v])if(u!=p && u!=c) t += dp[u][max(i-1, k-i)];
            dp[v][i] = max(dp[v][i], t);
        }
    }

    for(int i=N-1; i>0; --i) dp[v][i-1] = max(dp[v][i-1], dp[v][i]);
}

int main(){
    scanf(" %d %d", &n, &k);
    rep(i,n) scanf(" %d", &a[i]);
    rep(i,n-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    dfs(0,-1);
    printf("%d\n", dp[0][0]);
    return 0;
}
