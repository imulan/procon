#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

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

using pi = pair<int,int>;

const int N = 1000000;
vector<int> G[N];

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    rep(i,n-1){
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        G[x].pb(y);
        G[y].pb(x);
    }

    auto calc = [&](){
        vector<pi> v(n);
        rep(i,n) v[i] = {a[i],i};
        sort(all(v));

        vector<int> rank(n);
        rep(i,n) rank[v[i].se] = i;

        UF uf(n);
        ll ret = 0;
        rep(i,n){
            int u = v[i].se;
            ll sum = 0, sq = 0;
            for(int nx:G[u])if(rank[nx] < rank[u]){
                ll sz = uf.size(nx);
                sum += sz;
                sq += sz*sz;
            }
            ret += (sum + (sum*sum-sq)/2)*a[u];
            for(int nx:G[u])if(rank[nx] < rank[u]) uf.unite(u,nx);
        }
        return ret;
    };

    ll MX = calc();
    rep(i,n) a[i] = -a[i];
    ll MN = calc();

    printf("%lld\n", MX+MN);
    return 0;
}
