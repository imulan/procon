#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

struct edge{ int to,cap,rev; };

const int MAX_V = 222;
const int F_INF = 19191919;
vector<edge> G[MAX_V];
int level[MAX_V], iter[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].pb({to,cap,(int)G[to].size()});
    G[to].pb({from,0,(int)G[from].size()-1});
}

void dinic_bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        rep(i,G[v].size()){
            edge &e = G[v][i];
            if(e.cap>0 & level[e.to]<0){
                level[e.to] = level[v]+1;
                que.push(e.to);
            }
        }
    }
}

int dinic_dfs(int v, int t, int f){
    if(v==t) return f;
    for(int &i=iter[v]; i<(int)G[v].size(); ++i){
        edge &e = G[v][i];
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

int max_flow(int s, int t){
    int flow = 0;
    while(1){
        dinic_bfs(s);
        if(level[t]<0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while( (f=dinic_dfs(s,t,F_INF)) > 0 ) flow += f;
    }
}

int solve(){
    int h,w;
    cin >>h >>w;

    int one = 0;
    vector<vector<int>> u(h,vector<int>(w));
    rep(i,h)rep(j,w){
        cin >>u[i][j];
        one += u[i][j];
    }

    vector<int> f(w),s(h);
    rep(i,w) cin >>f[i];
    rep(i,h) cin >>s[i];

    rep(i,h)rep(j,w){
        if(u[i][j]==1) {
            if(min(f[j],s[i]) == 0) return -1;
        }
    }

    rep(i,h){
        int tmp = 0;
        rep(j,w)if(u[i][j]) tmp = max(tmp, min(s[i],f[j]));
        if(tmp < s[i]) return -1;
    }

    rep(i,w){
        int tmp = 0;
        rep(j,h)if(u[j][i]) tmp = max(tmp, min(f[i],s[j]));
        if(tmp < f[i]) return -1;
    }

    int ans = 0;
    for(int ww=100; ww>=2; --ww){
        //printf(" ww %d\n", ww);
        rep(i,MAX_V) G[i].clear();

        int S = h+w, T = S+1;
        rep(i,h) add_edge(S,i,1);
        rep(i,w) add_edge(h+i,T,1);

        rep(i,h)rep(j,w)if(u[i][j] && s[i]==ww && f[j]==ww){
//            printf(" ww %d:: %d -> %d\n",ww,i,j);
            add_edge(i,h+j,1);
        }

        int ff = max_flow(S,T);
//        printf(" ff %d\n", ff);

        int ct = 0;
        rep(i,h) ct += (s[i]==ww);
        rep(i,w) ct += (f[i]==ww);

        ans += (ww-1)*(ct-ff);
    }
    ans += one;

    return ans;
}

int main(){
    cout << solve() << endl;
    return 0;
}