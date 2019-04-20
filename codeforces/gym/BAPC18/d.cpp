#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define fi first
#define se second

struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N):n(N), d(N,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int X,int Y){
        X=root(X); Y=root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};

int main(){
    int n,A,B;
    scanf(" %d %d %d", &n, &A, &B);

    vector<int> l(n),r(n),t(n);
    rep(i,n) scanf(" %d %d %d", &l[i], &r[i], &t[i]);

    UF uf(n);
    using P = pair<pair<int,int>,int>;
    queue<P> que({ {{A,B},0} });
    while(!que.empty()){
        P now = que.front();
        que.pop();
        int x = now.fi.fi, y = now.fi.se, d = now.se;

        if(t[x] != t[y]){
            printf("%d\n", d);
            return 0;
        }

        if(!uf.unite(x,y)) continue;
        que.push({{l[x],l[y]}, d+1});
        que.push({{r[x],r[y]}, d+1});
    }
    printf("indistinguishable\n");
    return 0;
}
