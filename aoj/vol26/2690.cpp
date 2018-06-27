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

using pi = pair<ll,int>;

struct edge{int to,cost;};

const int N = 2002;
const ll INF = LLONG_MAX/3;
vector<edge> G[N];

ll dp[N];
int pw[N];
void dfs(int v, int p, int pe){
    dp[v] = pe;
    pw[v] = pe;
    for(const auto &e:G[v])if(e.to != p){
        dfs(e.to, v, e.cost);
        dp[v] = max(dp[v], dp[e.to]+pe);
    }
    if(p==-1) dp[v] = -INF;
}

int main(){
    int n,m;
    cin >>n >>m;

    rep(i,n-1){
        int a,b,c;
        cin >>a >>b >>c;
        --a;
        --b;
        G[a].pb({b,c});
        G[b].pb({a,c});
    }

    vector<ll> s(n);
    rep(i,n) cin >>s[i];

    vector<ll> cand;
    rep(i,n){
        dfs(i,-1,0);
        // rep(j,n) printf(" %d: dp[%d] = %d\n",i,j,dp[j]);

        vector<ll> add;
        vector<bool> used(n);
        // (value,id)
        priority_queue<pi> pq;
        rep(j,n) pq.push({dp[j],j});

        while(!pq.empty()){
            pi p = pq.top();
            pq.pop();

            ll val = p.fi;
            int id = p.se;
            if(used[id] || id==i) continue;

            // printf(" %d : %d\n", i,id);

            add.pb(s[i]*val);
            int now = id;
            while(now != -1){
                int nx = -1;
                for(const auto &e:G[now]){
                    if(!used[e.to] && dp[now] - pw[now] == dp[e.to]) nx = e.to;
                }

                used[now] = true;
                now = nx;
            }
        }

        for(ll j:add) cand.pb(j);
    }

    sort(all(cand), greater<ll>());
    int sz = cand.size();
    // dbg(sz);dbg(cand);
    ll ans = 0;
    rep(i,min(sz,m)) ans += cand[i];
    cout << ans << endl;
    return 0;
}
