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

const int MAX_V = 333; // TODO:initialize
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


int main(){
    int n,m;
    cin >>n >>m;

    vector<int> ans(n);

    int R = n+2*m;
    int S = R+1, T = S+1;

    rep(i,n){
        add_edge(S,i,1);
        add_edge(i,R,1);
    }

    int sum = 0;
    rep(i,m){
        int s,d,c;
        cin >>s >>d >>c;
        --s;
        --d;
        for(int j=s; j<d; ++j){
            add_edge(j,n+i,1);
        }
        add_edge(d,n+m+i,1);
        add_edge(n+i,T,c);
        add_edge(n+m+i,T,1);

        sum += c+1;
        ans[d] = m+1;
    }

    if(n-sum<0){
        cout << -1 << endl;
        return 0;
    }

    add_edge(R,T,n-sum);

    int f = max_flow(S,T);
    if(f<n){
        cout << -1 << endl;
        return 0;
    }

    rep(i,m){
        for(const auto &e:G[n+i]){
            if(e.to<n && e.cap>0){
                ans[e.to] = i+1;
            }
        }
    }

    rep(i,n) cout << ans[i] << " \n"[i==n-1];
    return 0;
}
