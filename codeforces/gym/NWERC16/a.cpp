#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N = 40;
const int INF = 1919191;

int n,m;

const int M = 444;
char s[N][M];
char ans[N][M];

int dp[401][41][41][11];
int dfs(int d, int l, int r, int a){
    if(d==m) return 0;
    if(l>=r) return 0;
    if(a==10) return INF;

    if(dp[d][l][r][a]>=0) return dp[d][l][r][a];

    int ret = INF;
    int ad = 0;

    char aa = '0'+a;
    for(int nl=l; nl<=r; ++nl){
        int t = dfs(d+1,l,nl,0)+dfs(d,nl,r,a+1)+ad;
        ret = min(ret,t);

        if(nl<r) ad += (s[nl][d] != aa);
    }

//    printf("%d %d %d %d ,, ret %d\n",d,l,r,a,ret);
    return dp[d][l][r][a] = ret;
}

void makeans(int d, int l, int r, int a) {
    if(d==m) return;
    if(l>=r) return;
    if(a==10) return;

    int VAL = dfs(d,l,r,a);
    int idx = -1;
    int ad = 0;
    for(int nl=l; nl<=r; ++nl){
        int t = dfs(d+1,l,nl,0)+dfs(d,nl,r,a+1)+ad;
        if(VAL == t){
            idx = nl;
            break;
        }

        if(nl<r) ad += (s[nl][d] != ('0'+a));
    }

    char aa = '0'+a;
    for(int i=l; i<idx; ++i) ans[i][d] = aa;

    makeans(d+1,l,idx,0);
    makeans(d,idx,r,a+1);
}

int main(){
    scanf(" %d %d", &n, &m);
    rep(i,n){
        scanf(" %s", s[i]);
        rep(j,m) ans[i][j] = s[i][j];
    }

    memset(dp,-1,sizeof(dp));
    dfs(0,0,n,0);
    makeans(0,0,n,0);
    rep(i,n) printf("%s\n", ans[i]);
    return 0;
}