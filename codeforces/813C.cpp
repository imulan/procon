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

const int N = 200000;

vector<int> G[N];
int par[N];
int d[N];
// 部分木で、最も遠い頂点との距離
int dp[N];

int dfs(int now){
    int ret = 0;
    for(int nx:G[now]){
        if(par[now] != nx){
            par[nx] = now;
            d[nx] = d[now] + 1;
            ret = max(ret,dfs(nx)+1);
        }
    }
    return dp[now] = ret;
}

int main(){
    int n,x;
    cin >>n >>x;
    --x;
    rep(i,n-1){
        int a,b;
        cin >>a >>b;
        --a; --b;
        G[a].pb(b);
        G[b].pb(a);
    }

    par[0] = -1;
    d[0] = 0;
    dfs(0);

    int ans = 0;

    int bob = 0;
    while(d[x] > bob){
        // xまで行き、そこから遠いとこまで逃げる
        ans = 2*(d[x]+dp[x]);

        x = par[x];
        ++bob;
    }

    cout << ans << endl;
    return 0;
}
