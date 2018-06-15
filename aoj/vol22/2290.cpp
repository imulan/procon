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
using P = pair<int,pi>;

// (行き先, 容量, コスト, 逆辺)
struct edge{ int to,cap,cost,rev; };

int V; // TODO:initialize
const int MAX_V = 6006; // TODO:initialize
const ll INF = LLONG_MAX/10; // TODO:initialize
vector<edge> G[MAX_V];
ll h[MAX_V]; // ポテンシャル
ll dist[MAX_V];
int prevv[MAX_V], preve[MAX_V]; // 直前の頂点と辺

bool used[MAX_V];

void add_edge(int from, int to, int cap, int cost){
    G[from].pb({to,cap,cost,(int)G[to].size()});
    G[to].pb({from,0,-cost,(int)G[from].size()-1});
}

// sからtへの流量fの最小費用流(不可能なら-1)
ll min_cost_flow(int s, int t, int f, bool neg = false){
    ll res = 0;
    fill(h,h+V,0);
    while(f>0){
        // dbg(f);
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
                        if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                            dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            // dbg(v);
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

            // fill(used,used+V,false);
            // while(1){
            //     int v=-1;
            //     rep(i,V){
            //         if(!used[i] && (v==-1 || dist[i]<dist[v])) v=i;
            //     }
            //     if(v==-1) break;

            //     rep(i,G[v].size()){
            //         edge &e = G[v][i];
            //         if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
            //             dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];
            //             prevv[e.to] = v;
            //             preve[e.to] = i;
            //         }
            //     }
            // }
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

int main(){
    int n,v,xl,xr;
    cin >>n >>v >>xl >>xr;

    vector<P> m(n);
    rep(i,n){
        int x,t,p;
        cin >>x >>t >>p;
        m[i] = {t,{x,p}};
    }
    sort(all(m));

    int S=0, L=1, R=2;
    int T = 2*n+3;
    V = 2*n+4;

    add_edge(S,L,1,0);
    add_edge(S,R,1,0);
    add_edge(L,T,1,0);
    add_edge(R,T,1,0);

    auto reach = [&](int from, int to, ll dt){
        if(dt<0) return false;
        int dx = abs(from-to);
        return dt*v >= dx;
    };

    rep(i,n){
        int t = m[i].fi, x = m[i].se.fi, p = m[i].se.se;

        add_edge(3+2*i,3+2*i+1,1,-p);
        add_edge(3+2*i+1,T,1,0);
        if(reach(xl,x,t)) add_edge(L,3+2*i,1,0);
        if(reach(xr,x,t)) add_edge(R,3+2*i,1,0);

        for(int j=i+1; j<n; ++j){
            int jt = m[j].fi, jx = m[j].se.fi;
            if(reach(x,jx,jt-t)){
                add_edge(3+2*i+1,3+2*j,1,0);
            }
        }
    }

    cout << -min_cost_flow(S,T,2,true) << endl;
    return 0;
}
