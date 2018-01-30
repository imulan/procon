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

const int N = 100000;
vector<int> G[N],rG[N];

vector<int> tl;
bool vis[N]={};
void dfs(int x){
    if(!vis[x]){
        vis[x]=true;
        for(int e:G[x]) dfs(e);
        tl.pb(x);
    }
}

int dp[N];
int main(){
    int n,m;
    cin >>n >>m;
    vector<int> exe(n);
    rep(i,n) cin >>exe[i];
    rep(i,m){
        int u,v;
        cin >>u >>v;
        G[v].pb(u);
        rG[u].pb(v);
    }

    rep(i,n) dfs(i);
    reverse(all(tl));

    for(int v:tl){
        if(exe[v]) dp[v] = max(dp[v],1);

        for(int nx:G[v])
        {
            int add = 0;
            if(!exe[v] && exe[nx]) add = 1;
            dp[nx] = max(dp[nx],dp[v]+add);
        }
    }

    int ans = 0;
    rep(i,n) ans = max(ans,dp[i]);
    cout << ans << endl;
    return 0;
}
