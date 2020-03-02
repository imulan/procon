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

int n;
string s[5];
int c[10];

map<pi,int> b2idx;

int m_dist(pi p, pi q){
    return abs(p.fi-q.fi)+abs(p.se-q.se);
}

int dp[5][5][11][1<<10];
int dfs(int y, int x, int ci, int mask){
    if(ci == n) return 0;
    if(dp[y][x][ci][mask] >= 0) return dp[y][x][ci][mask];

    int ret = 0;
    rep(i,5)rep(j,5){
        if(m_dist({i,j},{y,x}) == c[ci] && s[i][j]=='B'){
            int idx = b2idx[{i,j}];
            if(mask>>idx&1) continue;

            int nmask = mask|(1<<idx);
            if(dfs(i,j,ci+1,nmask) == 0) ret = 1;
        }
    }
    return dp[y][x][ci][mask] = ret;
}

int main(){
    cin >>n;
    rep(i,5) cin >>s[i];
    rep(i,n) cin >>c[i];

    int sy,sx;
    int bct=0;
    rep(i,5)rep(j,5){
        if(s[i][j]=='G'){
            sy = i;
            sx = j;
        }
        if(s[i][j]=='B'){
            b2idx[{i,j}] = bct;
            ++bct;
        }
    }

    memset(dp,-1,sizeof(dp));
    cout << (dfs(sy,sx,0,0)?"gori":"uho") << "\n";
    return 0;
}
