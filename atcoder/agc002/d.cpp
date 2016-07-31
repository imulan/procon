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
typedef vector<int> vi;

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

int main()
{
    int n,m;
    cin >>n >>m;

    vector<int> a(m),b(m);
    rep(i,m)
    {
        scanf(" %d %d", &a[i], &b[i]);
        --a[i];
        --b[i];
    }

    int q;
    cin >>q;
    vector<int> x(q), y(q), z(q);
    rep(i,q)
    {
        scanf(" %d %d %d", &x[i], &y[i], &z[i]);
        --x[i];
        --y[i];
    }

    //クエリを並列に二分探索する
    vector<int> l(q,0), r(q,m);
    rep(times,18)
    {
        //pivotの位置をクエリごとに分割
        vector<vi> s(m+1);
        rep(i,q) s[(l[i]+r[i])/2].pb(i);

        UF u(n);
        //枝を1つずつつないでいく
        rep(i,m)
        {
            u.unite(a[i],b[i]);
            for(const auto &j: s[i])
            {
                int reach=0;
                if(u.root(x[j])==u.root(y[j])) reach=u.size(x[j]);
                else reach=u.size(x[j])+u.size(y[j]);

                if(reach>=z[j]) r[j]=i;
                else l[j]=i;
            }
        }
    }

    rep(i,q) printf("%d\n", r[i]+1);
    return 0;
}
