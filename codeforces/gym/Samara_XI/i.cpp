#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int ask(int x, int y){
    printf("? %d %d\n", x+1, y+1);
    fflush(stdout);
    int a;
    scanf(" %d", &a);
    return a;
}

void ans(vector<int> p){
    printf("!");
    rep(i,p.size()) printf(" %d", p[i]+1);
    printf("\n");
    fflush(stdout);
}

int n;
int h;
vector<int> par;
void dfs(vector<int> v, vector<int> leaf, int p, int dep){
    if(v.size()==1){
        int root = v[0];
        par[root] = p;
        return;
    }

    int V = v.size(), L = leaf.size();
    int x = leaf[0];

    vector<int> dx(n);
    rep(i,V)if(x != v[i]) dx[v[i]] = ask(x,v[i]);

    int y = -1;
    for(int i=1; i<L; ++i){
        if(dx[leaf[i]] == 2*(h-1-dep)) y = leaf[i];
    }

    vector<int> dy(n);
    rep(i,V)if(y != v[i]) dy[v[i]] = ask(y,v[i]);

    int root = -1;
    rep(i,V){
        if(dx[v[i]]==h-1-dep && dy[v[i]]==h-1-dep) root = v[i];
    }
    par[root] = p;

    vector<int> v_l, v_r;
    vector<int> leaf_l,leaf_r;
    rep(i,V)if(v[i]!=root){
        if(dx[v[i]] > dy[v[i]]) v_r.pb(v[i]);
        else v_l.pb(v[i]);
    }
    rep(i,L){
        if(dx[leaf[i]] > dy[leaf[i]]) leaf_r.pb(leaf[i]);
        else leaf_l.pb(leaf[i]);
    }

    dfs(v_l, leaf_l, root, dep+1);
    dfs(v_r, leaf_r, root, dep+1);
}

int main(){
    scanf(" %d", &n);

    par = vector<int>(n,-1);
    if(n==1){
        ans(par);
        return 0;
    }

    h = __builtin_popcount(n);

//    find x
    int md = 0, x = -1;
    for(int i=1; i<n; ++i){
        int d = ask(0,i);
        if(d > md){
            md = d;
            x = i;
        }
    }

//    find y
    vector<int> dx(n),dy(n);
    md = 0;
    int y = -1;
    rep(i,n)if(i!=x){
        int d = ask(x,i);
        dx[i] = d;

        if(d > md){
            md = d;
            y = i;
        }
    }

//    x-y is diameter
    rep(i,n) if(i!=y) dy[i] = ask(y,i);

//    find root
    int root = -1;
    rep(i,n)if(dx[i]==h-1 && dy[i]==h-1) root = i;

    vector<int> vx,vy;
    vector<int> leaf_x, leaf_y;
    rep(i,n){
        if(i==root) continue;

        int H = 2*(h-1);
        if(dx[i]==H) leaf_y.pb(i);
        if(dy[i]==H) leaf_x.pb(i);

        if(dx[i]<dy[i]) vx.pb(i);
        else vy.pb(i);
    }

    dfs(vx,leaf_x,root,1);
    dfs(vy,leaf_y,root,1);

    ans(par);
    return 0;
}