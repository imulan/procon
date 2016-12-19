#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<double,pi> edge;

inline double dist(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

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
    int n,m;
    scanf(" %d %d", &n, &m);

    vector<int> x(n),y(n);
    rep(i,n) scanf(" %d %d", &x[i], &y[i]);

    vector<edge> e(m);
    double sum=0;
    rep(i,m)
    {
        int p,q;
        scanf(" %d %d", &p, &q);
        --p;
        --q;

        e[i] = edge(dist(x[p],y[p],x[q],y[q]), pi(p,q));
        sum += e[i].fi;
    }

    sort(all(e),greater<edge>());

    UF uf(n);
    double mst_max_cost=0;
    rep(i,m)
    {
        int p=e[i].se.fi, q=e[i].se.se;
        if(!uf.same(p,q))
        {
            uf.unite(p,q);
            mst_max_cost += e[i].fi;
        }
    }

    printf("%.10f\n", sum - mst_max_cost);
    return 0;
}
