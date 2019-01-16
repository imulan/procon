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

/* 基本要素 */
typedef complex<double> Point;
typedef pair<Point, Point> Line;
typedef vector<Point> VP;
const double INF = 1e9;

Point READP(){
    double x,y;
    scanf(" %lf %lf", &x, &y);
    return {x,y};
}

VP READ(){
    return VP({READP(), READP()});
}

const int N = 14;
double dp[1<<N][N][2];

int main(){
    int CASE = 1;
    int n;
    while(scanf(" %d", &n),n){
        vector<VP> s(n);
        rep(i,n) s[i] = READ();

        rep(i,1<<N)rep(j,N)rep(k,2) dp[i][j][k] = INF;
        rep(i,n)rep(j,2) dp[1<<i][i][j] = 0;

        rep(mask,1<<n)rep(i,n){
            if(!(mask>>i&1)) continue;
            rep(ii,2){
                double D = dp[mask][i][ii];
                Point start = s[i][ii];

                // next
                rep(j,n){
                    if(mask>>j&1) continue;
                    rep(jj,2){
                        Point goal = s[j][jj];
                        int nmask = mask|(1<<j);
                        dp[nmask][j][!jj] = min(dp[nmask][j][!jj], D+abs(start-goal));
                    }
                }
            }
        }

        double ans = INF;
        rep(i,n)rep(j,2) ans = min(ans, dp[(1<<n)-1][i][j]);

        rep(i,n) ans += abs(s[i][0]-s[i][1]);
        printf("Case %d: %.5f\n", CASE, ans);
        ++CASE;
    }
    return 0;
}
