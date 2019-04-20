#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

// (行き先,容量,逆辺)
struct edge{ int to,cap,rev; };

const int MAX_V = 303; // TODO:initialize
const int F_INF = 191919; // TODO:initialize
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

using pi = pair<int,int>;

int S,T;
bool ave[MAX_V];

bool found;
vector<pi> ans;
stack<int> st;
bool vis[MAX_V];

string ex[MAX_V];

void dfs(int x){
    vis[x] = true;

    if(x==S){
        found = true;
        stack<int> tmp = st;

        vector<int> path;
        while(!tmp.empty()){
            path.pb(tmp.top());
            tmp.pop();
        }

        int sz = path.size();
        vector<pi> v(sz-1);
        rep(i,sz-1) v[i] = {path[i], path[i+1]};

//        printf("sz %d\n", sz);
//        rep(i,sz) printf(" path[%d] = %d\n",i, path[i]);

        int prev = sz-1;
        int idx = sz-2;

        if(sz-1 > 1) assert(ave[v[1].fi]);
        while(idx > 0){
            if(ave[v[idx].fi]){
                for(int i=idx; i<prev; ++i){
                    ans.pb(v[i]);
//                    printf(" %d -> %d\n",v[i].fi,v[i].se);
                }
                ave[v[idx].fi] = false;

                assert(!ave[v[prev-1].se]);
                ave[v[prev-1].se] = true;

                prev = idx;
            }

            --idx;
        }

        v.pb({path.back(), T});
        rep(i,sz){
            int a = v[i].fi, b = v[i].se;
            rep(j,G[b].size()){
                edge &e = G[b][j];
                if(e.to==a && e.cap>0){
                    --e.cap;
                    ++G[e.to][e.rev].cap;
                }
            }
        }
    }

    for(const auto &e:G[x]){
        if(vis[e.to]) continue;
        if(found) break;

        if(e.cap>0){
            if(e.to!=S && e.to!=T && x!=S && x!=T){
                if(ex[e.to][x]!='1') continue;
            }

            st.push(e.to);
            dfs(e.to);
            st.pop();
        }
    }
}


int main(){
    int n,k;
    cin >>n >>k;

    vector<int> a(k),b(k);
    rep(i,k){
        cin >>a[i];
        --a[i];

        ave[a[i]] = true;
    }
    rep(i,k){
        cin >>b[i];
        --b[i];
    }

    rep(i,n) cin >>ex[i];

    S = n;
    T = n+1;

    rep(i,k){
        add_edge(S,a[i],1);
        add_edge(b[i],T,1);
    }
    rep(i,n)rep(j,n){
        if(ex[i][j]=='1') add_edge(i,j,2*n);
    }

    int f = max_flow(S,T);
    if(f != k){
        cout << "NO" << endl;
        return 0;
    }

    rep(i,k){
//        printf(" --- %d --- \n", i);
        found = false;
        st = stack<int>();
        fill(vis,vis+MAX_V,false);
        dfs(T);
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for(const auto &p:ans) cout << p.fi+1 << " " << p.se+1 << endl;
    return 0;
}