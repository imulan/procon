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

inline int g(int x, int y, int z){
    if(x==0 && y==0 && z==0) return 0;
    if(x==1 && y==0 && z==0) return 0;
    if(x==1 && y==1 && z==1) return 0;
    return 1;
}

const int N = 2002;
const ll mod = 1e9+7;

int n;
int e[N];

int first,last;
ll dp[N][2][2];
ll dfs(int x, int l, int m){
    if(dp[x][l][m]>=0) return dp[x][l][m];

    ll ret = 0;
    if(x==n-2){
        return (g(l,m,last) == e[x] && g(m,last,first) == e[x+1]);
    }
    else{
        rep(i,2)if(g(l,m,i) == e[x]) (ret += dfs(x+1,m,i)) %= mod;
    }

    return dp[x][l][m] = ret;
}

int main(){
    cin >>n;
    rep(i,n) cin >>e[i];

    ll ans = 0;
    rep(i,2)rep(j,2){
        memset(dp,-1,sizeof(dp));
        first = i;
        last = j;
        (ans += dfs(0,j,i)) %= mod;
    }
    cout << ans << endl;
    return 0;
}
