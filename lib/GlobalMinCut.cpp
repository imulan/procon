/* GlocalMinCut*/

int V; // TODO:initialize
const int MAX_V = ; // TODO:initialize
const int G_INF = ; // TODO:initialize

vector<vector<int>> G;

// O(V^3)
int global_min_cut(){
    int ret = G_INF;
    vector<int> redV(V);
    rep(i,V) redV[i] = i;
    for(int r=V; r>1; --r){
        // calc Maximum Adjacent Order
        int u=0, v=0, cut=0;
        vector<int> w(r,0);
        rep(i,r){
            u = v;
            v = max_element(all(w)) - w.begin();
            cut = w[v];
            w[v] = -1;
            rep(nx,r)if(w[nx]>=0) w[nx] += G[redV[v]][redV[nx]];
        }
        // merge
        rep(i,r){
            G[redV[u]][redV[i]] += G[redV[v]][redV[i]];
            G[redV[i]][redV[u]] += G[redV[i]][redV[v]];
        }
        redV.erase(redV.begin()+v);
        // update
        ret = min(ret,cut);
    }
    return ret;
}


// まだ出来てない
// O(VElogV) にしたい
using P = pair<int,int>;
struct edge{ int to,cost; };

vector<edge> G[MAX_V];

int global_min_cut2(){
    int ret = G_INF;
    vector<bool> merged(V,false);

    for(int r=V; r>1; --r){
        // calc Maximum Adjacent Order
        int u=0, v=0, cut=0;
        vector<int> w(V,0);

        priority_queue<P> que;
        rep(i,V)if(!merged[i]){
            que.push(P(w[i],i));
        }
        while(!que.empty()){
            P p = que.top();
            que.pop();

            if(w[v]==-1) continue;

            u = v;
            v = p.se;
            cut = w[v];
            w[v] = -1;
            rep(i,G[v].size()){
                edge &e = G[v][i];
                if(w[e.to]>=0 && !merged[e.to]){
                    w[e.to] += e.cost;
                    que.push(P(w[e.to],e.to));
                }
            }
        }

        // merge
        vector<int> cost(V,0);
        vector<bool> found(V,false);
        rep(i,G[v].size()) cost[e.to] = e.cost;

        rep(i,G[u].size())


        merged[v] = true;

        // update
        ret = min(ret,cut);
    }
    return ret;
}
