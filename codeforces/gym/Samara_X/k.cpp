#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back

struct edge{
    int to;
    ll cost;
    int ID;
};

const int N = 400000;
vector<edge> G[N],rG[N];

const ll INF = LLONG_MAX/3;

void ADD(int from, int to, ll c, int id){
    G[from].pb({to,c,id});
    rG[to].pb({from,c,id});
}

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> t;
    vector<int> a(n),b(n);
    vector<ll> c(n);
    rep(i,n){
        scanf(" %d %d %lld", &a[i], &b[i], &c[i]);
        t.pb(a[i]);
        t.pb(b[i]);
    }

    sort(all(t));
    t.erase(unique(all(t)), t.end());
    rep(i,n){
        a[i] = lower_bound(all(t), a[i]) - t.begin();
        b[i] = lower_bound(all(t), b[i]) - t.begin();

        ADD(a[i],b[i],c[i],i);
    }

    int T = t.size();
    rep(i,T-1) ADD(i,i+1,0,-1);

    vector<ll> dp(T);
    rep(i,T){
        for(const auto &e:G[i]){
            dp[e.to] = max(dp[e.to], dp[i]+e.cost);
        }
//        printf(" dp[%d] = %lld\n",i,dp[i]);
    }


    vector<ll> min_time(T,INF);
    vector<int> par(T,-1);
    min_time[T-1] = 0;
    for(int i=T-1; i>=0; --i){
        for(const auto &e:rG[i]){
            if(dp[i] != dp[e.to]+e.cost) continue;
            ll add = 0;
            if(e.cost>0) add = t[i]-t[e.to];

            if(min_time[e.to] > min_time[i]+add){
                min_time[e.to] = min_time[i]+add;
                par[e.to] = i;
            }
        }
    }

    vector<int> path;
    int now = 0;
    while(par[now] != -1){
        int nx = par[now];
//        printf(" now %d -> %d\n", now,nx);

        if(dp[now] < dp[nx]){
            for(const auto &e:G[now]){
                if(e.to == nx && dp[e.to] == dp[now]+e.cost){
                    path.pb(e.ID+1);
                    break;
                }
            }
        }
        now = nx;
    }

    int sz = path.size();
    printf("%d %lld %lld\n", sz, dp[T-1], min_time[0]);
    rep(i,sz) printf("%d%c", path[i], " \n"[i==sz-1]);
    return 0;
}