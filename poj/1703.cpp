#include <iostream>
#include <cstdio>
#include <vector>
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
    int T;
    scanf(" %d", &T);
    while(T--)
    {
        int n,m;
        scanf(" %d %d", &n, &m);

        UF uf(2*n);

        while(m--)
        {
            char c;
            int a,b;
            scanf(" %c %d %d", &c, &a, &b);
            --a;
            --b;
            if(c=='A')
            {
                if(!uf.same(a,n+b) && !uf.same(a,b)) printf("Not sure yet.\n");
                else
                {
                    if(uf.same(a,b)) printf("In the same gang.\n");
                    else if(uf.same(a,n+b)) printf("In different gangs.\n");
                }
            }
            else
            {
                uf.unite(a,n+b);
                uf.unite(n+a,b);
            }
        }
    }
    return 0;
}
