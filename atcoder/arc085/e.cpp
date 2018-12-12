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

/* Dinic */

// (行き先,容量,逆辺)
struct edge{
    int to;
    ll cap;
    int rev;
};

const int MAX_V = 111; // TODO:initialize
const ll F_INF = LLONG_MAX/3; // TODO:initialize
vector<edge> G[MAX_V];
ll level[MAX_V]; // sからの距離
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
            ll d = dinic_dfs(e.to,t,min(f,e.cap));
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

/*
「Xが赤でYが青だとZ円罰金」
X->Yに容量Zの辺を貼る

「Xが赤 or 青だとZ円罰金」
赤だと罰金:X->Tに容量Zの辺
青だと罰金:S->Xに容量Zの辺
*/

int main(){
    int n;
    cin >>n;
    vector<ll> a(n);
    rep(i,n) cin >>a[i];

    // S:割らない, T:割る
    int S = n, T = n+1;

    ll ss = 0;
    rep(i,n){
        if(a[i]>0){
            ss += a[i];
            add_edge(S,i,a[i]);
        }
        else{
            add_edge(i,T,-a[i]);
        }

        int I=i+1;
        rep(j,i){
            int J=j+1;
            if(I%J == 0) add_edge(i,j,F_INF);
        }
    }

    cout << ss - max_flow(S,T) << endl;
    return 0;
}
