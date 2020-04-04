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
using edge = pair<int,pi>;

const int LIM = 1000000;

int main(){
    int n;
    scanf(" %d", &n);

    vector<vector<int>> G(n);
    map<pi,int> e2id;
    rep(i,n-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);
        e2id[{u,v}] = i;
        e2id[{v,u}] = i;
    }

    int m;
    scanf(" %d", &m);
    vector<edge> e(m);
    map<int,vector<int>> w;
    rep(i,m){
        int a,b,g;
        scanf(" %d %d %d", &a, &b, &g);
        --a;
        --b;
        e[i] = {g,{a,b}};
        w[g].pb(i);
    }

    vector<int> par(n,-1);
    vector<int> d(n);
    queue<int> que({0});
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int i:G[v])if(i!=par[v]){
            d[i] = d[v]+1;
            par[i] = v;
            que.push(i);
        }
    }

    vector<int> LCA(m);
    rep(i,m){
        int a = e[i].se.fi, b = e[i].se.se;
        if(d[a] > d[b]) swap(a,b);
        while(d[a] < d[b]) b = par[b];

        while(a!=b){
            a = par[a];
            b = par[b];
        }
        LCA[i] = a;
    }

    vector<int> eid2par(n,-1);
    for(int i=1; i<n; ++i) eid2par[i] = e2id[{i,par[i]}];

    vector<int> ect(n-1);
    vector<vector<int>> eids(m);
    rep(i,m){
        int a = e[i].se.fi, b = e[i].se.se;
        while(a!=LCA[i]){
            int ei = eid2par[a];
            ++ect[ei];
            eids[i].pb(ei);
            a = par[a];
        }
        while(b!=LCA[i]){
            int ei = eid2par[b];
            ++ect[ei];
            eids[i].pb(ei);
            b = par[b];
        }
    }

    vector<int> ans(n-1,LIM);

    for(const auto &wi:w){
        vector<int> idx = wi.se;
        for(int i:idx){
            for(int ei:eids[i]) --ect[ei];
        }

        for(int i:idx){
            int a = e[i].se.fi, b = e[i].se.se;
            int x = -1;
            while(a!=LCA[i]){
                int ei = eid2par[a];
                if(ect[ei] == 0) x = ei;
                a = par[a];
            }
            while(b!=LCA[i]){
                int ei = eid2par[b];
                if(ect[ei] == 0) x = ei;
                b = par[b];
            }

            if(x == -1){
                printf("-1\n");
                return 0;
            }
            ans[x] = wi.fi;
        }
    }

    rep(i,n-1) printf("%d%c", ans[i], " \n"[i==n-1]);
    return 0;
}
