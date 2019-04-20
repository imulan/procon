#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n;

map<vector<int>,int> dp[15][15][15];
int dfs(int x, int rem, int prev, const vector<int> &v){
    if(x==1) return 0;
    if(dp[x][rem][prev].count(v)) return dp[x][rem][prev][v];

    int s = 0;
    for(int i=2; i<x; ++i) s += i;
    s += rem;

    int vs = 0;
    rep(i,n) vs += (i+2)*v[i];

    if(s < vs){
        return dp[x][rem][prev][v] = 0;
    }

    bool ok = true;
    rep(i,n)if(v[i]>0) ok = false;
    if(ok){
        return dp[x][rem][prev][v] = 1;
    }

    int ret = 0;

    if(prev+1<n) ret |= dfs(x,rem,prev+1,v);
    ret |= dfs(x-1,x-1,0,v);
    if(v[prev]>0 && rem>=prev+2){
        vector<int> nv(v);
        --nv[prev];
        ret |= dfs(x,rem-prev-2,prev,nv);
    }

    return dp[x][rem][prev][v] = ret;
}

int main(){
    cin >>n;

    vector<int> v(n);
    rep(i,n) cin >>v[i];

    auto check = [&](int lim){
        return dfs(lim+1,lim+1,0,v);
    };

    for(int i=1; i<=12; ++i){
        if(check(i)){
            printf("%d\n", i);
            return 0;
        }
    }
    printf("impossible\n");
    return 0;
}


