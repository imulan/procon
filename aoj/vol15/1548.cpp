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

using pi = pair<int,int>;

const int N = 100000;
const int W = 100;
bool vis[N][W];

struct edge{ int to,cost; };
vector<edge> G[N];

const int INF = 19191919;

int main(){
    int n,m,w;
    scanf(" %d %d %d", &n, &m, &w);

    rep(i,m){
        int s,t,c;
        scanf(" %d %d %d", &s, &t, &c);
        G[s].pb({t,c});
    }

    queue<pi> que;
    rep(i,n) que.push({i,0});
    while(!que.empty()){
        pi now = que.front();
        que.pop();

        int v = now.fi, c = now.se;
        for(const auto &e:G[v]){
            int nv = e.to;
            int nc = c+e.cost;
            if(nc<W && !vis[nv][nc]){
                vis[nv][nc] = true;
                que.push({nv,nc});
            }
        }
    }

    int ans = -INF;
    rep(i,n){
        rep(j,-w)if(vis[i][j]) ans = max(ans, j+w);
    }
    if(ans == -INF) printf("NA\n");
    else printf("%d\n", ans);
    return 0;
}
