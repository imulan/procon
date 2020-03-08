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
using P = pair<pi,int>;

const int N = 14;
vector<int> G[N];

const int INF = 191919;

int E[N][N][1<<N];
int pE[N][N][1<<N];

int dp[1<<N];
P par[1<<N];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    rep(i,n)rep(j,n)rep(k,1<<n) E[i][j][k] = INF;
    memset(pE,-1,sizeof(pE));

    rep(i,m){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        G[u].pb(v);
        G[v].pb(u);

        E[u][v][0] = E[v][u][0] = 1;
        pE[u][v][0] = u;
        pE[v][u][0] = v;
    }

    rep(mask,1<<n)rep(x,n)rep(y,n)if(E[x][y][mask] < INF){
        for(int z:G[y]){
            if(mask==0 && z==x) continue;
            if(!(mask>>z&1)){
                int nx = mask|(1<<y);
                E[x][z][nx] = E[x][y][mask]+1;
                pE[x][z][nx] = y;
            }
        }
    }

    const int U = (1<<n)-1;
    rep(i,1<<n){
        dp[i] = INF;
        par[i] = {{-1,-1},-1};
    }
    dp[1] = 0;

    for(int mask=1; mask<(1<<n); ++mask){
        int S = (~mask)&U;
        int addmask = S;
        while(addmask){
            rep(x,n)rep(y,x+1)if((mask>>x&1) && (mask>>y)&1 && E[x][y][addmask]<INF){
                int nmask = mask|addmask;
                if(dp[nmask] > dp[mask]+E[x][y][addmask]){
                    dp[nmask] = dp[mask]+E[x][y][addmask];
                    par[nmask] = {{x,y},addmask};
                }
            }

            addmask = (addmask-1)&S;
        }
    }

    printf("%d\n", dp[(1<<n)-1]);
    int now = (1<<n)-1;
    while(now>1){
        P p = par[now];
        int x = p.fi.fi, y = p.fi.se, addmask = p.se;

        while(pE[x][y][addmask] != -1){
            int t = pE[x][y][addmask];
            printf("%d %d\n", y+1, t+1);

            y = t;
            addmask ^= (1<<t);
        }
        now ^= p.se;
    }
    return 0;
}
