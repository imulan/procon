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
typedef pair<int,pi> edge;

const int INF=123456789;

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
    while(cin >>n >>m,n)
    {
        vector<edge> e(m);
        rep(i,m)
        {
            int a,b,w;
            scanf(" %d %d %d", &a, &b, &w);
            --a;
            --b;
            e[i]=edge(w,pi(a,b));
        }
        sort(all(e));

        int ans=INF;
        rep(i,m)
        {
            int min_cost=e[i].fi;
            int max_cost=INF;

            UF uf(n);
            for(int j=i; j<m; ++j)
            {
                int a=e[j].se.fi, b=e[j].se.se;
                if(!uf.same(a,b)) uf.unite(a,b);

                if(uf.size(0)==n)
                {
                    max_cost=e[j].fi;
                    break;
                }
            }

            // printf(" %d - %d\n", max_cost, min_cost);
            if(uf.size(0)==n) ans=min(ans,max_cost-min_cost);
        }

        if(ans==INF) ans=-1;
        printf("%d\n", ans);
    }
    return 0;
}
