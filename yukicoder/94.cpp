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

int dist(int x1, int y1, int x2, int y2)
{
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

int main()
{
    int n;
    cin >>n;

    if(n==0)
    {
        printf("1\n");
        return 0;
    }

    vector<int> x(n),y(n);
    rep(i,n) scanf(" %d %d", &x[i], &y[i]);

    UF t(n);
    rep(i,n)rep(j,i)
    {
        if(dist(x[i],y[i],x[j],y[j])<=10*10) t.unite(i,j);
    }

    double ans=2;
    rep(i,n)rep(j,i)
    {
        if(t.root(i)==t.root(j)) ans=max(ans,sqrt(dist(x[i],y[i],x[j],y[j]))+2);
    }

    printf("%.10lf\n", ans);
    return 0;
}
