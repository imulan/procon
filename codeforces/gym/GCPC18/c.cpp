#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N = 1000;

int d[N][N];

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);

    memset(d,-1,sizeof(d));
    rep(i,n) d[i][i] = 0;

    rep(i,m){
        int s,t,c;
        scanf(" %d %d %d", &s, &t, &c);
        --s;
        --t;
        d[s][t] = max(d[s][t],c);
    }

    rep(k,n)rep(i,n)rep(j,n){
        if(d[i][k]==-1 || d[k][j]==-1) continue;
        d[i][j] = max(d[i][j], d[i][k]+d[k][j]);
    }

    int ans = 0;
    rep(i,n)rep(j,n) ans = max(ans, d[i][j]);
    printf("%d\n", ans);
    return 0;
}

