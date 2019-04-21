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

const int N = 3003;
double dp[N][N];

int main(){
    int n;
    scanf(" %d", &n);
    vector<double> p(n);
    rep(i,n) scanf(" %lf", &p[i]);

    dp[0][0] = 1;
    rep(i,n){
        rep(j,N-1){
            dp[i+1][j+1] += dp[i][j]*p[i];
            dp[i+1][j] += dp[i][j]*(1.0-p[i]);
        }
    }

    double ans = 0;
    rep(i,N){
        if(i > n-i) ans += dp[n][i];
    }
    printf("%.10f\n", ans);
    return 0;
}
