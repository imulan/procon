#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
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

int f[1000][1000];
int solve()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int n,m;
    cin >>n >>m;

    bool all_black=true;
    rep(i,n)rep(j,m)
    {
        cin >>f[i][j];
        all_black &= (f[i][j]==1);
    }

    if(all_black) return n*m-1;

    #define F(x,y) (y*m+x)
    #define IN(x,y) (0<=x && x<m && 0<=y && y<n)
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

    UF uf(n*m);

    rep(i,n)rep(j,m)if(f[i][j]==1)
    {
        int u = F(j,i);
        rep(d,4)
        {
            int nx=j+dx[d], ny=i+dy[d];
            if(IN(nx,ny) && f[ny][nx]==1)
            {
                int v = F(nx,ny);
                uf.unite(u,v);
            }
        }
    }

    int ans=0;

    rep(i,n)rep(j,m)if(f[i][j]==0)
    {
        set<int> r;
        rep(d,4)
        {
            int nx=j+dx[d], ny=i+dy[d];
            if(IN(nx,ny) && f[ny][nx]==1) r.insert(uf.root(F(nx,ny)));
        }

        int add=0;
        for(const auto &k:r) add += uf.size(k);
        ans = max(ans,add);
    }

    return ans+1;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
