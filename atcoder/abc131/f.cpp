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

const int N = 100010;
vector<pi> X[N],Y[N];

vector<int> G[N];

int main(){
    int n;
    cin >>n;

    vector<pi> p(n);
    rep(i,n){
        int x,y;
        cin >>x >>y;
        X[x].pb({y,i});
        Y[y].pb({x,i});

        p[i] = {x,y};
    }

    rep(i,N){
        int sz;

        sort(all(X[i]));
        sz = X[i].size();
        rep(j,sz-1){
            int u = X[i][j].se, v = X[i][j+1].se;
            G[u].pb(v);
            G[v].pb(u);
        }

        sort(all(Y[i]));
        sz = Y[i].size();
        rep(j,sz-1){
            int u = Y[i][j].se, v = Y[i][j+1].se;
            G[u].pb(v);
            G[v].pb(u);
        }
    }

    ll ans = 0;
    vector<bool> vis(n);
    rep(i,n)if(!vis[i]){
        vis[i] = true;
        queue<int> que({i});
        vector<int> cc({i});
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v])if(!vis[e]){
                que.push(e);
                vis[e] = true;
                cc.pb(e);
            }
        }

        set<int> ux,uy;
        for(int idx:cc){
            ux.insert(p[idx].fi);
            uy.insert(p[idx].se);
        }

        ll sx = ux.size(), sy = uy.size();
        int C = cc.size();
        ans += sx*sy - C;
    }

    cout << ans << "\n";
    return 0;
}
