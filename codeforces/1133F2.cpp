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

int main(){
    int n,m,d;
    scanf(" %d %d %d", &n, &m, &d);

    vector<pi> R,E;
    rep(i,m){
        int u,v;
        scanf(" %d %d", &u, &v);
        --u;
        --v;
        if(u>v) swap(u,v);

        if(u==0) R.pb({u,v});
        else E.pb({u,v});
    }

    UF uf(n);
    int cc = n;
    for(pi p:E){
        if(uf.unite(p.fi,p.se)) --cc;
    }

    if(cc-1<=d && d<=R.size()){
        printf("YES\n");

        vector<pi> ans;
        int ct = 0;

        UF ufa(n);
        for(pi p:R){
            if(uf.unite(p.fi,p.se)){
                ans.pb(p);
                ++ct;
                ufa.unite(p.fi,p.se);
            }
        }

        for(pi p:R){
            if(ct == d) break;
            if(ufa.unite(p.fi,p.se)){
                ans.pb(p);
                ++ct;
            }
        }

        for(pi p:E)if(ufa.unite(p.fi,p.se)) ans.pb(p);

        for(pi p:ans) printf("%d %d\n", p.fi+1, p.se+1);
    }
    else printf("NO\n");
    return 0;
}
