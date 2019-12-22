#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
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
using E = pair<ll,pi>;

int main(){
    int n;
    cin >>n;
    vector<ll> x(n),y(n),c(n),k(n);
    rep(i,n) cin >>x[i] >>y[i];
    rep(i,n) cin >>c[i];
    rep(i,n) cin >>k[i];

    vector<E> edge;
    rep(i,n) edge.pb({c[i],{i,n}});
    rep(i,n)rep(j,i){
        ll cost = abs(x[i]-x[j])+abs(y[i]-y[j]);
        cost *= (k[i]+k[j]);
        edge.pb({cost,{j,i}});
    }
    sort(all(edge));

    UF uf(n+1);
    ll ans = 0;
    vector<int> power;
    vector<pi> connect;
    for(const auto &e:edge){
        int u = e.se.fi, v = e.se.se;
        if(uf.unite(u,v)){
            if(v == n) power.pb(u);
            else connect.pb(e.se);
            ans += e.fi;
        }
    }

    // output
    cout << ans << "\n";

    int P = power.size();
    cout << P << "\n";
    rep(i,P) cout << power[i]+1 << " \n"[i==P-1];

    cout << connect.size() << "\n";
    for(pi p:connect) cout << p.fi+1 << " " << p.se+1 << "\n";
    return 0;
}
