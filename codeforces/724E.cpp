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

const int N=10000;
const ll INF = 123456789012345LL;
ll dp[2][N+1];

int main()
{
    int n;
    ll c;
    cin >>n >>c;

    vector<ll> p(n),s(n);
    rep(i,n) cin >>p[i];
    rep(i,n) cin >>s[i];

    fill(dp[0],dp[2],INF);

    auto now = dp[1], prev = dp[0];
    prev[0] = 0;
    rep(i,n)
    {
        fill(now,now+N+1,INF);
        rep(j,i+1)
        {
            now[j+1] = min(now[j+1], prev[j]+s[i]);
            now[j] = min(now[j], prev[j]+p[i]+c*j);
        }
        swap(now,prev);
    }

    ll ans = INF;
    rep(i,N+1) ans = min(ans,prev[i]);
    cout << ans << endl;
    return 0;
}
