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

int n;
string s[2];

const int N = 111;
int dp[N][2][2];

int dfs(int x, int u, int b){
    if(x==n) return 0;
    if(dp[x][u][b]>=0) return dp[x][u][b];

    int nu = (s[0][x]=='X'), nb = (s[1][x]=='X');
    int ret = dfs(x+1,nu,nb);
    if(u==0 && b==0){
        if(nu==0) ret = max(ret, dfs(x+1,1,nb)+1);
        if(nb==0) ret = max(ret, dfs(x+1,nu,1)+1);
    }
    if(nu==0 && nb==0){
        if(u==0 || b==0) ret = max(ret, dfs(x+1,1,1)+1);
    }

    return dp[x][u][b] = ret;
}

int main(){
    rep(i,2) cin >>s[i];
    n = s[0].size();
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,1,1) << endl;
    return 0;
}
