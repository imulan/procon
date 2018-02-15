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

struct edge{int to; ll cost;};

const int N = 200000;
vector<edge> G[N];
int par[N];
int vis[N]={};

vector<int> cycle;
bool is_cycle[N]={};
void find_cycle(int x){
    int now = x;
    while(1){
        cycle.pb(now);
        is_cycle[now] = true;
        for(const auto &e:G[now]){
            if(e.to!=par[now] && vis[e.to]==2){
                now = e.to;
                break;
            }
        }
        if(now == x) break;
    }
}

void dfs(int x){
    vis[x] = 2;
    for(const auto &e:G[x])if(e.to != par[x]){
        if(vis[e.to]==0){
            par[e.to] = x;
            dfs(e.to);
        }
        else if(vis[e.to]==2) find_cycle(e.to);
    }
    vis[x] = 1;
}

using pi = pair<int,int>;
using P = pair<ll,pi>;

const ll INF = LLONG_MAX/3;

pair<ll,int> farthest(int start, int n){
    vector<ll> d(n, INF);
    d[start] = 0;
    queue<int> que;
    que.push(start);
    while(!que.empty()){
        int now = que.front();
        que.pop();
        for(const auto &e:G[now]){
            if(d[e.to] > d[now]+e.cost){
                d[e.to] = d[now]+e.cost;
                que.push(e.to);
            }
        }
    }

    ll max_d = 0;
    int idx = -1;
    rep(i,n){
        if(d[i] > max_d){
            max_d = d[i];
            idx = i;
        }
    }
    assert(max_d < INF);
    return {max_d,idx};
}

int main(){
    int n;
    cin >>n;
    vector<int> u(n),v(n),l(n);
    rep(i,n){
        cin >>u[i] >>v[i] >>l[i];
        --u[i];
        --v[i];
        if(u[i]>v[i]) swap(u[i],v[i]);
        G[u[i]].pb({v[i], l[i]});
        G[v[i]].pb({u[i], l[i]});
    }

    par[0] = -1;
    dfs(0);

    int C = cycle.size();
    vector<ll> d(C+1),w(C);
    rep(i,C){
        // calc d
        queue<P> que;
        que.push({0,{cycle[i],-1}});
        while(!que.empty()){
            P now = que.front();
            que.pop();
            d[i] = max(d[i], now.fi);
            int vv = now.se.fi, pp = now.se.se;
            for(const auto &e:G[vv])if(!is_cycle[e.to] && e.to != pp){
                que.push({now.fi+e.cost, {e.to,vv}});
            }
        }

        // calc w
        for(const auto &e:G[cycle[i]]){
            if(e.to == cycle[(i+1)%C]) w[i] = e.cost;
        }
    }

    vector<ll> pred(C+1),sufd(C+1);
    vector<ll> pref(C+1),suff(C+1);

    ll dt = -INF;
    ll sw = 0;
    pred[0] = pref[0] = d[0];
    for(int i=1; i<C; ++i){
        dt = max(dt,d[i-1]) + w[i-1];
        pred[i] = max(pred[i-1], dt+d[i]);

        sw += w[i-1];
        pref[i] = max(pref[i-1], d[i]+sw);
    }

    sufd[C] = suff[C] = -INF;
    dt = -INF;
    sw = 0;
    for(int i=C-1; i>=0; --i){
        dt = max(dt,d[i+1]) + w[i];
        sufd[i] = max(sufd[i+1], dt+d[i]);

        sw += w[i];
        suff[i] = max(suff[i+1], d[i]+sw);
    }

    int idx = 0;
    ll min_inconvenience = INF;
    rep(i,C){
        ll t_inconv = max({pref[i]+suff[i+1], pred[i], sufd[i+1]});
        if(min_inconvenience > t_inconv){
            min_inconvenience = t_inconv;
            idx = i;
        }
    }

    int del = 0;
    int ru = cycle[idx], rv = cycle[(idx+1)%C];
    if(ru>rv) swap(ru,rv);
    rep(i,N) G[i].clear();
    rep(i,n){
        if(u[i]==ru && v[i]==rv){
            ++del;
            continue;
        }
        G[u[i]].pb({v[i], l[i]});
        G[v[i]].pb({u[i], l[i]});
    }
    assert(del==1);

    int xx = farthest(0,n).se;
    cout << farthest(xx,n).fi << endl;
    return 0;
}
