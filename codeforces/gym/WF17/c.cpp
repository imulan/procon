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

const int MAX_V = 200;
int V;
vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

void add_edge(int u, int v){
    G[u].pb(v);
    G[v].pb(u);
}

bool bp_dfs(int v){
    used[v] = true;
    rep(i,G[v].size()){
        int u = G[v][i], w = match[u];
        if(w<0 || (!used[w]&&bp_dfs(w))){
            match[v] = u;
            match[u] = v;
            return true;
        }
    }
    return false;

}

int bp_matching(){
    int ret = 0;
    memset(match, -1, sizeof(match));
    rep(i,V){
        if(match[i]<0){
            memset(used, 0, sizeof(used));
            if(bp_dfs(i)) ++ret;
        }
    }
    return ret;
}

int main(){
    int h,w;
    cin >>h >>w;

    ll xx = 0;
    int one = 0;
    vector<vector<ll>> x(h, vector<ll>(w));
    vector<ll> ux;
    vector<ll> r(h), c(w);
    rep(i,h)rep(j,w){
        cin >>x[i][j];
        xx += x[i][j];

        if(x[i][j] != 0) ++one;

        --x[i][j];
        if(x[i][j]>0) ux.pb(x[i][j]);

        r[i] = max(r[i], x[i][j]);
        c[j] = max(c[j], x[i][j]);
    }

    sort(all(ux));
    ux.erase(unique(all(ux)), ux.end());
    int UX = ux.size();

    vector<vector<int>> ur(UX), uc(UX);
    rep(i,h){
        if(r[i]>0){
            int idx = lower_bound(all(ux), r[i]) - ux.begin();
            ur[idx].pb(i);
        }
    }
    rep(i,w){
        if(c[i]>0){
            int idx = lower_bound(all(ux), c[i]) - ux.begin();
            uc[idx].pb(i);
        }
    }

    V = h+w;

    ll ans = one;
    rep(i,UX){
        ll val = ux[i];

        rep(j,MAX_V) G[j].clear();
        for(int ridx:ur[i])for(int cidx:uc[i]){
            if(x[ridx][cidx]!=-1){
                // printf("ADD %d %d\n", ridx, cidx);
                add_edge(ridx, h+cidx);
            }
        }

        int m = bp_matching();
        // dbg(val);
        // dbg(m);

        ll ct = 0;
        rep(j,h) ct += (r[j]==val);
        rep(j,w) ct += (c[j]==val);

        ans += val*(ct-m);
    }

    cout << xx - ans << '\n';
    return 0;
}
