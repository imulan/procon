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

const int N = 505;
double dp[N][N];

int main(){
    int n,m;
    cin >>n >>m;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    fill(dp[0],dp[N],-1e9);
    dp[0][0] = 0;
    rep(i,n)rep(j,m){
        double s = 0;
        for(int k=i; k<n; ++k){
            s += a[k];
            dp[k+1][j+1] = max(dp[k+1][j+1], dp[i][j]+(s/(k-i+1)));
        }
    }

    double ans = 0;
    rep(i,m+1) ans = max(ans,dp[n][i]);
    printf("%.10f\n", ans);
    return 0;
}
