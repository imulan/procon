#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);i++)
#define mp(a,b) make_pair((a),(b))
#define pb(a) push_back((a))
#define all(x) begin(x),end(x)
#define uniq(x) sort(all(x)),(x).erase(unique(all(s)),end(x))
#define dbg(x) cout<<#x" = "<<((x))<<endl
#define fi first
#define se second

using ll = long long;

using pi = pair<ll,int>;
struct edge{int to,cap; ll cost; int rev;};

int V;
const int MAX_V = 210;
const ll INF = 19191919191919LL;
vector<edge> G[MAX_V];
ll h[MAX_V];
ll dist[MAX_V];
int prevv[MAX_V], preve[MAX_V];

void add_edge(int from, int to, int cap, ll cost){
    // printf(" %d -> %d, cap \n", from,to);
    G[from].push_back({to,cap,cost,(int)G[to].size()});
    G[to].push_back({from,0,-cost,(int)G[from].size()-1});
}

// ll min_cost_flow(int s, int t, int f, bool neg=false){
//     ll res = 0;
//     fill(h,h+V,0);
//
//     if(neg) printf("!!!NEEG\n");
//
//     while(f>0){
//         printf(" f %d\n", f);
//         priority_queue<pi,vector<pi>,greater<pi>> pq;
//         fill(dist,dist+V,INF);
//         dist[s]=0;
//
//         if(neg)
//         {
//             neg = false;
//             rep(v,V){
//                 if(dist[v] == INF) continue;
//                 rep(i,G[v].size()){
//                     edge &e = G[v][i];
//                     if(e.cap>0 && dist[e.to]>dist[v]+e.cost){
//                         dist[e.to] = dist[v]+e.cost;
//                         prevv[e.to] = v;
//                         preve[e.to] = i;
//                         // update = true;
//                         printf("UP %d\n", e.to);
//                     }
//                 }
//             }
//         }
//         else
//         {
//             // dijkstra
//             pq.push(pi(0,s));
//             while(!pq.empty()){
//                 pi p = pq.top(); pq.pop();
//                 int v = p.se;
//                 if(p.fi>dist[v]) continue;
//
//                 rep(i,G[v].size())
//                 {
//                     edge &e = G[v][i];
//                     if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
//                         dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];
//                         prevv[e.to] = v;
//                         preve[e.to] = i;
//                         pq.push(pi(dist[e.to],e.to));
//                     }
//                 }
//             }
//         }
//         if(dist[t]==INF) return -1;
//
//         rep(v,V) h[v] += dist[v];
//
//         int d=f;
//         for(int v=t; v!=s; v=prevv[v]) d = min(d,G[prevv[v]][preve[v]].cap);
//         f -= d;
//         res += d*h[t];
//
//         for(int v=t; v!=s; v=prevv[v]){
//             edge &e = G[prevv[v]][preve[v]];
//             e.cap -=d;
//             G[v][e.rev].cap +=d;
//         }
//     }
//     return res;
// }

// sからtへの流量fの最小費用流(不可能なら-1)
ll min_cost_flow(int s, int t, int f, bool neg = false){
    ll res = 0;
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


using vi = vector<int>;

const ll M =1234567890LL;

int main()
{
    int n;
    while(cin >>n,n)
    {
        rep(i,MAX_V) G[i].clear();

        V = 2*n+2;
        int S = 2*n, T = S+1;

        vector<vi> c(n);
        rep(i,n)
        {
            vi t(3);
            rep(j,3) cin >>t[j];
            sort(all(t));
            c[i] = t;
        }

        // rep(i,n)
        // {
        //     rep(j,3) printf(" %d", c[i][j]);
        //     printf("\n");
        // }

        rep(i,n)
        {
            add_edge(S, 2*i, 1, c[i][0]*c[i][1]*c[i][2]);
            add_edge(2*i, 2*i+1, 1, -M);
            add_edge(2*i, T, 1, 0);
            add_edge(2*i+1, T, 1, 0);
        }

        rep(i,n)rep(j,n)
        {
            if(i==j) continue;
            bool ok = true;
            rep(k,3) if(c[i][k]>=c[j][k]) ok=false;

            if(ok)
            {
                // printf(" %d -> %d\n", i,j);
                add_edge(2*i+1, 2*j, 1, -c[i][0]*c[i][1]*c[i][2]);
            }
        }

        cout << min_cost_flow(S,T,n,true)+M*n << endl;
    }
    return 0;
}
