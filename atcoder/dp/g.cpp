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
vector<int> G[N];
bool vis[N];
vector<int> tlist;

void dfs(int v){
    if(vis[v]) return;
    vis[v] = true;
    for(int e:G[v]){
        dfs(e);
    }
    tlist.pb(v);
}

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
    rep(i,m){
        int from,to;
        scanf(" %d %d", &from, &to);
        --from;
        --to;
        G[from].pb(to);
    }

    rep(i,n) dfs(i);
    reverse(all(tlist));

    int ans = 0;
    vector<int> dp(n);
    for(int i:tlist){
        for(int e:G[i]) dp[e] = max(dp[e], dp[i]+1);
        ans = max(ans, dp[i]);
    }
    printf("%d\n", ans);
    return 0;
}
