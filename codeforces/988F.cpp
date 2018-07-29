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

const ll INF = LLONG_MAX/3;

const int N = 2002;
ll dp[N][N];

ll u[N];
int rain[N]={};

int main(){
    int a,n,m;
    scanf(" %d %d %d", &a, &n, &m);

    rep(i,n){
        int l,r;
        scanf(" %d %d", &l ,&r);
        ++rain[l];
        --rain[r];
    }
    rep(i,N-1) rain[i+1] += rain[i];

    fill(u,u+N,INF);
    vector<int> w;
    w.pb(0);
    rep(i,m){
        int x,p;
        scanf(" %d %d", &x, &p);
        u[x] = min(u[x], (ll)p);
        w.pb(p);
    }
    sort(all(w));
    w.erase(unique(all(w)), w.end());
    int W = w.size();

    fill(dp[0], dp[N], INF);
    dp[0][0]=0;
    rep(i,a){
        if(u[i]<INF){
            int idx = lower_bound(all(w), u[i]) - w.begin();
            // 持ち変える
            rep(j,W) dp[i][idx] = min(dp[i][idx], dp[i][j]);
        }
        // 捨てる
        rep(j,W) dp[i][0] = min(dp[i][0], dp[i][j]);

        int s=0;
        if(rain[i]) s=1;
        for(int j=s; j<W; ++j){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]+w[j]);
        }
    }

    ll ans = INF;
    rep(i,N) ans = min(ans, dp[a][i]);
    if(ans == INF) ans = -1;
    printf("%lld\n", ans);
    return 0;
}
