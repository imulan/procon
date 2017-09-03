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

using pi = pair<int,int>;

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
    int n,m,q;
    cin >>n >>m >>q;

    set<pi> s;
    rep(i,100000)
    {
        int u = i%n, v = i%m;
        if(s.count({u,n+v})) break;
        s.insert({u,n+v});
    }
    // for(pi p:s) dbg(p);

    UF uf(n+m);
    rep(i,q)
    {
        int c,d;
        cin >>c >>d;
        --c;
        --d;
        uf.unite(c,n+d);
    }

    int ans = 0;
    while(1)
    {
        bool ok = false;
        for(pi p:s) ok |= !uf.same(p.fi,p.se);
        if(!ok) break;

        int u = ans%n, v = ans%m;
        uf.unite(u,n+v);

        ++ans;
    }
    printf("%d\n", ans);
    return 0;
}
