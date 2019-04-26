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
const int N = 10005;
const int D = 111;

string k;
int d;

int dp[N][D][2];
int dfs(int x, int r, int s){
    if(x==N) return !r;
    if(dp[x][r][s]>=0) return dp[x][r][s];

    int ret = 0;
    int lim = s==0?k[x]-'0':9;
    rep(i,lim+1) (ret += dfs(x+1, (r+i)%d, s|(i<lim))) %= mod;
    return dp[x][r][s] = ret;
}

int main(){
    cin >>k >>d;

    reverse(all(k));
    while(k.size()<N) k += "0";
    reverse(all(k));

    memset(dp,-1,sizeof(dp));
    cout << (dfs(0,0,0)+mod-1)%mod << "\n";
    return 0;
}
