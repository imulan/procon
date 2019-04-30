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

vector<vector<int>> G;

map<vector<int>,int> h2id;
int tree_hash(int v, int par){
    vector<int> hs;
    for(int ch:G[v])if(ch!=par){
        hs.pb(tree_hash(ch,v));
    }
    sort(all(hs));

    if(!h2id.count(hs)) h2id[hs] = h2id.size();
    return h2id[hs];
}

// const int INF = 10101010;
vector<int> find_g(int start){
    unordered_map<int,int> d0;
    d0[start] = 0;
    queue<int> que({start});
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:G[v]){
            if(!d0.count(e)){
                d0[e] = d0[v] + 1;
                que.push(e);
            }
        }
    }

    int md = -1;
    int farthest_x = -1;
    for(const auto &p:d0){
        if(md < p.se){
            md = p.se;
            farthest_x = p.fi;
        }
    }
    assert(farthest_x != -1);

    unordered_map<int,int> par,d;
    d[farthest_x] = 0;
    par[farthest_x] = -1;
    que.push(farthest_x);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int e:G[v]){
            if(!d.count(e)){
                d[e] = d[v] + 1;
                par[e] = v;
                que.push(e);
            }
        }
    }

    md = -1;
    int farthest_y = -1;
    for(const auto &p:d){
        if(md < p.se){
            md = p.se;
            farthest_y = p.fi;
        }
    }
    assert(farthest_y != -1);

    vector<int> path;
    int now = farthest_y;
    while(now != -1){
        path.pb(now);
        now = par[now];
    }

    int P = path.size();
    vector<int> ret;
    if(P%2 == 0) ret.pb(path[P/2-1]);
    ret.pb(path[P/2]);
    return ret;
}

int main(){
    int n1,m1;
    scanf(" %d %d", &n1, &m1);

    vector<vector<int>> G1(n1);
    rep(i,m1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G1[u].pb(v);
        G1[v].pb(u);
    }

    int n2;
    scanf(" %d", &n2);

    vector<vector<int>> G2(n2);
    rep(i,n2-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G2[u].pb(v);
        G2[v].pb(u);
    }

    G = G2;
    vector<int> g2_hash;
    for(int i:find_g(0)) g2_hash.pb(tree_hash(i,-1));

    G = G1;
    int ans = 0;
    vector<bool> vis(n1);
    rep(i,n1)if(!vis[i]){
        vis[i] = true;
        queue<int> que({i});
        while(!que.empty()){
            int v = que.front();
            que.pop();
            for(int e:G[v])if(!vis[e]){
                vis[e] = true;
                que.push(e);
            }
        }

        int add = 0;
        for(int j:find_g(i)){
            int h1 = tree_hash(j,-1);
            for(int h2:g2_hash)if(h1 == h2) add = 1;
        }
        ans += add;
    }
    printf("%d\n", ans);
    return 0;
}
