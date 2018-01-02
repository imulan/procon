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

const int A = 111;
const int INF = 191919;
int dp[A][A];

int main()
{
    int n,m;
    cin >>n >>m;
    vector<pi> p(m);
    rep(i,m)
    {
        int a,b;
        cin >>a >>b;
        p[i] = {a-1,b-1};
    }
    sort(all(p));

    rep(i,A)rep(j,A) dp[i][j]=INF;
    dp[0][0]=0;
    rep(i,m)rep(j,n+1)
    {
        dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
        if(p[i].fi<=j) dp[i+1][p[i].se+1] = min(dp[i+1][p[i].se+1],dp[i][j]+1);
    }

    int ans = dp[m][n];
    if(ans==INF) cout << "Impossible" << endl;
    else cout << ans << endl;
    return 0;
}
