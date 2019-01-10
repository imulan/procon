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

const int N = 111;
const int INF = 10101010;

int dp[N][N][N];
int nx[N][N];

int main(){
    int n,p;
    cin >>n >>p;
    vector<int> x(n),y(n);
    rep(i,n) cin >>x[i] >>y[i];

    rep(i,n){
        rep(j,i+1){
            int t = 0;
            int now_x;
            for(int k=j; k<=i; ++k){
                now_x = max(0, x[k]-t);
                t = max(0, y[k]-now_x);
            }
            nx[i][j] = now_x;
            // printf(" nx %d %d   = %d\n",i,j,nx[i][j]);
        }
    }

    rep(i,N)rep(j,N)rep(k,N) dp[i][j][k] = -INF;
    dp[0][0][0] = p;
    rep(i,n)rep(j,i+1)rep(k,n+1)if(dp[i][j][k] >= 0){
        dp[i+1][i+1][k] = max(dp[i+1][i+1][k], dp[i][j][k]);

        int rem = dp[i][j][k] - max(0, y[i]-nx[i][j]);
        dp[i+1][j][k+1] = max(dp[i+1][j][k+1], rem);
    }

    int ans = 0;
    rep(j,N)rep(k,N) if(dp[n][j][k]>=0) ans = max(ans, k);
    cout << ans << endl;
    return 0;
}
