#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))

using B = bitset<500>;
int n,m;
B b[500];

int dp(){
    vector<int> dp(1<<m,-1919);
    dp[0] = 0;
    rep(i,n){
        int t = 0;
        rep(j,m) t |= (b[i][j]<<j);
        vector<int> nx(dp);
        rep(mask,1<<m) nx[mask^t] = max(nx[mask^t], dp[mask]+1);
        dp = nx;
    }
    return dp[0];
}

int dfs(int idx, const B &g){
    if(idx==n){
        rep(i,m)if(g[i]) return -1919;
        return 0;
    }
    B ng = g^b[idx];
    return max(dfs(idx+1,g), dfs(idx+1,ng)+1);
}

int main(){
    while(scanf(" %d %d", &n, &m),n){
        rep(i,n){
            char s[505];
            scanf(" %s",s);
            b[i] = B(s);
        }
        printf("%d\n", (m<n ? dp() : dfs(0,B())));
    }
    return 0;
}
