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

const int INF = 1234567;

const int N = 303;
const int M = 634;
int dp[N][M];
int nx[N][M];

int main(){
    int n,x,y;
    cin >>n >>x >>y;

    rep(j,N)rep(k,M) dp[j][k] = -INF;
    dp[x][N+y] = 0;

    rep(i,n){
        int a,b,c,d;
        cin >>a >>b >>c >>d;

        rep(j,N)rep(k,M) nx[j][k] = dp[j][k];
        rep(j,N)rep(k,M){
            if(j-a>=0 && k+b<M) nx[j-a][k+b] = max(nx[j-a][k+b], dp[j][k]);
            if(k-c>=0) nx[j][k-c] = max(nx[j][k-c], dp[j][k]+d);
        }

        rep(j,N)rep(k,M) dp[j][k] = nx[j][k];
    }

    int ans = 0;
    rep(i,N)for(int j=N; j<M; ++j) ans = max(ans, dp[i][j]);
    cout << ans << endl;
    return 0;
}
