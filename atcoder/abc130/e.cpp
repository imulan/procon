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

const ll mod = 1e9+7;
const int N = 2002;
ll dp[N][N];

int main(){
    int n,m;
    cin >>n >>m;

    vector<int> s(n+1), t(m+1);
    rep(i,n) cin >>s[i+1];
    rep(i,m) cin >>t[i+1];

    rep(i,N) dp[0][i] = dp[i][0] = 1;
    for(int i=1; i<=n; ++i)for(int j=1; j<=m; ++j){
        if(s[i]==t[j]) dp[i][j] = dp[i-1][j-1];
        dp[i][j] = (dp[i][j] + dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + mod) % mod;
    }
    cout << dp[n][m] << endl;
    return 0;
}
