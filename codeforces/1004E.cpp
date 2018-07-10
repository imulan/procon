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

struct edge{
    int to;
    ll cost;
};

const int N = 100010;
vector<edge> G[N];

ll d[N];
int par[N];
ll parw[N];
int dep[N];
void dfs(int x, int p){
    d[x] = 0;
    for(const auto &e:G[x])if(e.to!=p){
        par[e.to] = x;
        parw[e.to] = e.cost;
        dep[e.to] = dep[x]+1;

        dfs(e.to, x);
        d[x] = max(d[x], d[e.to]+e.cost);
    }
}

ll g[N];
void dfs2(int x, int p, ll v){
    g[x] = max(d[x], v);

    vector<ll> w;
    for(const auto &e:G[x])if(e.to!=p) w.pb(d[e.to]+e.cost);
    w.pb(v);
    sort(all(w));
    int W = w.size();

    for(const auto &e:G[x])if(e.to!=p){
        ll nv = w[W-1];
        if(d[e.to]+e.cost==w[W-1]) nv = w[W-2];
        dfs2(e.to, x, nv+e.cost);
    }
}


ll calc(int root, int n, int k){
    // dbg(root);
    par[root]=-1;
    parw[root]=0;
    dep[root]=0;
    dfs(root,-1);

    ll l=-1, r=1000000000;
    // ll l=0, r=20;
    while(r-l>1){
        ll mid = (l+r)/2;

        vector<bool> must(n);
        rep(i,n){
            if(i==root) must[i]=true;
            else{
                if(d[i]+parw[i]>mid) must[i] = true;
            }
        }

        bool ok = false;

        int ct = 0;
        rep(i,n) ct += must[i];

        // dbg(mid);
        // dbg(must);

        if(ct<=k){
            ok = true;

            vector<bool> vis(n);

            priority_queue<pi> pq;
            rep(i,n)if(root!=i && must[i]) pq.push({dep[i],i});

            rep(_,2)if(!pq.empty()){
                int nx = -1;
                while(!pq.empty()){
                    pi cur = pq.top();
                    pq.pop();
                    nx = cur.se;
                    if(!vis[nx]) break;
                }
                if(nx==-1) break;
                // dbg(nx);

                while(nx!=root){
                    if(vis[nx]){
                        ok = false;
                        break;
                    }
                    vis[nx] = true;
                    nx = par[nx];
                }
            }
            while(!pq.empty()){
                pi cur = pq.top();
                if(!vis[cur.se]) break;
                pq.pop();
            }

            if(!pq.empty()) ok = false;
        }

        if(ok) r=mid;
        else l=mid;
    }
    return r;
}

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    rep(i,n-1){
        int u,v,D;
        scanf(" %d %d %d", &u, &v, &D);
        --u;
        --v;
        G[u].pb({v,D});
        G[v].pb({u,D});
    }

    dfs(0,-1);
    dfs2(0,-1,0);

    ll min_g = INF;
    rep(i,n) min_g = min(min_g, g[i]);

    vector<int> roots;
    rep(i,n)if(g[i]==min_g) roots.pb(i);

    ll ans = INF;
    for(int root:roots){
        // dbg(root);
        ans = min(ans, calc(root,n,k));
    }
    cout << ans << endl;
    return 0;
}
