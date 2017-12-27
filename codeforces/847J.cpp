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

const int MAX_V = 10010; // TODO:initialize
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

using pi = pair<int,int>;

int main()
{
    int n,m;
    cin >>n >>m;

    vector<pi> e(m);
    rep(i,m)
    {
        cin >>e[i].fi >>e[i].se;
        --e[i].fi; --e[i].se;
    }

    int ng=-1, ok=5000;
    vector<pi> ans;
    while(ok-ng>1)
    {
        rep(i,MAX_V) G[i].clear();
        int mid=(ng+ok)/2;

        int S=n+m+1, T=S+1;
        rep(i,m) add_edge(S,n+i,1);
        rep(i,m)
        {
            add_edge(n+i,e[i].fi,1);
            add_edge(n+i,e[i].se,1);
        }
        rep(i,n) add_edge(i,T,mid);

        if(max_flow(S,T)==m)
        {
            ok=mid;

            ans.clear();
            rep(i,m)
            {
                for(const auto &E:G[n+i])
                {
                    if(E.cap==0)
                    {
                        int from = E.to;
                        int to = e[i].fi+e[i].se-from;
                        ans.pb({from+1,to+1});
                        break;
                    }
                }
            }
        }
        else ng=mid;
    }

    cout << ok << endl;
    rep(i,m) cout << ans[i].fi << " " << ans[i].se << endl;
    return 0;
}
