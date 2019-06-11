#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
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
    ll cap;
    int rev;
};

const int MAX_V = 2000; // TODO:initialize
const ll F_INF = LLONG_MAX/100000; // TODO:initialize
vector<edge> G[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

void add_edge(int from, int to, ll cap){
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
ll dinic_dfs(int v, int t, ll f){
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
        ll f;
        while( (f=dinic_dfs(s,t,F_INF)) > 0 ) flow+=f;
    }
}

const int N = 55;
vector<int> neighbor[N][N];

int main(){
    int h,w,W;
    cin >>h >>w >>W;
    vector<vector<int>> b(h, vector<int>(w));
    rep(i,h)rep(j,w) cin >>b[i][j];

    // 予めもらうreward
    ll s = 0;
    rep(i,h)rep(j,w) s += b[i][j];

    vector<ll> a;
    vector<int> flip;
    int P = 0;
    rep(i,h-1)rep(j,w-1)if((i+j)%2 == 0){
        ll t = 0;
        rep(ii,2)rep(jj,2){
            int y=i+ii, x = j+jj;
            neighbor[y][x].pb(P);
            t += b[y][x];
        }
        a.pb(t);
        flip.pb(i%2);
        ++P;
    }

    int S = MAX_V-2, T = MAX_V-1;
    rep(i,P){
        // on だとpenalty W
        // off だとpenalty a[i]
        if(flip[i]){
            add_edge(i,T,a[i]);
            add_edge(S,i,W);
        }
        else{
            add_edge(i,T,W);
            add_edge(S,i,a[i]);
        }
    }

    rep(i,h)rep(j,w)if(neighbor[i][j].size()==2){
        int x = neighbor[i][j][0], y = neighbor[i][j][1];
        assert((flip[x]^flip[y]) == 1);
        // 2つの電源が両方on だとpenalty b[i][j]
        s += b[i][j];
        if(flip[x]) add_edge(y,x,b[i][j]);
        else add_edge(x,y,b[i][j]);
    }

    cout << s - max_flow(S,T) << endl;
    return 0;
}
