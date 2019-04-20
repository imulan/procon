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

const int MAX_V = 2000; // TODO:initialize
const int F_INF = 19191919; // TODO:initialize
vector<edge> G[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

void add_edge(int from, int to, int cap){
//    printf(" %d -> %d  (%d)\n",from,to,cap);
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

int main(){
    int n,Q,S;
    cin >>n >>Q >>S;

    int src = 2*Q*n+n, sink = src+1;

    vector<int> q(S);
    rep(i,S){
        cin >>q[i];
        --q[i];
    }

    vector<int> c(Q);
    rep(i,Q) cin >>c[i];

    int sa = 0;
    rep(i,n){
        int d;
        cin >>d;

        add_edge(2*Q*n+i,sink,d);

        vector<int> dat(Q);
        rep(j,S){
            int a;
            cin >>a;
            dat[q[j]] += a;
            sa += a;
        }

        rep(j,Q){
            add_edge(2*Q*i+2*j, 2*Q*i+2*j+1, c[j]);

            add_edge(src,2*Q*i+2*j,dat[j]);
            add_edge(2*Q*i+2*j+1,2*Q*n+i,F_INF);

            if(i<n-1) add_edge(2*Q*i+2*j+1, 2*Q*(i+1)+2*j, c[j]);
        }
    }

    int f = max_flow(src,sink);
//    printf(" f %d\n",f);

    string ans = "possible";
    if(f!=sa) ans = "im"+ans;
    cout << ans << endl;
    return 0;
}