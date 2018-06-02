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

const int N = 50;
vector<int> G[N];

int n,m,a,b,c;

const int D = 105;
bool dp[D][N][D];
bool vis[D][N][D];

bool dfs(int d, int p, int rem){
    if(rem==0){
        if(p == n-1) return true;
        if(d == 0) return false;
    }
    if(vis[d][p][rem]) return dp[d][p][rem];

    bool ret;
    if(rem==0){
        ret = true;
        ret &= dfs(d-1,p,a);
        ret &= dfs(d-1,p,b);
        ret &= dfs(d-1,p,c);
    }
    else{
        ret = false;
        for(int i:G[p]) ret |= dfs(d,i,rem-1);
    }

    vis[d][p][rem] = true;
    return dp[d][p][rem] = ret;
}

int main(){
    cin >>n >>m >>a >>b >>c;

    rep(i,m){
        int u,v;
        cin >>u >>v;
        --u;
        --v;
        G[u].pb(v);
    }

    const int LIM=100;
    for(int i=1; i<=LIM; ++i){
        if(dfs(i,0,0)){
            cout << i << endl;
            return 0;
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}
