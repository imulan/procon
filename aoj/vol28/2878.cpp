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

struct edge{
    int to,cost;
};

const int N = 100000;
vector<edge> G[N];

const ll INF = LLONG_MAX/3;

int main(){
    int n,m,s,t;
    scanf(" %d %d %d %d", &n, &m, &s, &t);
    --s;
    --t;
    rep(i,m){
        int v[3];
        rep(j,3){
            scanf(" %d", &v[j]);
            --v[j];
        }

        int d;
        scanf(" %d", &d);

        rep(j,3){
            int x = v[j], y = v[(j+1)%3];
            G[x].pb({y,d});
            G[y].pb({x,d});
        }
    }

    using P = pair<ll,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<ll> d(n,INF);
    pq.push({0,s});
    d[s] = 0;
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();
        int v = now.se;
        if(now.fi>d[v]) continue;
        for(const auto &e:G[v]){
            if(d[e.to] > d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                pq.push({d[e.to], e.to});
            }
        }
    }

    printf("%lld\n", d[t]);
    return 0;
}
