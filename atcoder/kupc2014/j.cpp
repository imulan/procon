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

const int INF = 19191919;
int dp[101][101];

int main()
{
    int n,m,p;
    cin >>n >>m >>p;
    vector<int> x(m);
    rep(i,m) cin >>x[i];

    vector<int> sx(m+1);
    rep(i,m) sx[i+1] = sx[i]+x[i];

    fill(dp[0],dp[101],-INF);
    dp[0][0]=0;
    rep(i,n)rep(j,n)if(dp[i][j]>=0)
    {
        int money = dp[i][j]+p;
        rep(k,m+1)if(j+k<=n)
        {
            if(money-sx[k]>=0) dp[i+1][j+k]=max(dp[i+1][j+k], money-sx[k]);
        }
    }

    // rep(i,n+1)rep(j,n+1) printf("dp[%d][%d]= %d\n", i,j,dp[i][j]);

    int ans = 0;
    while(dp[ans][n]<0) ++ans;
    cout << ans << endl;
    return 0;
}
