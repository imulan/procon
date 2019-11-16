#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int N = 333;
const ll INF = LLONG_MAX/3;

ll dp[N][N][N];

int main(){
    int n,x;
    cin >>n >>x;

    vector<ll> h(n);
    vector<ll> uh;
    rep(i,n){
        cin >>h[i];
        uh.pb(h[i]);
    }

    uh.pb(0);
    sort(all(uh));
    uh.erase(unique(all(uh)), uh.end());
    int U = uh.size();

    unordered_map<ll,int> m;
    rep(i,U) m[uh[i]] = i;

    rep(i,N)rep(j,N)rep(k,N) dp[i][j][k] = INF;
    rep(i,U){
        int nj = 1;
        if(uh[i] == h[0]) nj = 0;
        dp[1][nj][i] = uh[i];
    }

    for(int i=1; i<n; ++i)rep(j,x+1)rep(k,U){
        int idx = m[h[i]];

        // uh[k]に揃える
        int nj = j+1;
        if(k == idx) nj = j;
        if(nj<=x) dp[i+1][nj][k] = min(dp[i+1][nj][k], dp[i][j][k]);

        // そのまま
        ll cost = 0;
        if(uh[k] < h[i]) cost = h[i]-uh[k];
        dp[i+1][j][idx] = min(dp[i+1][j][idx], dp[i][j][k]+cost);
    }

    ll ans = INF;
    rep(i,x+1)rep(j,U) ans = min(ans, dp[n][i][j]);
    cout << ans << "\n";
    return 0;
}
