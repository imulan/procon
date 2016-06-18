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
typedef pair<int,pi> edge;
typedef pair<pi,int> query;

const int N=100000;

int par[N];
int r[N];
int ct[N];

void init(int n)
{
    rep(i,n)
    {
        par[i]=i;
        r[i]=0;
        ct[i]=1;
    }
}

int find(int x)
{
    if(par[x]==x) return x;
    else return par[x]=find(par[x]);
}

void unite(int x,int y)
{
    x=find(x);
    y=find(y);
    if(x==y) return;

    if(r[x]<r[y])
    {
        par[x]=y;
        ct[y]+=ct[x];
    }
    else
    {
        par[y]=x;
        ct[x]+=ct[y];
        if(r[x]==r[y]) ++r[x];
    }

}

int main()
{
    int n,m;
    cin >>n >>m;

    vector<edge> e;
    rep(i,m)
    {
        int a,b,y;
        scanf(" %d %d %d",&a,&b,&y);
        --a;
        --b;
        e.pb(edge(-y,pi(a,b)));
    }

    //新しい順にソート
    sort(all(e));
    rep(i,m) e[i].fi=-e[i].fi;

    //初期化
    init(n);

    //クエリに答える
    int q;
    cin >>q;

    vector<query> qu(q);
    vector<int> ans(q);

    rep(Q,q)
    {
        int v,w;
        scanf(" %d %d",&v,&w);
        --v;
        qu[Q]=query(pi(-w,v),Q);
    }

    sort(all(qu));
    rep(i,q) qu[i].fi.fi=-qu[i].fi.fi;

    int idx=0;
    rep(i,q)
    {
        while(idx<m)
        {
            if(qu[i].fi.fi >= e[idx].fi) break;

            int x=e[idx].se.fi;
            int y=e[idx].se.se;
            //printf(" u %d %d\n", x,y);
            unite(x,y);
            ++idx;
        }

        int start=qu[i].fi.se;
        ans[qu[i].se]=ct[find(start)];
    }

    rep(i,q) printf("%d\n", ans[i]);
    return 0;
}
