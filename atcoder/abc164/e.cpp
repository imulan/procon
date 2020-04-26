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

using pi = pair<int,int>;
using P = pair<ll,pi>;

struct edge{ int to,cost,time; };

const int N = 50;
const int C = 2525;
const ll INF = LLONG_MAX/3;

vector<edge> G[N];
ll dp[N][C];

int main(){
    int n,m,s;
    cin >>n >>m >>s;
    s = min(s,C-1);

    rep(i,m){
        int u,v,a,b;
        cin >>u >>v >>a >>b;
        --u;
        --v;
        G[u].pb({v,a,b});
        G[v].pb({u,a,b});
    }

    vector<int> c(n),d(n);
    rep(i,n) cin >>c[i] >>d[i];

    rep(i,N)rep(j,C) dp[i][j] = INF;
    dp[0][s] = 0;

    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,{0,s}});
    while(!pq.empty()){
        P p = pq.top();
        pq.pop();

        int pos = p.se.fi, cur = p.se.se;
        ll now = dp[pos][cur];
        if(p.fi > now) continue;

        // exchange
        int nj = min(cur+c[pos], C-1);
        if(dp[pos][nj] > now+d[pos]){
            dp[pos][nj] = now+d[pos];
            pq.push({dp[pos][nj], {pos,nj}});
        }

        // move
        for(const auto &e:G[pos])if(cur >= e.cost){
            nj = cur - e.cost;
            if(dp[e.to][nj] > now+e.time){
                dp[e.to][nj] = now+e.time;
                pq.push({dp[e.to][nj], {e.to,nj}});
            }
        }
    }

    for(int i=1; i<n; ++i){
        ll ans = INF;
        rep(j,C) ans = min(ans, dp[i][j]);
        cout << ans << "\n";
    }
    return 0;
}
