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

const int mod = 1000000007;
const int N = 21;

int n;
int a[N][N];
int dp[N][1<<N];
int dfs(int d, int mask){
    if(d==n) return 1;
    if(dp[d][mask]>=0) return dp[d][mask];

    int ret = 0;
    rep(i,n)if(!(mask>>i&1) && a[d][i]){
        int nmask = mask|(1<<i);
        (ret += dfs(d+1, nmask)) %= mod;
    }

    return dp[d][mask] = ret;
}

int main(){
    cin >>n;
    rep(i,n)rep(j,n) cin >>a[i][j];

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0) << "\n";
    return 0;
}
