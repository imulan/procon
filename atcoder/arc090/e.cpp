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

const ll mod = 1e9+7;

struct edge{
    int to;
    ll cost;
};

const int N = 100000;
vector<edge> G[N];

const ll INF = LLONG_MAX/3;

vector<ll> dijk(int start, int n){
    vector<ll> d(n,INF);
    d[start] = 0;

    using P = pair<ll,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();
        int v = now.se;
        if(now.fi > d[v]) continue;
        for(const auto &e:G[v]){
            if(d[e.to] > d[v]+e.cost){
                d[e.to] = d[v]+e.cost;
                pq.push({d[e.to], e.to});
            }
        }
    }
    return d;
}

vector<ll> pat(int start, int n, const vector<ll> &dd){
    vector<ll> ret(n);
    ret[start] = 1;

    using P = pair<ll,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    vector<bool> vis(n);
    pq.push({0,start});
    while(!pq.empty()){
        P now = pq.top();
        pq.pop();
        int v = now.se;
        if(vis[v]) continue;

        for(const auto &e:G[v]){
            if(dd[e.to] == dd[v]+e.cost){
                (ret[e.to] += ret[v]) %= mod;
                pq.push({dd[e.to], e.to});
            }
        }
        vis[v] = true;
    }
    return ret;
}

int main(){
    int n,m,s,t;
    cin >>n >>m >>s >>t;
    --s;
    --t;

    vector<int> u(m),v(m);
    vector<ll> d(m);
    rep(i,m){
        cin >>u[i] >>v[i] >>d[i];
        --u[i];
        --v[i];
        G[u[i]].pb({v[i],d[i]});
        G[v[i]].pb({u[i],d[i]});
    }

    vector<ll> ds = dijk(s,n), dt = dijk(t,n);
    ll D = ds[t];

    vector<bool> ok(n);
    rep(i,n) ok[i] = (ds[i]+dt[i] == D);

    vector<ll> ps = pat(s,n,ds), pt = pat(t,n,dt);

    ll ans = (ps[t]*ps[t])%mod;
    rep(i,m){
        int a = u[i], b = v[i];
        if(!ok[a] || !ok[b]) continue;
        if(ds[a]>dt[a] && ds[b]<dt[b]) swap(a,b);

        if(ds[a]<dt[a] && ds[b]>dt[b] && ds[a]+d[i]==ds[b]){
            ll sub = (ps[a]*pt[b])%mod;
            sub = (sub*sub)%mod;
            ans = (ans-sub+mod)%mod;
        }
    }
    rep(i,n)if(ok[i] && ds[i]==dt[i]){
        ll sub = (ps[i]*pt[i])%mod;
        sub = (sub*sub)%mod;
        ans = (ans-sub+mod)%mod;
    }
    cout << ans << endl;
    return 0;
}
