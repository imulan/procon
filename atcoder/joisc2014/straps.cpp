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

const ll INF = LLONG_MAX/3;
ll dp[2001][2001];

int main()
{
    int n;
    cin >>n;
    vector<pi> s(n);
    rep(i,n)
    {
        int a,b;
        cin >>a >>b;
        s[i] = pi(a-1,b);
    }
    sort(all(s),greater<pi>());

    fill(dp[0],dp[2001],-INF);
    dp[0][1]=0;
    rep(i,n)rep(j,2001)
    {
        dp[i+1][j] = max(dp[i+1][j],dp[i][j]);

        int nj = min(2000,j+s[i].fi);
        if(nj<0) continue;
        dp[i+1][nj] = max(dp[i+1][nj],dp[i][j]+s[i].se);
    }

    ll ans = -INF;
    rep(i,2001) ans = max(ans,dp[n][i]);
    cout << ans << endl;
    return 0;
}
