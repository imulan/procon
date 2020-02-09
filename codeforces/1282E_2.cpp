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

using pi = pair<int,int>;

void solve(){
    int n;
    scanf(" %d", &n);

    map<pi,vector<int>> edge;
    vector<vector<int>> tri(n-2);
    rep(i,n-2){
        vector<int> t(3);
        rep(j,3){
            scanf(" %d", &t[j]);
            --t[j];
        }

        rep(j,3){
            int u = t[j], v = t[(j+1)%3];
            if(u>v) swap(u,v);
            edge[{u,v}].pb(i);
        }

        tri[i] = t;
    }

    vector<vector<int>> G(n);
    for(const auto &p:edge){
        if(p.se.size() == 2){
            int u = p.se[0], v = p.se[1];
            G[u].pb(v);
            G[v].pb(u);
        }
    }

    vector<int> d(n-2,n);
    d[0] = 0;
    queue<int> que({0});
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:G[v]){
            if(d[e] > d[v]+1){
                d[e] = d[v]+1;
                que.push(e);
            }
        }
    }

    vector<pi> qq(n-2);
    rep(i,n-2) qq[i] = {d[i], i};
    sort(all(qq), greater<pi>());

    vector<int> q(n-2);
    rep(i,n-2) q[i] = qq[i].se;

    vector<bool> used(n);
    vector<set<int>> nxt(n);
    vector<int> start = tri[q[n-3]];
    rep(i,3){
        used[start[i]] = true;
        rep(j,3)if(i!=j) nxt[start[i]].insert(start[j]);
    }

    for(int i=n-4; i>=0; --i){
        vector<int> t = tri[q[i]];

        int idx = -1;
        rep(j,3)if(!used[t[j]]) idx = j;
        assert(idx != -1);

        int v = t[idx];
        used[v] = true;

        vector<int> o;
        rep(j,3)if(j!=idx) o.pb(t[j]);

        rep(j,2){
            nxt[v].insert(o[j]);
            nxt[o[j]].insert(v);
            nxt[o[j]].erase(o[!j]);
        }
    }

    int pre = -1;
    int now = 0;
    vector<int> p(n);
    rep(i,n){
        p[i] = now;
        for(int j:nxt[now])if(pre != j){
            pre = now;
            now = j;
            break;
        }
    }

    rep(i,n) printf("%d%c", p[i]+1, " \n"[i==n-1]);
    rep(i,n-2) printf("%d%c", q[i]+1, " \n"[i==n-3]);
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
