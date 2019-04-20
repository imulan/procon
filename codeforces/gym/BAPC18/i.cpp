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

// (行き先,容量,逆辺)
struct edge{
    int to;
    int cap;
    int rev;
};

const int MAX_V = 100015; // TODO:initialize
const int F_INF = 1000000010; // TODO:initialize
vector<edge> G[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

void add_edge(int from, int to, int cap){
    G[from].pb({to,cap,(int)G[to].size()});
    G[to].pb({from,0,(int)G[from].size()-1});
}

void dinic_bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s]=0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        rep(i,G[v].size()){
            edge &e = G[v][i];
            if(e.cap>0 && level[e.to]<0){
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}

// 増加パスをdfsで探す
int dinic_dfs(int v, int t, int f){
    if(v==t) return f;
    for(int &i=iter[v]; i<(int)G[v].size(); ++i){
        edge &e=G[v][i];
        if(e.cap>0 && level[v]<level[e.to]){
            int d = dinic_dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

// sからtへの最大流
ll max_flow(int s, int t){
    ll flow = 0;
    while(1){
        dinic_bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while( (f=dinic_dfs(s,t,F_INF)) > 0 ) flow+=f;
    }
}

struct ee{
    int to;
    ll cost;
};

const int N = 100010;
const ll INF = LLONG_MAX/3;
vector<ee> gg[N];

vector<ll> dijkstra(int start, int n){
    vector<ll> dist(n,INF);

    using P = pair<ll,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();
        int v = now.se;
        if(now.fi > dist[v]) continue;

        for(const auto &e:gg[v]){
            if(dist[e.to] > dist[v]+e.cost){
                dist[e.to] = dist[v]+e.cost;
                pq.push({dist[e.to], e.to});
            }
        }
    }

    return dist;
}

int main(){
    int n,m,s;
    scanf(" %d %d %d", &n, &m, &s);

    vector<ll> p(n);
    ll sumP = 0;
    rep(i,n){
        scanf(" %lld", &p[i]);
        sumP += p[i];
    }

    rep(i,m){
        int u,v,w;
        scanf(" %d %d %d", &u, &v, &w);
        --u;
        --v;
        gg[u].pb({v,w});
        gg[v].pb({u,w});
    }

    vector<int> pos(s),cap(s);
    vector<vector<ll>> d(s);
    rep(i,s){
        scanf(" %d %d", &pos[i], &cap[i]);
        --pos[i];

        d[i] = dijkstra(pos[i], n);
    }

    int S = n+s, T = S+1;

    auto check = [&](ll x){
        rep(i,n+s+2) G[i].clear();

        rep(i,n) add_edge(S, i, p[i]);
        rep(i,s){
            add_edge(n+i, T, cap[i]);

            rep(j,n){
                if(d[i][j]<=x){
                    add_edge(j, n+i, p[j]);
                }
            }
        }

        return max_flow(S,T) == sumP;
    };

    ll ng=-1, ok=(1LL<<47)-2;
    while(ok-ng>1){
        ll mid = (ng+ok)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    printf("%lld\n", ok);
    return 0;
}
