/* MinCostFlow */

using pi = pair<int,int>;

// (行き先, 容量, コスト, 逆辺)
struct edge{ int to,cap,cost,rev; };

int V; // TODO:initialize
const int MAX_V = ; // TODO:initialize
const int INF = ; // TODO:initialize
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
        if(neg){
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
        else{
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

// 辺に最小流量制約がある場合
// e(u->v)に対して、最大流量c、最小流量b、コストdのとき
// e'(u->v)を用意して、
// e:{cap:c-b, cost:d} / e':{cap:b, cost:d-M(十分に大きい数)}
// としてからMCFを求め、それに M*Σb を足せば良い (d-Mが負になるかもしれないので注意)

// グラフに負のコストの辺がある場合
// ・ベルマンフォードを使う

// ・使われる辺の個数が等しいとき：
// それらのコストに適当なkを足して非負にしておき、あとでそれらを引く

// ・流す流量Fが一定であるとき：
// e(u->v): cap:c, cost:-dの辺に対して、

// 旧source(s),sink(t)
// 新しいsource(S),sink(T)を作成
// 辺の張り方
// v->u:{cap:c, cost:d} / u->T:{cap:c, cost:0} / S->v:{cap:c, cost:0}
// S->s:{cap:F, cost:0} / t->T:{cap:F, cost:0}

// このグラフに対して、
// min_cost_flow(S,T,F+Σc(コスト負の辺)) + Σc*(-d)
// がもとのグラフに対する最小費用流になる
