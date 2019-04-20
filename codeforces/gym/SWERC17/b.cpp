#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define fi first
#define se second
#define pb push_back

const int F = 2002;
int f[F][F]={};

int ans[F][F]={};

int main(){
    int X,Y,N,D;
    scanf(" %d %d %d %d", &X, &Y, &N, &D);


    rep(i,N){
        int lx,rx,ly,ry;
        scanf(" %d %d %d %d", &lx, &rx, &ly, &ry);
        for(int x=lx; x<rx; ++x)for(int y=ly; y<ry; ++y) ++f[y][x];
    }

    rep(i,Y){
        rep(j,X) printf("%d", f[i][j]);
        printf("\n");
    }




    while(D--){
        int qx,qy;
        scanf(" %d %d", &qx, &qy);
        printf("%d\n", ans[qy][qx]);
    }
    return 0;

}
