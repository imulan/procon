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

const int MAX_V = 66;
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

int bipartite_matching(){
    int ret = 0;
    memset(match,-1,sizeof(match));
    rep(i,V){
        if(match[i]<0){
            memset(used,0,sizeof(used));
            if(bp_dfs(i)) ++ret;
        }
    }
    return ret;
}

int main(){
    int n;
    cin >>n;

    vector<vector<int>> a(n,vector<int>(n));
    rep(i,n)rep(j,n) cin >>a[i][j];

    V = 2*n;

    auto check = [&](int x){
        rep(i,MAX_V) G[i].clear();
        rep(i,n)rep(j,n){
            if(a[i][j]>=x){
                add_edge(i,n+j);
            }
        }
        return bipartite_matching() == n;
    };

    int ok = 1, ng = 1000001;
    while(ng-ok>1){
        int mid = (ok+ng)/2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
    return 0;
}
