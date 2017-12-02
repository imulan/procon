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

const int N=100000;

int n,m;
int a[N],b[N];
int Q;
int x[N],y[N];

int l[N],r[N];
vector<int> query[N+10];

int main()
{
    cin >>n >>m;
    rep(i,m)
    {
        cin >>a[i] >>b[i];
        --a[i];
        --b[i];
    }
    cin >>Q;
    rep(i,Q)
    {
        cin >>x[i] >>y[i];
        --x[i];
        --y[i];
    }

    rep(i,Q)
    {
        l[i]=-1;
        r[i]=m;
    }

    rep(loop,17)
    {
        rep(i,N+10) query[i].clear();
        rep(i,Q) query[(l[i]+r[i])/2].pb(i);

        UF uf(n);
        rep(i,m)
        {
            uf.unite(a[i],b[i]);
            for(int id:query[i])
            {
                if(uf.same(x[id],y[id])) r[id]=i;
                else l[id]=i;
            }
        }
    }

    rep(i,Q)
    {
        int ans = r[i]+1;
        if(ans==m+1) ans = -1;
        cout << ans << endl;
    }
    return 0;
}
