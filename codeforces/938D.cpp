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

using P = pair<ll,int>;

struct edge{ int to; ll cost; };

const int N = 200000;
vector<edge> G[N];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
    rep(i,m){
        int u,v;
        ll w;
        scanf(" %d %d %lld", &u, &v, &w);
        --u;
        --v;
        G[u].pb({v,w});
        G[v].pb({u,w});
    }

    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> d(n);

    rep(i,n){
        scanf(" %lld", &d[i]);
        pq.push({d[i],i});
    }

    while(!pq.empty()){
        P now = pq.top();
        pq.pop();

        int v = now.se;
        if(now.fi > d[v]) continue;

        for(const auto &e:G[v]){
            if(d[e.to] > d[v]+2*e.cost){
                d[e.to] = d[v]+2*e.cost;
                pq.push({d[e.to],e.to});
            }
        }
    }

    rep(i,n) printf("%lld%c", d[i], " \n"[i==n-1]);
    return 0;
}
