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

const int INF=123456789;

int n,d;
int c[365][3000];

int dp[366][3001][3];

int main()
{
    scanf(" %d %d", &n, &d);
    rep(i,d)rep(j,n) scanf(" %d", &c[i][j]);

    rep(i,366)rep(j,3001)rep(k,3) dp[i][j][k]=INF;

    rep(i,n) dp[0][i][0]=c[0][i];
    for(int i=1; i<d; ++i)
    {
        // 前日と同じ店
        rep(j,n)rep(k,3)
        {
            int nk = min(2,k+1);
            int MUL = (nk==1)?9:7;
            dp[i][j][nk] = min(dp[i][j][nk], dp[i-1][j][k]+c[i][j]*MUL/10);
        }

        // 前日と違う店
        int MIN=INF;
        rep(j,n)rep(k,3) MIN = min(MIN,dp[i-1][j][k]);

        rep(j,n) dp[i][j][0] = min(dp[i][j][0], MIN+c[i][j]);
    }

    int ans=INF;
    rep(i,n)rep(j,3) ans=min(ans,dp[d-1][i][j]);
    printf("%d\n", ans);
    return 0;
}
