#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

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
    int n,m;
    scanf(" %d %d", &n, &m);

    UF uf(n+m);

    rep(i,n)
    {
        int k;
        scanf(" %d", &k);
        rep(j,k)
        {
            int L;
            scanf(" %d", &L);
            --L;
            uf.unite(i,n+L);
        }
    }

    string ans="YES";
    rep(i,n) if(!uf.same(0,i)) ans="NO";
    cout << ans << endl;
    return 0;
}
