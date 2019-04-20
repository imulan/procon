#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl;

const int INF = 19191919;

vector<int> bfs(int s, const vector<vector<int>> g){
    int n = g.size();
    vector<int> d(n,INF);
    d[s] = 0;
    queue<int> que;
    que.push(s);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:g[v]){
            if(d[e] > d[v]+1){
                d[e] = d[v]+1;
                que.push(e);
            }
        }
    }
    return d;
}

int main(){
    int n,m,a,b;
    scanf(" %d %d %d %d", &n, &m, &a, &b);

    vector<vector<int>> G(n+1),rG(n+1);
    rep(i,m){
        int u,v;
        scanf(" %d %d", &u, &v);
        G[u].pb(v);
        rG[v].pb(u);
    }

    vector<int> ds = bfs(0,G), da = bfs(a,rG), db = bfs(b,rG);
    int ans = INF;
    rep(i,n+1){
        ans = min(ans, ds[i]+da[i]+db[i]);
    }
    printf("%d\n",ans);
    return 0;
}