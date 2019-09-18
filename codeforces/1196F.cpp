#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

using P = pair<ll,int>;

struct edge{
    int to;
    ll cost;
};

const int N = 200000;
const ll INF = LLONG_MAX/3;
vector<edge> G[N];


int main(){
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);
    rep(i,m){
        int u,v,w;
        scanf(" %d %d %d", &u, &v, &w);
        --u;
        --v;
        G[u].pb({v,w});
        G[v].pb({u,w});
    }

    auto check = [&](ll x){
        int ct = 0;
        vector<ll> d(n,INF);

        rep(i,n){
            d[i] = 0;

            vector<int> upd;
            priority_queue<P, vector<P>, greater<P>> pq;
            upd.pb(i);
            pq.push({0,i});

            while(!pq.empty()){
                P now = pq.top();
                pq.pop();

                int v = now.se;
                if(now.fi > d[v]) continue;

                if(d[v]<=x && i<v){
                    ++ct;
                    if(ct>=k) return false;
                }

                for(const auto &e:G[v]){
                    if(d[e.to] > d[v]+e.cost && d[v]+e.cost<=x){
                        d[e.to] = d[v]+e.cost;
                        upd.pb(e.to);
                        pq.push({d[e.to], e.to});
                    }
                }
            }

            for(int j:upd) d[j] = INF;
        }
        return true;
    };

    ll ok=0, ng=INF;
    while(ng-ok>1){
        ll mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    printf("%lld\n", ok+1);
    return 0;
}
