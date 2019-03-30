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

pi ee(int x, int y){
    return {min(x,y), max(x,y)};
}

int main(){
    int n,k;
    scanf(" %d %d", &n, &k);

    vector<vector<int>> G(n);
    vector<int> deg(n);
    vector<pi> e(n-1);
    rep(i,n-1){
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        if(x > y) swap(x,y);

        e[i] = {x,y};
        ++deg[x];
        ++deg[y];
        G[x].pb(y);
        G[y].pb(x);
    }

    vector<pi> v(n);
    rep(i,n) v[i] = {deg[i],i};
    sort(all(v));
    reverse(all(v));

    vector<int> idx(n);
    rep(i,n) idx[v[i].se] = i;

    // dbg(v);
    int ans = v[k].fi;
    map<pi,int> c;

    vector<bool> vis(n);
    for(int i=k; i<n; ++i){
        if(vis[v[i].se]) continue;

        vis[v[i].se] = true;
        queue<int> que({v[i].se});
        while(!que.empty()){
            int now = que.front();
            // dbg(now);
            que.pop();

            set<int> used;
            for(int nx:G[now]){
                if(c.count(ee(now,nx))) used.insert(c[ee(now,nx)]);
            }

            int cidx = 0;
            for(int nx:G[now]){
                if(!c.count(ee(now,nx))){
                    while(used.count(cidx)) ++cidx;
                    c[ee(now,nx)] = cidx;
                    used.insert(cidx);
                }

                if(!vis[nx] && idx[nx]>=k){
                    vis[nx] = true;
                    que.push(nx);
                }
            }
        }
    }

    int ct = 0;
    rep(i,n){
        int add = 0;
        set<int> used;

        for(int nx:G[i]){
            int col = c[ee(i,nx)];
            if(used.count(col)) add = 1;
            used.insert(col);
        }
        ct += add;
    }
    assert(ct<=k);

    cout << ans << '\n';
    rep(i,n-1){
        int col = 0;
        if(c.count(e[i])) col = c[e[i]];
        cout << col+1 << " \n"[i==n-2];
    }
    return 0;
}
