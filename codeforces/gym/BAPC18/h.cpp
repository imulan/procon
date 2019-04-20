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
using P = pair<ll,pi>;

struct edge{
    int to,cost;
};

const int N = 100010;
vector<edge> G[N], rG[N];

const ll INF = LLONG_MAX/3;
ll d[N][2];

int main(){
    int n,m,s,g;
    scanf(" %d %d %d %d", &n, &m, &s, &g);

    rep(i,m){
        int a,b,w;
        scanf(" %d %d %d", &a, &b, &w);
        G[a].pb({b,w});
        rG[b].pb({a,w});
    }

    rep(i,N)rep(j,2) d[i][j] = INF;

    priority_queue<P,vector<P>,greater<P>> pq;
    rep(i,2){
        d[g][i] = 0;
        pq.push({0,{g,i}});
    }

    while(!pq.empty()){
        P now = pq.top();
        pq.pop();

        int v = now.se.fi, f = now.se.se;
        for(const auto &e:rG[v]){
            int nf = !f;
            if(nf == 0){
                ll val = 0;
                for(const auto &ee:G[e.to]){
                    val = max(val, d[ee.to][1]+ee.cost);
                }
                if(d[e.to][nf] > val){
                    d[e.to][nf] = val;
                    pq.push({d[e.to][nf], {e.to,nf}});
                }
            }
            else{
                if(d[e.to][nf] > d[v][f]+e.cost){
                    d[e.to][nf] = d[v][f]+e.cost;
                    pq.push({d[e.to][nf], {e.to,nf}});
                }
            }
        }
    }

    ll ans = d[s][0];
    if(ans == INF) printf("infinity\n");
    else printf("%lld\n", ans);
    return 0;
}
