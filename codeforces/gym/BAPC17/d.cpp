#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)n; ++(i))
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define pb push_back

struct edge{
    int to;
    ll cost;
};

using P = pair<ll,int>;

const int N = 100000;
const ll INF = LLONG_MAX/3;
vector<edge> G[N];
ll d[N];
int par[N];

void dijkstra(int s){
    fill(d,d+N,INF);
    fill(par,par+N,-1);

    priority_queue<P,vector<P>,greater<P>> pq;
    d[s] = 0;
    pq.push({0,s});
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();
        int v = now.se;
        if(now.fi>d[v]) continue;

        for(const auto &e:G[v]){
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                par[e.to] = v;
                pq.push({d[e.to],e.to});
            }
        }
    }
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> a(m),b(m);
    vector<ll> w(m);
    rep(i,m){
        scanf(" %d %d %lld", &a[i], &b[i], &w[i]);
        G[a[i]].pb({b[i],w[i]});
        G[b[i]].pb({a[i],w[i]});
    }

    dijkstra(1);

    rep(i,N) G[i].clear();

    // rep(i,n) printf("par[%d] =%d\n", i,par[i]);
    rep(i,m){
        if(par[a[i]]!=b[i]){
            // printf(" %d -> %d\n",a[i],b[i]);
            G[a[i]].pb({b[i],w[i]});
        }
        if(par[b[i]]!=a[i]){
            // printf(" %d -> %d\n",b[i],a[i]);
            G[b[i]].pb({a[i],w[i]});
        }
    }

    dijkstra(0);
    // rep(i,n) printf("par[%d] =%d\n", i,par[i]);

    int now = 1;
    vector<int> ans;
    while(now != -1){
        ans.pb(now);
        now = par[now];
    }

    if(ans.back()==0){
        reverse(all(ans));
        int sz = ans.size();
        printf("%d", sz);
        rep(i,sz) printf(" %d", ans[i]);
        printf("\n");
    }
    else printf("impossible\n");
    return 0;
}
