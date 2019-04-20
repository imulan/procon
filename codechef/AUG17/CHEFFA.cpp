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

const int mod = 1e9+7;
const int N = 100;

int n;
int a[N];
int dp[70][131][131][131];

int dfs(int d, int x, int y, int z)
{
    if(d==67) return 1;
    if(dp[d][x][y][z]>=0) return dp[d][x][y][z];

    int ret = 0;
    if(x>0 && y>0) (ret += dfs(d,x-1,y-1,z+1)) %= mod;
    (ret += dfs(d+1,y,z,a[d+3])) %= mod;
    return dp[d][x][y][z] = ret;
}

int solve()
{
    memset(a,0,sizeof(a));
    cin >>n;
    rep(i,n) cin >>a[i];
    memset(dp,-1,sizeof(dp));
    return dfs(0,a[0],a[1],a[2]);
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
