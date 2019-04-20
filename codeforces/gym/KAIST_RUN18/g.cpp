#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0; (i)<(int)(n); ++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const ll INF = LLONG_MAX/3;

struct edge{ int to; ll cost; };

const int N = 252525;
vector<edge> G[N];

void PRINT(ll x){
    printf("%lld.%d\n", x/2, 5*(x%2));
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
        
    vector<int> a(m),b(m);
    vector<ll> w(m);
    rep(i,m){
        int u,v;
        scanf(" %d %d %lld", &u, &v, &w[i]);
        --u;
        --v;
        
        w[i] *= 2;
        G[u].pb({v,w[i]});
        G[v].pb({u,w[i]});

        a[i] = u;
        b[i] = v;
    }
    
    int k;
    scanf(" %d", &k);
    vector<int> x(k);
    rep(i,k){
        scanf(" %d", &x[i]);
        --x[i];
    }
    
    using P = pair<ll,int>;
    vector<P> d(n,{INF,N});
    
    using dat = pair<P,int>;
    priority_queue<dat, vector<dat>, greater<dat>> pq;
    rep(i,k){
        d[x[i]] = {0,x[i]};
        pq.push({d[x[i]], x[i]});    
    }
    
    while(!pq.empty()){
        dat now = pq.top();
        pq.pop();
        
        P D = now.fi;
        int v = now.se;
        if(D > d[v]) continue;
        
        int idx = D.se;
        for(const auto &e:G[v]){
            ll nd = D.fi+e.cost;
            P nx = {nd,idx};
            if(d[e.to] > nx){
                d[e.to] = nx;
                pq.push({d[e.to], e.to});
            }
        }
    }
    
    
    vector<ll> ans(n);
    rep(i,m){
//    printf(" i %d\n",i);
        if( d[a[i]].se == d[b[i]].se ){
            ans[d[a[i]].se] += w[i];
        }
        else{
            ll DA = d[a[i]].fi, DB = d[b[i]].fi;
            ll W = DA+DB+w[i];
            W/=2;
  //          printf(" DA %lld DB %lld W %lld\n",DA,DB,W);
  //          printf("  %d,  %d\n ",d[a[i]].se,d[b[i]].se);
            ans[d[a[i]].se] += W-DA;
            ans[d[b[i]].se] += W-DB;
        }
    }
    
    rep(i,k) PRINT(ans[x[i]]);
    return 0;
}
