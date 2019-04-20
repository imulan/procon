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
struct edge{ int to,cap,rev; };

const int MAX_V = 1222; // TODO:initialize
const int F_INF = 19191919; // TODO:initialize
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
int max_flow(int s, int t){
    int flow = 0;
    while(1){
        dinic_bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dinic_dfs(s,t,F_INF))>0) flow+=f;
    }
}


struct E{
    int to;
    ll cost;
};

const ll INF = LLONG_MAX/3;

int main(){
    int v,e,n,k;
    scanf(" %d %d %d %d", &v, &e, &n, &k);

    vector<int> ct(v);
    rep(i,n){
        int s;
        scanf(" %d", &s);
        --s;
        ++ct[s];
    }

    vector<vector<E>> g(v);
    rep(i,e){
        int a,b,t;
        scanf(" %d %d %d", &a, &b, &t);
        --a;
        --b;
        g[a].pb({b,t});
        g[b].pb({a,t});
    }

    vector<vector<ll>> d(v,vector<ll>(v,INF));
    rep(i,v){
        vector<ll> dist(v,INF);
        dist[i] = 0;

        using P = pair<ll,int>;
        priority_queue<P, vector<P>, greater<P>> pq;
        pq.push({0,i});
        while(!pq.empty()){
            P now = pq.top();
            pq.pop();
            int pos = now.se;
            if(now.fi>dist[pos]) continue;
            for(const auto &xx:g[pos]){
                if(dist[xx.to] > dist[pos]+xx.cost){
                    dist[xx.to] = dist[pos]+xx.cost;
                    pq.push({dist[xx.to], xx.to});
                }
            }
        }

        rep(j,v) d[i][j] = dist[j];
    }

    int S = 2*v, T = S+1;

    int LIM = 1731312;
    int l = -1, r = LIM;
    while(r-l>1){
        int m = (l+r)/2;

        rep(i,MAX_V) G[i].clear();
        rep(i,v){
            add_edge(S,i,ct[i]);
            add_edge(i+v,T,1);
        }

        rep(i,v)rep(j,v)if(d[i][j]<=m){
            add_edge(i,v+j,1);
        }

        int f = max_flow(S,T);
        if(f>=k) r = m;
        else l = m;
    }

    if(r == LIM) r = -1;
    printf("%d\n", r);
    return 0;
}
