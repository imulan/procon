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

// (行き先, 容量, コスト, 逆辺)
struct edge{ int to,cap,cost,rev; };

int V; // TODO:initialize
const int MAX_V = 222; // TODO:initialize
const int INF = 12345678; // TODO:initialize
vector<edge> G[MAX_V];
int h[MAX_V]; // ポテンシャル
int dist[MAX_V];
int prevv[MAX_V], preve[MAX_V]; // 直前の頂点と辺

void add_edge(int from, int to, int cap, int cost){
    G[from].pb({to,cap,cost,(int)G[to].size()});
    G[to].pb({from,0,-cost,(int)G[from].size()-1});
}

// sからtへの流量fの最小費用流(不可能なら-1)
int min_cost_flow(int s, int t, int f, bool neg = false){
    int res = 0;
    fill(h,h+V,0);
    while(f>0){
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        fill(dist,dist+V,INF);
        dist[s]=0;
        if(neg)
        {
            // bellman-fordでhを更新
            neg = false;
            bool update;
            do{
                update = false;
                rep(v,V){
                    if(dist[v] == INF) continue;
                    rep(i,G[v].size()){
                        edge &e = G[v][i];
                        if(e.cap>0 && dist[e.to]>dist[v]+e.cost){
                            dist[e.to]=dist[v]+e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update = true;
                        }
                    }
                }
            }while(update);
        }
        else
        {
            // dijkstraでhを更新
            pq.push(pi(0,s));
            while(!pq.empty()){
                pi p = pq.top();
                pq.pop();
                int v = p.se;
                if(p.fi>dist[v]) continue;
                rep(i,G[v].size()){
                    edge &e = G[v][i];
                    if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                        dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        pq.push(pi(dist[e.to],e.to));
                    }
                }
            }
        }

        // これ以上流せない
        if(dist[t]==INF) return -1;

        rep(v,V) h[v] += dist[v];

        // s-t間の最短路に沿って目一杯流す
        int d=f;
        for(int v=t; v!=s; v=prevv[v]) d = min(d,G[prevv[v]][preve[v]].cap);
        f -= d;
        res += d*h[t];

        for(int v=t; v!=s; v=prevv[v]){
            edge &e = G[prevv[v]][preve[v]];
            e.cap -= d;
            G[v][e.rev].cap += d;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >>n;
    vector<vector<int>> W(n,vector<int>(n)),E(n,vector<int>(n));
    vector<string> F(n);

    rep(i,n)rep(j,n) cin >>W[i][j];
    rep(i,n)rep(j,n) cin >>E[i][j];
    rep(i,n) cin >>F[i];

    V = 2*n+2;
    int S = 2*n, T = S+1;
    rep(i,n)
    {
        add_edge(S,i,1,0);
        add_edge(n+i,T,1,0);
    }

    rep(i,n)rep(j,n)
    {
        int cost = 0;
        rep(k,n)
        {
            if(k==j)
            {
                if(F[i][k]!='o') cost += W[i][k];
            }
            else
            {
                if(F[i][k]!='.') cost += E[i][k];
            }
        }
        add_edge(i,n+j,1,cost);
    }

    cout << min_cost_flow(S,T,n) << endl;

    vector<int> r,c;
    vector<string> op;
    rep(i,n)
    {
        int id = 0;
        for(const auto &e:G[n+i])
        {
            if(e.cap>0) id = e.to;
        }
        rep(j,n)
        {
            if(j==i)
            {
                if(F[id][j]!='o')
                {
                    r.pb(id+1);
                    c.pb(j+1);
                    op.pb("write");
                }
            }
            else
            {
                if(F[id][j]!='.')
                {
                    r.pb(id+1);
                    c.pb(j+1);
                    op.pb("erase");
                }
            }
        }
    }

    cout << r.size() << endl;
    rep(i,r.size()) cout << r[i] << " " << c[i] << " " << op[i] << endl;
    return 0;
}
