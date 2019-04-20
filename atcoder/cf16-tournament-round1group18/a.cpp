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
    scanf(" %d %d", &n, &m);

    vector<edge> e(m);
    rep(i,m)
    {
        int a,b,c;
        scanf(" %d %d %d", &a, &b, &c);
        --a;
        --b;
        e[i]=edge(c,pi(a,b));
    }

    sort(all(e));

    vector<edge> mst;
    UF uf(n);
    ll mst_cost=0;
    rep(i,m)
    {
        int a=e[i].se.fi, b=e[i].se.se;
        if(!uf.same(a,b))
        {
            uf.unite(a,b);
            mst_cost+=e[i].fi;
            mst.pb(e[i]);
        }
    }

    // printf(" mst:%lld\n", mst_cost);
    int MST=mst.size();

    int Q;
    scanf(" %d", &Q);

    if(Q>1) return 0;

    while(Q--)
    {
        int s,t;
        scanf(" %d %d", &s, &t);
        --s;
        --t;

        ll ans=mst_cost;
        for(int i=MST-1; i>=0; --i)
        {
            ll tmp=0;
            UF u(n);
            rep(j,MST)
            {
                if(i==j) continue;

                int a=mst[j].se.fi, b=mst[j].se.se;
                // printf("a,b %d %d\n", a,b);
                u.unite(a, b);
                tmp+=mst[j].fi;
            }

            // printf("i= %d, tmp %lld\n", i,tmp);

            bool ok=true;
            rep(j,n)
            {
                if(!u.same(s,j) && !u.same(t,j)) ok=false;
            }
            if(ok)
            {
                ans=min(ans,tmp);
            }
        }

        cout << ans << endl;
    }

    return 0;
}
