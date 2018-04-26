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

const int N = 10010;
ll dp[N], nx[N];

int main(){
    int n;
    ll W,B,X;
    cin >>n >>W >>B >>X;

    vector<int> c(n), cost(n);
    rep(i,n) cin >>c[i];
    rep(i,n) cin >>cost[i];

    vector<pi> v;
    rep(i,n)rep(j,c[i]) v.pb({i,cost[i]});
    v.pb({n,0});
    int V = v.size();

    fill(dp,dp+N,-INF);
    dp[0]=W;
    rep(i,V-1){
        int w = v[i].se;

        ll add = 0;
        if(v[i].fi != v[i+1].fi) add = X;

        fill(nx,nx+N,-INF);
        rep(j,V+1)if(dp[j]>=0){
            ll cap = W+B*j;
            nx[j] = max(nx[j], min(cap,dp[j]+add));

            if(dp[j]-w >= 0){
                cap += B;
                nx[j+1] = max(nx[j+1], min(cap, dp[j]-w+add));
            }
        }

        rep(j,N) dp[j] = nx[j];
    }

    int ans = 0;
    rep(i,N)if(dp[i]>=0) ans = max(ans,i);
    cout << ans << endl;
    return 0;
}
