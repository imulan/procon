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
const int N = 5010;

ll dp[N][N];

int main()
{
    int n,m;
    cin >>n >>m;
    vector<int> x(n);
    rep(i,n) cin >>x[i];
    vector<pi> h(m);
    rep(i,m) cin >>h[i].fi >>h[i].se;

    sort(all(x));
    sort(all(h));

    fill(dp[0],dp[N],INF);
    dp[0][0] = 0;
    rep(i,m)
    {


    }

    ll ans = dp[m][n];
    if(ans == INF) ans = -1;
    cout << ans << endl;
    return 0;
}
