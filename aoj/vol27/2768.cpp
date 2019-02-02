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

const int N = 860;
const int INF = 19191919;
int dp[N][N], nx[N][N];

int main(){
    int n;
    cin >>n;
    vector<int> t(n);
    rep(i,n) cin >>t[i];

    rep(i,N)rep(j,N) dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,n){
        rep(j,N)rep(k,N) nx[j][k] = INF;
        rep(j,N)rep(k,N)if(dp[j][k]<INF){
            if(j+t[i]<N) nx[j+t[i]][k] = min(nx[j+t[i]][k], dp[j][k]);
            if(k+t[i]<N) nx[j][k+t[i]] = min(nx[j][k+t[i]], dp[j][k]);
            nx[j][k] = min(nx[j][k], dp[j][k]+t[i]);
        }
        rep(j,N)rep(k,N) dp[j][k] = nx[j][k];
    }

    int ans = INF;
    rep(i,N)rep(j,N) ans = min(ans, max({i,j,dp[i][j]}));
    cout << ans << "\n";
    return 0;
}
