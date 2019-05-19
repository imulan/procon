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

struct edge{int to,p;};

const int N = 100010;
vector<edge> G[N];

int col[N];
void dfs(int x, int par){
    for(const auto &e:G[x])if(e.to!=par){
        col[e.to] = (col[x]+e.p)%2;
        dfs(e.to,x);
    }
}

int main(){
    int n;
    scanf(" %d", &n);
    rep(i,n-1){
        int u,v,w;
        scanf(" %d %d %d", &u, &v, &w);
        --u;
        --v;
        w %= 2;
        G[u].pb({v,w});
        G[v].pb({u,w});
    }

    col[0] = 0;
    dfs(0,-1);
    rep(i,n) printf("%d\n", col[i]);
    return 0;
}
