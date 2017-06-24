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

// (行き先,容量,逆辺)
struct edge{ int to,cap,rev; };

const int MAX_V = 111; // TODO:initialize
const int F_INF = 99999999; // TODO:initialize
vector<edge> G[MAX_V],z[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

void add_edge(int from, int to, int cap){
    G[from].pb({to,cap,(int)G[to].size()});
    G[to].pb({from,cap,(int)G[from].size()-1});
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
    for(int &i=iter[v]; i<G[v].size(); ++i){
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

const int INF=5555555;
int ff[MAX_V][2]={};

void solve()
{
    bool direct = false;
    int K,N,M;
    cin >>K >>N >>M;
    vector<int> a(M),b(M),c(M);
    rep(i,M)
    {
        cin >>a[i] >>b[i] >>c[i];
        if(a[i]>b[i]) swap(a[i],b[i]);
        add_edge(a[i],b[i],c[i]);
        direct|=(a[i]==0 && 1<=b[i] && b[i]<=K);
    }

    if(direct)
    {
        cout << "overfuro" << endl;
        return;
    }

    int S=K+N+1,T=0;
    for(int i=1; i<=K; ++i) add_edge(S,i,INF);

    int F = max_flow(S,T);

    rep(i,MAX_V) z[i]=G[i];

    ff[S][0]=INF;
    rep(i,S)
    {
        rep(j,MAX_V) G[j]=z[j];
        ff[i][0] = max_flow(S,i);
    }
    ff[0][1]=INF;
    for(int i=1; i<=S; ++i)
    {
        rep(j,MAX_V) G[j]=z[j];
        ff[i][1] = max_flow(i,T);
    }

    int add = 0;
    rep(i,M)
    {
        int u=a[i], v=b[i];
        add = max(add,min(ff[u][0],ff[v][1]));
        add = max(add,min(ff[v][0],ff[u][1]));
    }

    cout << F+add << endl;
}

int main()
{
    solve();
    return 0;
}
