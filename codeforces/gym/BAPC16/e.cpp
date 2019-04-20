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
    int to;
    ll cost;
};

const int N = 10000;
const ll INF = LLONG_MAX/3;
vector<edge> G[N];

int main(){
    int n,m,x;
    scanf(" %d %d %d", &n, &m, &x);

    vector<int> u(m),v(m),t(m);
    rep(i,m){
        scanf(" %d %d %d", &u[i], &v[i], &t[i]);
        --u[i];
        --v[i];
    }

    auto dijkstra = [&](){
        using P = pair<ll,int>;
        priority_queue<P,vector<P>,greater<P>> pq;

        vector<ll> d(n,INF);
        d[0] = 0;
        pq.push({0,0});
        while(!pq.empty()){
            P now = pq.top();
            pq.pop();

            int cur = now.se;
            if(now.fi > d[cur]) continue;

            for(const auto &e:G[cur]){
                if(d[e.to] > d[cur]+e.cost){
                    d[e.to] = d[cur]+e.cost;
                    pq.push({d[e.to], e.to});
                }
            }
        }
        return d[n-1];
    };

    auto shortest = [&](){
        rep(i,m){
            G[u[i]].pb({v[i],t[i]});
            G[v[i]].pb({u[i],t[i]});
        }

        return dijkstra();
    };

    ll D = shortest();

    auto check = [&](int lim){
        rep(i,N) G[i].clear();
        rep(i,m){
            if(t[i]<=lim){
                G[u[i]].pb({v[i],t[i]});
                G[v[i]].pb({u[i],t[i]});
            }
        }

        ll dd = dijkstra();
        return dd <= (D*(100+x))/100;
    };

    int l=0, r=1000000000;
    while(r-l>1){
        int mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%d\n", r);
    return 0;
}
