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
const int MAX_V = 10010;// TODO:initialize
const int F_INF = 191919191; // TODO:initialize
vector<edge> G[MAX_V];
int level[MAX_V]; // sからの距離
int iter[MAX_V]; // どこまで調べ終わったか

void add_edge(int from, int to, int cap){
    // printf(" %d -> %d  ( %d ) \n",from,to,cap);
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
        while( (f=dinic_dfs(s,t,F_INF)) > 0 ) flow+=f;
    }
}

map<int,int> factorize(int n){
    int t = n;
    map<int,int> ret;
    for(int i=2; i*i<=n; ++i){
        while(t%i==0){
            t /= i;
            ++ret[i];
        }
    }
    if(t>1) ++ret[t];
    return ret;
}

const int N = 10001;
bool prime[N];
bool powprime[N];

using pi = pair<int,int>;
vector<pi> divs;
int rr;
void dfs(int dep, int val){
    if(dep == divs.size()){
        if(rr+1 == val) return;
        // printf(" rr+1  %d -> val %d\n",rr+1,val);
        add_edge(rr,val-1,F_INF);
        return;
    }

    int d = divs[dep].fi;
    int num = divs[dep].se;
    rep(i,num+1){
        dfs(dep+1, val);
        val *= d;
    }
}

int main(){
    fill(prime, prime+N, true);
    prime[0] = prime[1] = false;
    for(int i=2; i<N; ++i){
        if(prime[i]){
            for(int j=2*i; j<N; j+=i) prime[j] = false;

            for(int j=i; j<N; j*=i) powprime[j] = true;
        }
    }

    int n;
    scanf(" %d", &n);
    vector<int> v(n),c(n);
    rep(i,n) scanf(" %d", &v[i]);
    rep(i,n) scanf(" %d", &c[i]);

    int S = n, T = n+1;

    rep(i,n){
        add_edge(S,i,v[i]);

        map<int,int> f = factorize(i+1);
        if(f.size()==1){
            auto itr = f.begin();

            int p = itr->fi;
            int num = itr->se;

            for(int j=1; j<i+1; j*=p){
                add_edge(i,j-1,F_INF);
            }

            // printf(" ::::::: i %d  p %d  num %d\n",i,p,num);

            add_edge(i,T,(2*num-1)*c[p-1]);
        }
        else{
            rr = i;
            divs.clear();
            for(const auto &ppp:f) divs.pb(ppp);
            dfs(0,1);
        }
    }

    int sv = 0;
    rep(i,n) sv += v[i];

    printf("%d\n", sv - max_flow(S,T));
    return 0;
}
