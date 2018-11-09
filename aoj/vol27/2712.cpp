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

typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int,int> edge;

vector<vi> G;

void bridge_dfs(int now, int from, vector<edge> &bridge, vector<vi> &bicomp, stack<int> &roots,
                stack<int> &S, vb &inS, vi &preord, int &pre_ct){
    preord[now] = pre_ct++;
    S.push(now); inS[now]=true;
    roots.push(now);
    rep(i,G[now].size()){
        int to = G[now][i];
        if(preord[to] == -1) bridge_dfs(to,now,bridge,bicomp,roots,S,inS,preord,pre_ct);
        else if(from != to && inS[to]) while(preord[roots.top()] > preord[to]) roots.pop();
    }
    if(now == roots.top()){
        bridge.pb(edge(now,from));
        bicomp.pb(vi());
        while(1){
            int v=S.top(); S.pop(); inS[v]=false;
            bicomp.back().pb(v);
            if(now == v) break;
        }
        roots.pop();
    }
}

void bridge_detect(vector<edge> &bridge, vector<vi> &bicomp){
    const int n=G.size();
    vi preord(n,-1);
    vb inS(n,false);
    stack<int> roots,S;
    int pre_ct=0;
    rep(i,n)if(preord[i] == -1){
        bridge_dfs(i,n,bridge,bicomp,roots,S,inS,preord,pre_ct);
        bridge.pop_back();
    }
}

vector<vi> T;
vi par;
vb leaf;
void dfs(int v, int p){
    par[v] = p;
    for(int e:T[v])if(e!=p){
        dfs(e,v);
        leaf[v] = false;
    }
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> w(n);
    rep(i,n) scanf(" %d", &w[i]);
    vector<int> a(m),b(m);
    rep(i,m){
        scanf(" %d %d", &a[i], &b[i]);
        --a[i];
        --b[i];
    }

    G = vector<vi>(n);
    rep(i,m){
        G[a[i]].pb(b[i]);
        G[b[i]].pb(a[i]);
    }

    vector<edge> bridge;
    vector<vi> bicomp;
    bridge_detect(bridge, bicomp);

    int sz = bicomp.size();

    vector<int> cmp(n);
    rep(i,sz){
        for(int j:bicomp[i]) cmp[j] = i;
    }

    T = vector<vi>(sz);
    rep(i,m){
        int u = cmp[a[i]], v = cmp[b[i]];
        if(u!=v){
            T[u].pb(v);
            T[v].pb(u);
        }
    }

    int root = cmp[0];
    par = vi(sz,-1);
    leaf = vb(sz,true);
    dfs(root,-1);

    vector<bool> ok(sz);
    queue<int> que;
    rep(i,sz){
        if(bicomp[i].size()>1){
            ok[i] = true;
            que.push(i);
        }
    }
    while(!que.empty()){
        int now = que.front();
        que.pop();

        int pp = par[now];
        if(pp==-1) continue;

        if(!ok[pp]){
            ok[pp] = true;
            que.push(pp);
        }
    }

    int ans = 0;
    rep(i,sz){
        if(!ok[i] && leaf[i]){
            int tmp = 0;
            int idx = i;
            while(idx!=-1 && !ok[idx]){
                tmp += w[bicomp[idx][0]];
                idx = par[idx];
            }

            ans = max(ans, tmp);
        }
    }

    rep(i,sz)if(ok[i]){
        for(int j:bicomp[i]) ans += w[j];
    }

    cout << ans << endl;
    return 0;
}
