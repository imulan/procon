#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<int,pi> edge;

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
    while(cin >>n)
    {
        vector<edge> e;
        rep(i,n)rep(j,n)
        {
            int c;
            scanf(" %d", &c);

            e.pb(edge(c,pi(i,j)));
        }
        sort(all(e));

        UF uf(n);
        int ans=0;
        rep(i,e.size())
        {
            int u=e[i].se.fi, v=e[i].se.se;
            if(!uf.same(u,v))
            {
                // printf("%dd :(%d,%d)\n", e[i].fi,u,v);
                uf.unite(u,v);
                ans+=e[i].fi;
            }
        }

        printf("%d\n", ans);
    }
    return 0;
}
