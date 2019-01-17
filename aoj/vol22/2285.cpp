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

struct artist{
    int cost;
    int val;

    void READ(){
        char name[33];
        scanf(" %s %d %d", name, &cost, &val);
    }
};

const int M = 111;
const int L = 1001;
const int INF = 10101010;

int dp[M][M][L];
int mx[L];

int main(){
    int lim,n,m,x;
    while(scanf(" %d %d %d %d", &lim, &n, &m, &x),lim){
        vector<artist> a(n),b(m);
        rep(i,n) a[i].READ();
        rep(i,m) b[i].READ();

        rep(i,M)rep(j,M)rep(k,L) dp[i][j][k] = -INF;
        dp[0][0][0] = 0;
        rep(i,m)rep(j,i+1)rep(k,L)if(dp[i][j][k]>=0){
            dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);

            int nk = k+b[i].cost;
            if(nk<L) dp[i+1][j+1][nk] = max(dp[i+1][j+1][nk], dp[i][j][k]+b[i].val);
        }

        rep(i,L) mx[i] = -INF;
        for(int i=x; i<=m; ++i)rep(j,L) mx[j] = max(mx[j], dp[m][i][j]);
        rep(i,L-1) mx[i+1] = max(mx[i+1],mx[i]);

        int ans = -INF;
        rep(i,n){
            int rem = lim-a[i].cost;
            if(rem<0) continue;
            ans = max(ans, a[i].val+mx[rem]);

            rep(j,n)if(i!=j){
                int rr = rem-a[j].cost;
                if(rr<0) continue;
                ans = max(ans, a[i].val+a[j].val+mx[rr]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
