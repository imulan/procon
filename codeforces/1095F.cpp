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

using P = pair<ll,int>;

using pi = pair<int,int>;
using E = pair<ll,pi>;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    int n,m;
    cin >>n >>m;

    vector<P> a(n);
    rep(i,n){
        cin >>a[i].fi;
        a[i].se = i;
    }
    sort(all(a));

    vector<E> edge;
    for(int i=1; i<n; ++i){
        int u = a[0].se;
        int v = a[i].se;
        ll w = a[0].fi+a[i].fi;
        edge.pb({w,{u,v}});
    }

    rep(i,m){
        int x,y;
        ll w;
        cin >>x >>y >>w;
        --x;
        --y;
        edge.pb({w,{x,y}});
    }

    sort(all(edge));

    UF uf(n);
    ll ans = 0;
    for(const auto &e:edge){
        ll w = e.fi;
        int u = e.se.fi, v = e.se.se;
        if(!uf.same(u,v)){
            uf.unite(u,v);
            ans += w;
        }
    }
    cout << ans << "\n";
    return 0;
}
