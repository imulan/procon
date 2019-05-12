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

const int N = 1000;

int n;
int c[N];

struct edge{ int to,cost; };
vector<edge> G[N];

int dfs(int v, int par){
    int ret = 0;
    for(const auto &e:G[v])if(e.to != par){
        int add = e.cost;
        if(c[e.to] == 0) add = min(add, dfs(e.to, v));
        ret += add;
    }
    return ret;
}

int main(){
    cin >>n;
    for(int i=1; i<n; ++i) cin >>c[i];

    rep(i,n-1){
        int u,v,p;
        cin >>u >>v >>p;
        G[u].pb({v,p});
        G[v].pb({u,p});
    }

    cout << dfs(0,-1) << endl;
    return 0;
}
