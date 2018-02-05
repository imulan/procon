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

struct edge{int to,cost;};

const int N = 1000000;
const int LIM = 10000001;
vector<edge> G[N];

vector<int> p[N];
vector<ll> pre_p[N];

void dfs(int x, int par){
    p[x].pb(0);
    for(const auto &e:G[x])if(e.to!=par){
        dfs(e.to,x);
        for(int w:p[e.to]){
            int nw = w+e.cost;
            if(nw<LIM) p[x].pb(nw);
        }
    }
    sort(all(p[x]));
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    for(int i=1; i<n; ++i){
        int u = (i+1)/2, v = i+1;
        --u; --v;

        int w;
        scanf(" %d", &w);

        G[u].pb({v,w});
        G[v].pb({u,w});
    }

    dfs(0,-1);

    rep(i,n){
        int P = p[i].size();
        pre_p[i] = vector<ll>(P);
        for(int j=1; j<P; ++j) pre_p[i][j] = pre_p[i][j-1]+p[i][j];
    }

    while(m--){
        int a,h;
        scanf(" %d %d", &a, &h);
        --a;

        ll ans = 0;

        int sw = 0;
        int ch = -1;
        while(1){
            if(sw<h) ans += h-sw;

            for(const auto &e:G[a])if(e.to!=ch && e.to>a){
                int tw = sw + e.cost;
                int idx = lower_bound(all(p[e.to]),h-tw) - p[e.to].begin();
                ll d = 0;
                if(idx>0) d = pre_p[e.to][idx-1];
                ans += (ll)(h-tw)*idx - d;
            }

            if(a==0) break;

            int par = (a-1)/2;
            for(const auto &e:G[par]){
                if(e.to==a) sw += e.cost;
            }
            ch = a;
            a = par;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
