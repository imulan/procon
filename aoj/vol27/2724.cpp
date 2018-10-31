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

// (行き先, 容量, コスト, 逆辺)
struct edge{
    int to,cap;
    double cost;
    int rev;
};

int V; // TODO:initialize
const int MAX_V = 666; // TODO:initialize
const double INF = 19191919; // TODO:initialize
vector<edge> G[MAX_V];
double h[MAX_V]; // ポテンシャル
double dist[MAX_V];
int prevv[MAX_V], preve[MAX_V]; // 直前の頂点と辺

void add_edge(int from, int to, int cap, double cost){
    G[from].pb({to,cap,cost,(int)G[to].size()});
    G[to].pb({from,0,-cost,(int)G[from].size()-1});
}

const double EPS = 1e-7;

// sからtへの流量fの最小費用流(不可能なら-1)
double min_cost_flow(int s, int t, int f){
    using pd = pair<double,int>;

    double res = 0;
    fill(h,h+V,0);
    while(f>0){
        priority_queue<pd,vector<pd>,greater<pd>> pq;
        fill(dist,dist+V,INF);
        dist[s]=0;
        // dijkstraでhを更新
        pq.push(pd(0,s));
        while(!pq.empty()){
            pd p = pq.top();
            pq.pop();
            int v = p.se;
            if(p.fi>dist[v]) continue;
            rep(i,G[v].size()){
                edge &e = G[v][i];
                if(e.cap>0 && dist[e.to]>dist[v]+e.cost+h[v]-h[e.to] + EPS){
                    dist[e.to] = dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    pq.push(pd(dist[e.to],e.to));
                }
            }
        }

        // これ以上流せない
        if( abs(dist[t]-INF) < EPS) return -1;

        rep(v,V) h[v] += dist[v];

        // s-t間の最短路に沿って目一杯流す
        int d=f;
        for(int v=t; v!=s; v=prevv[v]){
            // dbg(v);
            d = min(d,G[prevv[v]][preve[v]].cap);
        }
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

using pi = pair<int,int>;

#define x first
#define y second

pi READ(){
    int x,y;
    cin >>x >>y;
    return {x,y};
}

double calc(pi p, pi q){
    double dx = p.x-q.x;
    double dy = p.y-q.y;
    return sqrt(dx*dx + dy*dy);
}

int main(){
    int n;
    cin >>n;

    pi start = READ();

    vector<pi> s(n),t(n);
    rep(i,n){
        s[i] = READ();
        t[i] = READ();
    }

    double ans = 0;
    rep(i,n) ans += calc(s[i], t[i]);

    set<pi> pts;
    map<pi,int> indeg,outdeg;
    rep(i,n){
        ++indeg[t[i]];
        ++outdeg[s[i]];
        pts.insert(s[i]);
        pts.insert(t[i]);
    }

    vector<pi> aa,bb;
    for(pi p:pts){
        int d = indeg[p] - outdeg[p];
        if(d==0) continue;

        if(d>0) aa.pb(p);
        else bb.pb(p);
    }
    sort(all(aa));
    aa.erase(unique(all(aa)), aa.end());
    sort(all(bb));
    bb.erase(unique(all(bb)), bb.end());

    int A = aa.size(), B = bb.size();
    int S = A+B, T = S+1;
    V = A+B+2;
    int f = 0;
    for(pi p:pts){
        int d = indeg[p] - outdeg[p];
        if(d==0) continue;

        if(d>0){
            int idx = lower_bound(all(aa), p) - aa.begin();
            add_edge(S,idx,d,0);
            f += d;
        }
        else{
            int idx = lower_bound(all(bb), p) - bb.begin();
            add_edge(A+idx,T,-d,0);
        }
    }
    rep(i,A)rep(j,B){
        add_edge(i,A+j,f,calc(aa[i],bb[j]));
    }

    ans += min_cost_flow(S,T,f);
    printf("%.15f\n", ans);
    return 0;
}
