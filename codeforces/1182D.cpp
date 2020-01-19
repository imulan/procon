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

const int INF = 19191919;

int main(){
    int n;
    scanf(" %d,", &n);

    vector<vector<int>> G(n);
    vector<int> deg(n);
    rep(i,n-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
        ++deg[u];
        ++deg[v];
    }

    vector<int> par(n,-1);
    vector<int> d(n,INF);
    auto farthest = [&](int s){
        d = vector<int>(n,INF);
        par = vector<int>(n,-1);
        d[s] = 0;
        queue<int> que({s});
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v]){
                if(d[e] > d[v]+1){
                    d[e] = d[v]+1;
                    que.push(e);
                    par[e] = v;
                }
            }
        }

        int md = 0;
        int idx = s;
        rep(i,n)if(d[i] > md){
            md = d[i];
            idx = i;
        }
        return idx;
    };

    int x = farthest(0);
    int y = farthest(x);

    vector<int> path;
    int now = y;
    while(now!=-1){
        path.pb(now);
        now = par[now];
    }

    vector<int> cand({x,y});
    rep(loop,2){
        for(int i:path)if(deg[i]>=3){
            cand.pb(i);
            break;
        }
        reverse(all(path));
    }

    if(d[y]%2==0){
        int t = y;
        while(d[t] > d[y]/2) t = par[t];
        cand.pb(t);

        int near = -1;
        vector<bool> vis(n);
        vis[t] = true;
        queue<int> qq({t});
        while(!qq.empty()){
            int v = qq.front();
            qq.pop();
            for(int e:G[v])if(!vis[e] && deg[e]<=2){
                vis[e] = true;
                qq.push(e);
                if(deg[e] == 1){
                    near = e;
                    break;
                }
            }
            if(near != -1) break;
        }
        if(near != -1) cand.pb(near);
    }

    auto check = [&](int root){
        int f = farthest(root);
        int F = d[f];

        vector<set<int>> s(F+1);
        rep(i,n) s[d[i]].insert(deg[i]);

        rep(i,F+1)if(s[i].size()>1) return false;
        return true;
    };

    int ans = -1;
    for(int r:cand)if(check(r)) ans = r+1;
    printf("%d\n", ans);
    return 0;
}
