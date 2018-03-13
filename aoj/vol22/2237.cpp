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

const int N = 16;
double dp[N][1<<N];
double nx[N][1<<N];

int main(){
    int m,n;
    scanf(" %d %d", &m, &n);

    double p[16][16]={};
    rep(i,m)rep(j,n) scanf(" %lf", &p[i][j]);

    fill(dp[0], dp[N], 1);
    // i-th enemy
    for(int i=n-1; i>=0; --i){
        double max_p[1<<N];
        rep(mask,1<<m){
            rep(j,m)if(mask>>j&1){
                double win = p[j][i];
                int lmask = mask^(1<<j);
                nx[j][mask] = win*dp[j][mask] + (1-win)*max_p[lmask];
            }

            max_p[mask] = 0;
            rep(j,m)if(mask>>j&1) max_p[mask] = max(max_p[mask], nx[j][mask]);
        }

        rep(j,N)rep(k,1<<N) dp[j][k] = nx[j][k];
    }

    double ans = 0;
    rep(i,m) ans = max(ans, dp[i][(1<<m)-1]);
    printf("%.10f\n", ans);
    return 0;
}
