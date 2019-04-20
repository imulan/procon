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

const int N = 100001;
vector<int> G[N];
int ans[N];

int n;
int k[N];

int et[N];
int el[N],er[N];
int eidx = 0;

int d0[N];
void make_ET(int x, int par){
    if(par!=-1) d0[x] = d0[par]+1;

    et[eidx] = x;
    el[x] = eidx;
    ++eidx;
    for(int nx:G[x])if(nx != par){
        make_ET(nx, x);
    }
    er[x] = eidx;
}

// const int B = 150;
// const int C = 667;
// const int B = 180;
// const int C = 556;
// const int B = 100;
// const int C = 1000;
const int B = 400;
const int C = 250;

int add[B]={};
int W = 0;
int flg[B]={};

int d[B][C];
int sd[B][C];

inline void PUSH(int b){
    if(!flg[b]) return;
    flg[b] = 0;
    rep(i,C) sd[b][i] = d[b][i];
    sort(sd[b], sd[b]+C);
}

inline void ADD(int l, int r, int v){
    int lidx = l/C, ridx = r/C;
    flg[lidx] = flg[ridx] = 1;
    if(lidx == ridx){
        for(int i=l; i<=r; ++i) d[i/C][i%C] += v;
    }
    else{
        for(int i=l; i<C*(lidx+1); ++i) d[lidx][i%C] += v;
        for(int b=lidx+1; b<ridx; ++b) add[b] += v;
        for(int i=ridx*C; i<=r; ++i) d[ridx][i%C] += v;
    }
}

void dfs(int x, int par){
    // calc
    int ok = -1, ng = n;
    while(ng-ok>1){
        int mid = (ok+ng)/2;
        int ct = 0;
        rep(i,B){
            PUSH(i);
            int idx = upper_bound(sd[i],sd[i]+C,mid-add[i]-W) - sd[i];
            ct += C - idx;
            if(ct>=k[x]) break;
        }
        if(ct>=k[x]) ok = mid;
        else ng = mid;
    }
    ans[x] = ok;

    // go children
    for(int nx:G[x])if(nx != par){
        ++W;
        ADD(el[nx], er[nx]-1, -2);

        dfs(nx, x);

        --W;
        ADD(el[nx], er[nx]-1, 2);
    }
}

int dist[N];
int par[N];
void DFS(int x){
    if(par[x]!=-1) dist[x] = dist[par[x]]+1;
    for(int nx:G[x])if(nx!=par[x]){
        par[nx] = x;
        DFS(nx);
    }
}

int main(){
    scanf(" %d", &n);
    rep(i,n) scanf(" %d", &k[i]);
    rep(i,n-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    dist[0] = 0;
    par[0] = -1;
    DFS(0);

    int X = -1;
    int md = -1;
    rep(i,n){
        if(dist[i] > md){
            md = dist[i];
            X = i;
        }
    }

    dist[X] = 0;
    par[X] = -1;
    DFS(X);

    int Y = -1;
    md = -1;
    rep(i,n){
        if(dist[i] > md){
            md = dist[i];
            Y = i;
        }
    }

    int root = Y;
    rep(i,md/2) root = par[root];

    // dbg(root);

    make_ET(root,-1);

    rep(i,B)rep(j,C) d[i][j] = -N;
    rep(i,n) d[i/C][i%C] = d0[et[i]];
    rep(i,B){
        flg[i] = 1;
        PUSH(i);
    }

    dfs(root,-1);
    rep(i,n) printf("%d%c", ans[i], " \n"[i==n-1]);
    return 0;
}
