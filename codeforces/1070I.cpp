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

const int MAX_V = 1212; // TODO:initialize
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

vector<int> solve(){
    rep(i,MAX_V) G[i].clear();

    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);

    vector<int> NG(m,0);

    vector<int> deg(n);
    vector<int> a(m),b(m);
    rep(i,m){
        scanf(" %d %d", &a[i], &b[i]);
        --a[i];
        --b[i];
        ++deg[a[i]];
        ++deg[b[i]];
    }

    rep(i,n)if(deg[i] > 2*k) return NG;

    int S = n+m, T = S+1;

    rep(i,m){
        add_edge(S,i,1);
        add_edge(i,m+a[i],1);
        add_edge(i,m+b[i],1);
    }

    int sf = 0;
    rep(i,n){
        if(deg[i]>k){
            int cc = 2*(deg[i]-k);
            add_edge(m+i,T,cc);
            sf += cc;
        }
    }

    int f = max_flow(S,T);
    if(f != sf) return NG;

    vector<int> ret(m);
    int cid = 1;

    rep(i,n){
        vector<int> es;
        for(const auto &e:G[m+i]){
            if(e.cap>0 && e.to<m) es.pb(e.to);
        }

        for(int j=0; j<es.size(); j+=2){
            ret[es[j]] = cid;
            ret[es[j+1]] = cid;
            ++cid;
        }
    }

    rep(i,m)if(ret[i]==0) ret[i] = cid++;

    return ret;
}

int main(){
    int T;
    scanf(" %d", &T);
    rep(ttt,T){
        vector<int> ans = solve();
        int n = ans.size();
        rep(i,n) printf("%d%c", ans[i]," \n"[i==n-1]);
    }
    return 0;
}
