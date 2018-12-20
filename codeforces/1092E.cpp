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

const int N = 1010;
vector<int> G[N];

const int INF = 19191919;

vector<int> BFS(int s, vector<int> &par){
    par = vector<int>(N,-1);
    vector<int> d(N,INF);
    queue<int> que;

    d[s] = 0;
    que.push(s);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:G[v]){
            if(d[e] > d[v]+1){
                par[e] = v;
                d[e] = d[v]+1;
                que.push(e);
            }
        }
    }
    return d;
}

pi find_cent(const vector<int> &cc){
    int s = cc[0];
    vector<int> par;

    vector<int> ds = BFS(s,par);

    int x = -1;
    int md = -1;
    for(int v:cc){
        if(ds[v] > md){
            md = ds[v];
            x = v;
        }
    }

    vector<int> dx = BFS(x,par);

    int y = -1;
    md = -1;
    for(int v:cc){
        if(dx[v] > md){
            md = dx[v];
            y = v;
        }
    }

    int now = y;
    vector<int> path;
    while(now != -1){
        path.pb(now);
        now = par[now];
    }
    // printf(" x -- y %d %d\n",x,y);
    // dbg(path);

    int P = path.size();
    return {P,path[P/2]};
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,m){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<pi> cc;
    vector<bool> vis(n);
    rep(i,n){
        if(vis[i]) continue;
        vis[i] = true;
        queue<int> que;
        que.push(i);
        vector<int> t;
        t.pb(i);
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v]){
                if(!vis[e]){
                    vis[e] = true;
                    que.push(e);
                    t.pb(e);
                }
            }
        }

        cc.pb(find_cent(t));
    }
    sort(all(cc), greater<pi>());
    int C = cc.size();

    vector<pi> ans;
    for(int i=1; i<C; ++i){
        int u = cc[0].se;
        int v = cc[i].se;
        ans.pb({u+1,v+1});
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<int> a(n);
    rep(i,n) a[i] = i;
    pi res = find_cent(a);

    printf("%d\n", res.fi - 1);
    for(pi p:ans) printf("%d %d\n", p.fi, p.se);
    return 0;
}
