#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)n;(i)++)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) (x).begin(),(x).end()
#define uniq(x) sort(all(x)),(x).erase(unique(all(x)),end(x))
#define dbg(x) cout<<#x" = "<<((x))<<endl
#define fi first
#define se second

const long INF = 1234567890;

template<typename T>
class MinCostFlow{
public:
    struct edge{int to; T cap,cost; int rev;};
    using P =pair<T,int>;
    vector<vector<edge>> G;
    vector<int> prevv, preve;
    vector<T> h, d;
    MinCostFlow(int v){
        G.resize(v);
        prevv.resize(v);
        preve.resize(v);
        h.resize(v);
        d.resize(v);
    }
    T min_cost_flow(int s, int t, T f){
        T res = 0;
        fill(all(h), 0);
        bool neg = false;
        rep(v,G.size()){
            rep(j,G[v].size()){
                edge &e = G[v][j];
                if(e.cap == 0) continue;
                int u = e.to;
                h[u] = min(h[u], h[v]+e.cost);
            }
        }

        while(f>0){
            fill(all(d), INF);
            d[s]=0;
            if(neg){
                neg = false;
                bool update;
                do {
                    update = false;
                    rep(v,(int)G.size())
                    {
                        if(d[v]==INF) continue;
                        rep(i,G[v].size())
                        {
                            edge &e = G[v][i];
                            if(e.cap>0 && d[e.to]>d[v]+e.cost)
                            {
                                d[e.to] = d[v]+e.cost;
                                prevv[e.to] = v;
                                preve[e.to] = i;
                                update = true;
                            }
                        }
                    }
                } while(update);
            }
            else {
                priority_queue<P, vector<P>, greater<P>> pq;
                pq.push(mp(0,s));
                while(!pq.empty()){
                    auto p = pq.top(); pq.pop();
                    int v = p.se;
                    if(d[v]<p.fi) continue;
                    rep(i,G[v].size()){
                        auto &e = G[v][i];
                        if(e.cap > 0 && d[e.to] > d[v] + e.cost + h[v] - h[e.to]){
                            d[e.to] = d[v] + e.cost + h[v] - h[e.to];
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            pq.push(mp(d[e.to], e.to));
                        }
                    }
                }
            }
            if(d[t] == INF) return -1;
            rep(i,G.size()) h[i] += d[i];

            T nf = f;
            for(int v=t; v!=s; v = prevv[v]){
                nf = min(nf, G[prevv[v]][preve[v]].cap);
            }
            f -= nf;
            res += nf*h[t];
            for(int v=t; v!=s; v = prevv[v]){
                auto &e = G[prevv[v]][preve[v]];
                e.cap -= nf;
                G[v][e.rev].cap += nf;
            }
        }
        return res;
    }
    void add_edge(int from, int to, T cap, T cost){
        // printf(" %d -> %d %d %d\n", from,to,cap,cost);
        G[from].pb(((edge){to, cap, cost, (int)G[to].size()}));
        G[to].pb(((edge){from, 0, -cost, (int)G[from].size()-1}));
    }
};

int n,m;

inline bool in(int y, int x)
{
    return 0<=y && y<n && 0<=x && x<m;
}

inline int ID(int y, int x)
{
    return m*y+x;
}

const long M = 1000;
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

int main(){
    while(cin >>n >>m,n)
    {
        vector<string> c(n);
        rep(i,n) cin >>c[i];

        MinCostFlow<long> flow(2*n*m+2);
        int S = 2*n*m, T = S+1;

        rep(i,n)rep(j,m)
        {
            if(c[i][j]=='#') continue;

            int cost = 0;
            if(i==n-1 && j==0) cost = -M;
            if(i==0 && j==m-1) cost = -M;

            if(cost == 0)
            {
                flow.add_edge(2*ID(i,j), 2*ID(i,j)+1, 1, cost);
            }
            else
            {
                flow.add_edge(2*ID(i,j)+1, 2*ID(i,j), 1, -cost);
                flow.add_edge(S,2*ID(i,j)+1, 1, 0);
                flow.add_edge(2*ID(i,j), T, 1, 0);
            }

            rep(d,4)
            {
                int ny = i+dy[d], nx = j+dx[d];
                if(in(ny,nx) && c[ny][nx]!='#')
                {
                    flow.add_edge(2*ID(i,j)+1, 2*ID(ny,nx), 1, 0);
                }
            }
        }

        flow.add_edge(S, 2*ID(0,0)+1, 2, 0);
        flow.add_edge(2*ID(n-1,m-1), T, 2, 0);

        long F = flow.min_cost_flow(S, T, 4);
        // dbg(F);

        string ans = "NO";
        if(F-2*M == -2*M) ans = "YES";
        cout << ans << endl;
    }
    return 0;
}
