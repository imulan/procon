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

using pi = pair<int,int>;

const int N = 1001;
const int INF = INT_MAX/2-1;

int n;
pi p[N];

pi GET(int l, int r){
    return {p[l].fi, p[r].se};
}

int DIST(pi a, pi b){
    return abs(a.fi-b.fi) + abs(a.se-b.se);
}

int dp[N][N];
int dfs(int l, int r){
    if(dp[l][r]>=0) return dp[l][r];
    if(l == r) return 0;

    pi root = GET(l,r);

    int ret = INF;
    for(int i=l; i<r; ++i){
        ret = min(ret, dfs(l,i)+DIST(root,GET(l,i)) + dfs(i+1,r)+DIST(root,GET(i+1,r)));
    }
    // dbg(root);
    // printf(" %d %d :: %d\n",l,r,ret);
    return dp[l][r] = ret;
}

int main(){
    scanf(" %d", &n);
    rep(i,n){
        int x,y;
        scanf(" %d %d", &x, &y);
        p[i] = {x,y};
    }
    memset(dp,-1,sizeof(dp));
    printf("%d\n", dfs(0,n-1));
    return 0;
}
