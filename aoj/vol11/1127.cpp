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
typedef pair<double,pi> P;

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

int n;
double x[100],y[100],z[100],r[100];

inline double dist(int i, int j)
{
    return sqrt( (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]) + (z[i]-z[j])*(z[i]-z[j]) );
}

inline double make_edge(int i, int j)
{
    double ret=dist(i,j)-r[i]-r[j];
    return ret>0?ret:0;
}

int main()
{
    while(cin >>n,n)
    {
        rep(i,n) scanf(" %lf %lf %lf %lf", &x[i], &y[i], &z[i], &r[i]);

        vector<P> e;
        rep(i,n)rep(j,i) e.pb(P(make_edge(i,j),pi(i,j)));
        sort(all(e));

        double ans=0;
        UF uf(n);
        rep(i,e.size())
        {
            int a=e[i].se.fi, b=e[i].se.se;
            if(!uf.same(a,b))
            {
                uf.unite(a,b);
                ans+=e[i].fi;
            }

            if(uf.size(0)==n) break;
        }

        printf("%.3f\n", ans);
    }
    return 0;
}
