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

const int N = 17;
const ll INF = LLONG_MAX/3;
map<ll,ll> dp[N][N];

int main()
{
    int n,K;
    cin >>n >>K;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    dp[0][0][0]=0;
    rep(i,n)rep(j,i+1)
    {
        for(const auto &p:dp[i][j])
        {
            ll k=p.fi, v=p.se;

            if(!dp[i+1][j+1].count(a[i])) dp[i+1][j+1][a[i]]=INF;
            if(!dp[i+1][j].count(k)) dp[i+1][j][k]=INF;
            if(!dp[i+1][j+1].count(k+1)) dp[i+1][j+1][k+1]=INF;

            if(k<a[i])
            {
                dp[i+1][j+1][a[i]] = min(dp[i+1][j+1][a[i]],v);
            }
            else
            {
                dp[i+1][j][k] = min(dp[i+1][j][k],v);
                dp[i+1][j+1][k+1] = min(dp[i+1][j+1][k+1],v+k+1-a[i]);
            }
        }
    }

    ll ans = INF;
    for(int i=K; i<=n; ++i)for(const auto &p:dp[n][i]) ans = min(ans,p.se);
    cout << ans << endl;
    return 0;
}
