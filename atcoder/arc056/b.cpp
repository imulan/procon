#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

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
    bool unite(int x,int y){
        x=root(x); y=root(y);
        if(x==y) return false;
        if(size(x) < size(y)) swap(x,y);
        d[x]+=d[y];
        d[y]=x;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
};

int main()
{
    int n,m,s;
    cin >>n >>m >>s;
    --s;

    vector<pi> e(m);
    rep(i,m)
    {
        int u,v;
        scanf(" %d %d",&u,&v);
        --u;
        --v;
        if(u>v) swap(u,v);

        e[i]=pi(u,v);
    }
    sort(all(e),greater<pi>());

    //rep(i,m) printf(" %d %d\n", e[i].fi,e[i].se);

    UF t(n);
    vector<int> ans;

    int idx=0;
    for(int i=n-1; i>=0; --i)
    {
        while(idx<m && e[idx].fi>=i)
        {
            t.unite(e[idx].fi,e[idx].se);
            ++idx;
        }

        if(t.root(s)==t.root(i)) ans.pb(i+1);
    }

    reverse(all(ans));
    rep(i,ans.size()) printf("%d\n", ans[i]);
    return 0;
}
