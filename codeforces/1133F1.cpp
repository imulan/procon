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

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<vector<int>> G(n);
    vector<int> deg(n);
    rep(i,m){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
        ++deg[u];
        ++deg[v];
    }

    int root = 0;
    rep(i,n)if(deg[i] > deg[root]) root = i;

    vector<bool> vis(n);
    vector<pi> e;
    vis[root] = true;
    queue<int> que({root});
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int x:G[v])if(!vis[x]){
            vis[x] = true;
            que.push(x);
            e.pb({v,x});
        }
    }

    for(pi p:e) printf("%d %d\n", p.fi+1, p.se+1);
    return 0;
}
