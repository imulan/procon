#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define x first
#define y second

typedef pair<ll,ll> P;

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
};

ll dist2(P a, P b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main()
{
    int n;
    cin >>n;
    vector<P> p(n);
    rep(i,n) cin >>p[i].x >>p[i].y;

    ll l=0, r=2000000000;
    while(r-l>1)
    {
        ll med=(l+r)/2;

        UF t(n);
        rep(i,n)rep(j,i)
        {
            if(dist2(p[i],p[j])<=med*med) t.unite(i,j);
        }

        if(t.root(0)==t.root(n-1)) r=med;
        else l=med;
    }

    if(r%10!=0) r+=10-r%10;
    cout << r << endl;
    return 0;
}
