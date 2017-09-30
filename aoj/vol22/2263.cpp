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

using pi = pair<int,int>;

const int INF = 19191919;
int dp[1001][1005];

int main()
{
    int n;
    cin >>n;
    vector<pi> p(n);
    rep(i,n) cin >>p[i].se >>p[i].fi;

    sort(all(p));

    fill(dp[0],dp[1001],INF);
    dp[0][0] = 0;
    rep(i,n)
    {
        int a = p[i].se, b = p[i].fi;

        rep(j,n+1)
        {
            dp[i+1][j] = min(dp[i+1][j],dp[i][j]);

            int t = dp[i][j]+a;
            if(t<=b) dp[i+1][j+1] = min(dp[i+1][j+1],t);
        }
    }

    int ans = 0;
    rep(i,n+1)if(dp[n][i]<INF) ans = i;
    cout << ans << endl;
    return 0;
}
