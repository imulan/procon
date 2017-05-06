#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;
using edge = pair<int,pi>;

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

int main()
{
    int n;
    while(scanf(" %d", &n),n)
    {
        int m;
        scanf(" %d", &m);

        vector<edge> e(m);
        rep(i,m)
        {
            int a,b,d;
            scanf(" %d,%d,%d", &a, &b, &d);
            e[i] = edge(d,pi(a,b));
        }
        sort(all(e));

        UF uf(n);
        ll ans = 0;
        rep(i,m)
        {
            int a=e[i].se.fi, b=e[i].se.se, cost=e[i].fi;
            if(!uf.same(a,b))
            {
                uf.unite(a,b);
                ans += cost/100 - 1;
            }
        }

        printf("%lld\n", ans);
    }
    return 0;
}
