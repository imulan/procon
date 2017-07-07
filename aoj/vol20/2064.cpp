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

struct edge{int to,cap,rev;};

const int MAX_V = 2000;
const int F_INF = 19191919;
vector<edge> G[MAX_V];
int lv[MAX_V], it[MAX_V];

void add_edge(int from, int to, int cap){
    G[from].pb({to,cap,(int)G[to].size()});
    G[to].pb({from,0,(int)G[from].size()-1});
}

void dinic_bfs(int s){
    fill(lv,lv+MAX_V,-1);
    queue<int> que;
    lv[s]=0;
    que.push(s);
    while(!que.empty()){
        int v = que.front(); que.pop();
        rep(i,G[v].size()){
            edge &e = G[v][i];
            if(e.cap>0 && lv[e.to]<0){
                lv[e.to] = lv[v]+1;
                que.push(e.to);
            }
        }
    }
}

int dinic_dfs(int v, int t, int f){
    if(v==t) return f;
    for(int &i=it[v]; i<G[v].size(); ++i){
        edge &e = G[v][i];
        if(e.cap>0 && lv[v]<lv[e.to]){
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
        if(lv[t]<0) return flow;
        fill(it,it+MAX_V,0);
        int f;
        while((f=dinic_dfs(s,t,F_INF))>0) flow+=f;
    }
}

int main()
{
    int n;
    while(scanf(" %d", &n),n)
    {
        rep(i,MAX_V) G[i].clear();

        unordered_map<int,int> m;
        int M = 0;

        int ISSAC;
        scanf(" %d", &ISSAC);
        while(ISSAC--)
        {
            int day;
            scanf(" %d", &day);
            if(!m.count(day)) m[day] = M++;
        }

        vector<int> k(n);
        vector<vector<int>> s(n);

        rep(i,n)
        {
            scanf(" %d", &k[i]);
            rep(j,k[i])
            {
                int day;
                scanf(" %d", &day);
                if(m.count(day)) s[i].pb(m[day]);
            }
            k[i] = s[i].size();
        }

        int S = n+M, T = S+1;
        rep(i,n)
        {
            add_edge(S,i,1);
            rep(j,k[i]) add_edge(i,n+s[i][j],1);
        }
        rep(i,M) add_edge(n+i,T,1);

        printf("%d\n", max_flow(S,T));
    }
    return 0;
}
