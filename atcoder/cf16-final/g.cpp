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

const int N=200000;
const ll INF=123456789012345LL;
ll dp[N];

typedef pair<int,int> pi;
typedef pair<ll,pi> edge;
vector<edge> e;

int main()
{
    int n,Q;
    scanf(" %d %d", &n, &Q);

    fill(dp,dp+N,INF);

    while(Q--)
    {
        int a,b;
        ll c;
        scanf(" %d %d %lld", &a, &b, &c);

        e.pb(edge(c,pi(a,b)));
        dp[a]=min(dp[a],c+1);
        dp[b]=min(dp[b],c+2);
    }

    rep(_,2)rep(i,n) dp[i]=min(dp[i], dp[(i-1+n)%n]+2);
    rep(i,n) e.pb(edge(dp[i],pi(i,(i+1)%n)));

    sort(all(e));

    UF uf(n);
    ll ans=0;
    rep(i,e.size())
    {
        int a=e[i].se.fi, b=e[i].se.se;
        if(!uf.same(a,b))
        {
            uf.unite(a,b);
            ans+=e[i].fi;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
