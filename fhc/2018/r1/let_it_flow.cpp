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

const ll mod = 1000000007;

const int N = 1010;

int n;
string s[3];
// into from 0:left 1:up,bottom
ll dp[3][N][2];


ll dfs(int y, int x, int a){
    if(x==n){
        if(y==2 && a==0) return 1;
        return 0;
    }
    if(dp[y][x][a]>=0) return dp[y][x][a];

    ll ret = 0;
    if(a==0){
        for(int dy:{-1,1}){
            int ny=y+dy;
            if(0<=ny && ny<3 && s[ny][x]=='.') (ret += dfs(ny,x,!a)) %= mod;
        }
    }
    else{
        if(x+1==n || s[y][x+1]=='.') (ret += dfs(y,x+1,!a)) %= mod;
    }

    return dp[y][x][a] = ret;
}

ll solve(){
    cin >>n;
    rep(i,3) cin >>s[i];

    memset(dp,-1,sizeof(dp));
    ll ret = 0;
    if(s[0][0]=='.') ret = dfs(0,0,0);
    return ret;
}

int main(){
    int T;
    cin >>T;
    rep(i,T) printf("Case #%d: %lld\n",i+1,solve());
    return 0;
}
