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

const ll mod = 1000000007;
const int N = 100010;

vector<int> G[N];

ll dp[N][2];
ll dfs(int r, int c, int p){
    if(dp[r][c]>=0) return dp[r][c];

    ll ret = 1;
    for(int e:G[r])if(e!=p){
        ll a = 0;
        rep(i,2){
            if(i==1 && c==1) continue;
            (a += dfs(e,i,r)) %= mod;
        }
        (ret *= a) %= mod;
    }
    return dp[r][c] = ret;
}

int main(){
    int n;
    scanf(" %d", &n);
    rep(i,n-1){
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        G[x].pb(y);
        G[y].pb(x);
    }

    memset(dp,-1,sizeof(dp));
    ll ans = 0;
    rep(i,2) (ans += dfs(0,i,-1)) %= mod;
    printf("%lld\n", ans);
    return 0;
}
