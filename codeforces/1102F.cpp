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

const int N = 16;
const int M = 10000;
const int INF = 1000000001;

int n,m;
int a[N][M];

int ac[N][N];

int dp[1<<N][N][N];
int dfs(int mask, int prev, int head){
    if(dp[mask][prev][head]>=0) return dp[mask][prev][head];
    if(mask == (1<<n)-1){
        int ret = INF;
        rep(i,m-1) ret = min(ret, abs(a[prev][i]-a[head][i+1]));
        return dp[mask][prev][head] = ret;
    }

    int ret = 0;
    rep(i,n)if(!(mask>>i&1)){
        int nmask = mask|(1<<i);
        int v = min(dfs(nmask,i,head), ac[prev][i]);
        ret = max(ret,v);
    }
    return dp[mask][prev][head] = ret;
}

int main(){
    scanf(" %d %d", &n, &m);
    rep(i,n)rep(j,m) scanf(" %d", &a[i][j]);

    if(n==1){
        int ans = INF;
        rep(i,m-1) ans = min(ans, abs(a[0][i]-a[0][i+1]));
        printf("%d\n", ans);
        return 0;
    }

    // usual acceptance row i -> row j
    rep(i,n)rep(j,n){
        int t = INF;
        rep(k,m) t = min(t, abs(a[i][k]-a[j][k]));
        ac[i][j] = t;
    }

    memset(dp,-1,sizeof(dp));
    int ans = 0;
    rep(i,n) ans = max(ans, dfs(1<<i,i,i));
    printf("%d\n", ans);
    return 0;
}
