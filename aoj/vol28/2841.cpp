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

const int A = 10000;
const int INF = 19191919;

int dp[101][A+1];

int main()
{
    int n,C;
    cin >>n >>C;
    vector<int> a(n),b(n),c(n);
    rep(i,n) cin >>a[i] >>b[i] >>c[i];

    fill(dp[0],dp[101],-INF);
    dp[0][0]=0;
    rep(i,n)
    {
        for(int j=C; j>=0; --j)if(j+c[i]<=C)
        {
            int nx = j+c[i];
            rep(k,A+1)
            {
                dp[nx][min(A,k+a[i])] = max(dp[nx][min(A,k+a[i])], dp[j][k]+b[i]);
                dp[nx][min(A,k+b[i])] = max(dp[nx][min(A,k+b[i])], dp[j][k]+a[i]);
            }
        }
    }

    int ans = 0;
    rep(i,C+1)rep(j,A+1) ans = max(ans,min(j,dp[i][j]));
    cout << ans << endl;
    return 0;
}
