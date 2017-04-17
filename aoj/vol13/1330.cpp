#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    // rootと比べてどれくらい重いか
    vector<int> w;

    UF() {}
    UF(int N):n(N), d(N,-1), w(N,0){}

    int root(int v){
        if(d[v]<0) return v;

        int par = d[v];

        int r = root(d[v]);
        d[v] = r;
        w[v] += w[par];

        return d[v];
    }
    bool unite(int X,int Y,int W){
        int rx = root(X), ry = root(Y);
        if(rx==ry) return false;

        int RW = -w[Y] + w[X] + W;

        if(size(rx) < size(ry))
        {
            swap(rx,ry);
            swap(X,Y);
            RW = -RW;
        }


        d[rx]+=d[ry];
        d[ry]=rx;

        w[ry] = RW;

        // printf(" UNITE : %d -> %d : w[%d]=%d\n", ry,rx, ry, w[ry]);
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }

    int query(int X, int Y){
        root(X);
        root(Y);
        // printf(" query : %d -> %d  = %d\n", X,Y,w[Y]-w[X]);
        return w[Y]-w[X];
    }
};

int main()
{
    int n,m;
    while(scanf(" %d %d", &n, &m),n)
    {
        UF uf(n);

        while(m--)
        {
            char q;
            int a,b;
            scanf(" %c %d %d", &q, &a, &b);
            --a;
            --b;

            if(q=='?')
            {
                if(!uf.same(a,b)) printf("UNKNOWN\n");
                else printf("%d\n", uf.query(b,a));
            }
            else
            {
                int w;
                scanf(" %d", &w);
                uf.unite(b,a,w);
            }
        }
    }
    return 0;
}
