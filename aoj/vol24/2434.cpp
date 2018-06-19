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

const int N = 2002;
const int val[3] = {5,3,2};

int idol[N][3];

double dp2[N][N];
// i回以上アピールをする確率
double p[N];

double dp[N][3];

double E[3][N];

int main(){
    int n,m;
    cin >>n >>m;
    rep(i,n)rep(j,3) cin >>idol[i][j];

    dp2[0][0] = 1;
    rep(i,m){
        rep(j,i+1){
            dp2[i+1][j+1] += dp2[i][j]/3;
            dp2[i+1][j] += dp2[i][j]*2/3;
        }
    }

    rep(i,m+1) p[i] = dp2[m][i];
    for(int i=m-1; i>=0; --i) p[i] += p[i+1];

    rep(i,3){
        rep(j,m+1){
            int appeal = j*idol[0][i];

            // 最下位になる確率
            double worst = 1;
            for(int k=1; k<n; ++k){
                // num*idol[k][i]>=appeal
                int num = (appeal+idol[k][i]-1)/idol[k][i];
                if(num>m) worst *= 0;
                else worst *= p[num];
            }

            // 3位以内に入れる確率
            memset(dp,0,sizeof(dp));
            dp[1][0] = 1;
            for(int k=1; k<n; ++k){
                int num = (appeal+idol[k][i]-1)/idol[k][i];
                double win = 0;
                if(num<=m) win = p[num];
                rep(r,3){
                    if(r+1<3) dp[k+1][r+1] += dp[k][r]*win;
                    dp[k+1][r] += dp[k][r]*(1-win);
                }
            }

            E[i][j] = (dp[n][0]+dp[n][1]+dp[n][2])*val[i] - worst;
        }
    }


    double ans = -1234567;
    rep(i,m+1)rep(j,m+1){
        int k = m-i-j;
        if(k<0) continue;
        ans = max(ans, E[0][i]+E[1][j]+E[2][k]);
    }
    printf("%.15f\n", ans);
    return 0;
}
