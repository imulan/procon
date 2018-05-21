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

struct Point{
    int x,y,z;
};

Point read_p(){
    int x,y,z;
    scanf(" %d %d %d", &x, &y, &z);
    return {x,y,z};
}

using pp = pair<Point,Point>;

vector<vector<int>> G;
bool flg;
vector<int> vis;

void dfs(int x, int p){
    vis[x] = 2;
    for(int e:G[x])if(e!=p){
        if(vis[e]==2){
            flg = true;
        }
        if(vis[e]==0) dfs(e,x);
    }
    vis[x] = 1;
}

bool find_cycle(){
    flg = false;

    int n = G.size();
    vis = vector<int>(n,0);
    rep(i,n)if(vis[i]==0) dfs(i,-1);

    return flg;
}

using pi = pair<int,int>;
map<pi,int> Z[1001];
int ct = 0;

int main(){
    int k;
    scanf(" %d", &k);

    vector<pp> E(k);
    rep(i,k){
        E[i].fi = read_p();
        E[i].se = read_p();

        if(!Z[E[i].fi.z].count({E[i].fi.x,E[i].fi.y})) Z[E[i].fi.z][{E[i].fi.x,E[i].fi.y}] = ct++;
        if(!Z[E[i].se.z].count({E[i].se.x,E[i].se.y})) Z[E[i].se.z][{E[i].se.x,E[i].se.y}] = ct++;
    }

    // 3D
    G = vector<vector<int>>(ct);
    rep(i,k){
        int u = Z[E[i].fi.z][{E[i].fi.x,E[i].fi.y}];
        int v = Z[E[i].se.z][{E[i].se.x,E[i].se.y}];
        if(u!=v){
            G[u].pb(v);
            G[v].pb(u);
        }
    }

    if(find_cycle()) printf("True closed chains\n");
    else printf("No true closed chains\n");

    // 2D
    G.clear();

    vector<pi> shadow;
    rep(i,k){
        shadow.pb({E[i].fi.x,E[i].fi.y});
        shadow.pb({E[i].se.x,E[i].se.y});
    }
    sort(all(shadow));
    shadow.erase(unique(all(shadow)), shadow.end());

    int SZ = shadow.size();
    G = vector<vector<int>>(SZ);
    rep(i,k){
        int u = lower_bound(all(shadow), pi(E[i].fi.x,E[i].fi.y)) - shadow.begin();
        int v = lower_bound(all(shadow), pi(E[i].se.x,E[i].se.y)) - shadow.begin();
        if(u!=v){
            G[u].pb(v);
            G[v].pb(u);
        }
    }

    if(find_cycle()) printf("Floor closed chains\n");
    else printf("No floor closed chains\n");
    return 0;
}
