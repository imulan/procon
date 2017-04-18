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
typedef pair<ll,pi> edge;

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

    vector<ll> c(n);
    rep(i,n) scanf(" %lld", &c[i]);

    vector<edge> e(m);
    rep(i,m)
    {
        int a,b;
        ll r;
        scanf(" %d %d %lld", &a, &b, &r);
        --a;
        --b;
        e[i] = edge(r,pi(a,b));
    }
    sort(all(e));

    ll c_sum=0;
    rep(i,n) c_sum += c[i];
    ll e_sum=0;

    ll ans=c_sum;
    UF uf(n);
    rep(i,m)
    {
        int a=e[i].se.fi, b=e[i].se.se;
        ll cost=e[i].fi;

        if(!uf.same(a,b))
        {
            int ra=uf.root(a), rb=uf.root(b);
            ll min_c = min(c[ra],c[rb]);
            ll max_c = max(c[ra],c[rb]);

            if(cost - max_c >= 0) continue;

            c_sum -= max_c;
            e_sum += cost;

            uf.unite(a,b);
            c[ra]=c[rb]=min_c;
        }

        ans = min(ans,c_sum+e_sum);
    }

    printf("%lld\n", ans);
    return 0;
}
