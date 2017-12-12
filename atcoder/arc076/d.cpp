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

int main()
{
    int n;
    cin >>n;
    vector<int> x(n),y(n);
    rep(i,n) cin >>x[i] >>y[i];

    vector<int> sx,sy;
    map<int,vector<int>> mx,my;

    rep(i,n)
    {
        sx.pb(x[i]);
        mx[x[i]].pb(i);
        sy.pb(y[i]);
        my[y[i]].pb(i);
    }

    sort(all(sx));
    sx.erase(unique(all(sx)),sx.end());
    sort(all(sy));
    sy.erase(unique(all(sy)),sy.end());
    int SX = sx.size(), SY = sy.size();

    ll ans = 0;
    UF uf(n);
    rep(i,SX)
    {
        vector<int> v = mx[sx[i]];
        int V = v.size();
        rep(j,V-1) uf.unite(v[j],v[j+1]);
    }
    rep(i,SY)
    {
        vector<int> v = my[sy[i]];
        int V = v.size();
        rep(j,V-1) uf.unite(v[j],v[j+1]);
    }

    using P = pair<int,pair<int,int>>;
    vector<P> d;
    rep(i,SX-1) d.pb({sx[i+1]-sx[i],{sx[i],sx[i+1]}});
    rep(i,SY-1) d.pb({sy[i+1]-sy[i],{-sy[i],-sy[i+1]}});
    sort(all(d));
    rep(i,d.size())
    {
        pair<int,int> p=d[i].se;

        int v,u;
        if(p.fi+p.se>=0)
        {
            v=mx[p.fi][0];
            u=mx[p.se][0];
        }
        else
        {
            v=my[-p.fi][0];
            u=my[-p.se][0];
        }

        if(!uf.same(v,u))
        {
            uf.unite(v,u);
            ans += d[i].fi;
        }
    }

    assert(uf.size(0)==n);
    cout << ans << endl;
    return 0;
}
