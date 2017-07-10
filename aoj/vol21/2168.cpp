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

const int MAX_V = 454; // TODO:initialize
const int F_INF = 1919; // TODO:initialize
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

int main()
{
    int H,W,C,M,Nw,Nc,Nm;
    while(cin>>H>>W>>C>>M>>Nw>>Nc>>Nm,(H!=-1))
    {
        rep(i,MAX_V) G[i].clear();
        int S = H+2*W+2*C+2*M, T = S+1;

        int n,v;
        rep(i,W)
        {
            cin >>n;
            while(n--)
            {
                cin >>v;
                add_edge(v-1,H+i,1);
            }

            add_edge(H+i,H+W+i,1);
            add_edge(H+W+i,T+3,1);
        }
        rep(i,C)
        {
            cin >>n;
            while(n--)
            {
                cin >>v;
                add_edge(H+W+v-1,H+2*W+i,1);
            }

            add_edge(H+2*W+i,H+2*W+C+i,1);
            add_edge(T+2,H+2*W+i,1);
            add_edge(H+2*W+C+i,T+5,1);
        }
        rep(i,M)
        {
            cin >>n;
            while(n--)
            {
                cin >>v;
                add_edge(H+2*W+C+v-1,H+2*W+2*C+i,1);
            }

            add_edge(H+2*W+2*C+i,H+2*W+2*C+M+i,1);
            add_edge(T+4,H+2*W+2*C+i,1);
            add_edge(H+2*W+2*C+M+i,T,1);
        }

        rep(i,H)
        {
            add_edge(S,i,1);
            add_edge(i,T+1,1);
        }

        add_edge(T+1,T+2,Nw);
        add_edge(T+3,T+4,Nc);
        add_edge(T+5,T,Nm);
        cout << max_flow(S,T) << endl;
    }
    return 0;
}
