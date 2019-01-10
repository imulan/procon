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

using pd = pair<double,int>;

int main(){
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> a(m),b(m),c(m),d(m);
    rep(i,m) scanf(" %d %d %d %d", &a[i], &b[i], &c[i], &d[i]);

    auto check = [&](double x){
        vector<pd> v(m);
        rep(i,m) v[i] = {x*c[i]-d[i], i};

        sort(all(v));

        UF uf(n);
        double tmp = 0;
        rep(i,m){
            int vi = v[i].se;
            int p = a[vi], q = b[vi];
            if(uf.same(p,q)) tmp += v[i].fi;
            else uf.unite(p,q);
        }

        return tmp >= 0;
    };

    double l=0, r=1e11;
    rep(loop,70){
        double mid = (l+r)/2;
        if(check(mid)) r = mid;
        else l = mid;
    }
    printf("%.10f\n", r);
    return 0;
}
