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

const ll INF = LLONG_MAX/3;

int n,m,l;
vector<ll> k,s;

ll cost(int a, int b){
    return (s[k[b]]-s[k[a]-1])/l;
}

const int N = 2002;
ll dp[N][N];
ll dfs(int x, int y){
    if(dp[x][y]>=0) return dp[x][y];

    int nx = max(x,y)+1;
    if(nx == n){
        return cost(min(x,y), max(x,y));
    }

    ll ret = min(dfs(nx,y)+cost(x,nx), dfs(x,nx)+cost(y,nx));
    return dp[x][y] = ret;
}

int main(){
    cin >>n >>m >>l;

    k = vector<ll>(n);
    s = vector<ll>(m+1);
    rep(i,n) cin >>k[i];
    sort(all(k));

    rep(i,m) cin >>s[i+1];
    for(int i=1; i<=m; ++i) s[i] += s[i-1];

    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0) << endl;
    return 0;
}
