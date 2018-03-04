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

const int N = 300000;
vector<int> G[N];

int c = 1;
int ans[N];
vector<int> C[N];

void dfs(int v, int par){
    int SZ = C[v].size();
    if(SZ>1){
        vector<int> x = C[v];
        set<int> ap;
        rep(j,SZ){
            if(ans[x[j]] != -1){
                assert(!ap.count(ans[x[j]]));
                ap.insert(ans[x[j]]);
            }
        }

        int idx = 1;
        rep(j,SZ)if(ans[x[j]]==-1){
            while(ap.count(idx)) ++idx;

            assert(idx <= c);
            ans[x[j]] = idx;
            ap.insert(idx);
        }
    }

    for(int nx:G[v])if(nx!=par) dfs(nx, v);
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,n){
        int s;
        scanf(" %d", &s);
        c = max(c,s);

        C[i] = vector<int>(s);
        rep(j,s){
            scanf(" %d", &C[i][j]);
            --C[i][j];
        }
    }

    rep(i,n-1){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u; --v;
        G[u].pb(v);
        G[v].pb(u);
    }

    memset(ans,-1,sizeof(ans));
    dfs(0,-1);
    rep(i,m)if(ans[i]==-1) ans[i]=1;

    printf("%d\n",c);
    rep(i,m) printf("%d%c", ans[i], " \n"[i==m-1]);
    return 0;
}
