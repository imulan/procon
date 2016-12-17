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
    while(scanf(" %d %d", &n, &m),n)
    {
        vector<edge> e(m);
        rep(i,m)
        {
            int s,t,c;
            scanf(" %d %d %d", &s, &t, &c);
            --s;
            --t;
            e[i] = edge(c,pi(s,t));
        }

        sort(all(e));

        UF uf(n);
        vector<int> used;
        rep(i,m)
        {
            int a=e[i].se.fi, b=e[i].se.se;
            if(!uf.same(a,b))
            {
                uf.unite(a,b);
                used.pb(e[i].fi);
            }
        }

        printf("%d\n", used[n/2-1]);
    }
    return 0;
}
