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

int main()
{
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);

    vector<int> a(m),b(m),c(m);
    vector<pi> e(m);
    rep(i,m)
    {
        scanf(" %d %d %d", &a[i], &b[i], &c[i]);
        --a[i];
        --b[i];
        e[i] = pi(c[i],i);
    }

    sort(all(e));

    int ans = 0;
    int cc = n;
    UF uf(n);
    rep(i,m)
    {
        if(cc==k) break;

        int id = e[i].se;
        if(!uf.same(a[id],b[id]))
        {
            uf.unite(a[id],b[id]);
            --cc;
            ans += c[id];
        }
    }

    printf("%d\n", ans);
    return 0;
}
