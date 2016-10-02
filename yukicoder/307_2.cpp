#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

struct UF{
    // Graph
    set<int> G[40000];

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

        G[X].insert(G[Y].begin(), G[Y].end());
        G[Y].clear();

        return true;
    }
    int size(int v){ return -d[root(v)]; }
};

int h,w;
int a[200][200];

// connected component
int cc[200][200];
int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
int col[40000];

int main()
{
    scanf(" %d %d", &h, &w);
    rep(i,h)rep(j,w) scanf(" %d", &a[i][j]);

    // BFS
    #define IN(x,y) (0<=x && x<w && 0<=y && y<h)
    memset(cc,-1,sizeof(cc));
    int cc_num=0;
    rep(y,h)rep(x,w)
    {
        if(cc[y][x]>=0) continue;

        queue<pi> que;
        que.push(pi(y,x));
        cc[y][x]=cc_num;
        while(!que.empty())
        {
            pi now=que.front();
            que.pop();
            rep(i,4)
            {
                int nx=now.se+dx[i], ny=now.fi+dy[i];
                if(IN(nx,ny) && a[ny][nx]==a[now.fi][now.se] && cc[ny][nx]==-1)
                {
                    cc[ny][nx]=cc_num;
                    que.push(pi(ny,nx));
                }
            }
        }

        ++cc_num;
    }

    UF uf(cc_num);

    // グラフ構成
    rep(y,h)rep(x,w)
    {
        col[cc[y][x]] = a[y][x];
        rep(i,4)
        {
            int nx=x+dx[i], ny=y+dy[i];
            if(IN(nx,ny) && cc[y][x]!=cc[ny][nx])
            {
                int p=cc[y][x], q=cc[ny][nx];
                uf.G[p].insert(q);
                uf.G[q].insert(p);
            }
        }
    }

    // rep(i,h)
    // {
    //     rep(j,w) printf("%3d", cc[i][j]);
    //     printf("\n");
    // }
    // rep(i,cc_num)
    // {
    //     printf(" %d(col=%d) :", i,col[i]);
    //     for(const int &j:G[i]) printf(" %d", j);
    //     printf("\n");
    // }

    // クエリ処理
    int Q;
    scanf(" %d", &Q);
    while(Q--)
    {
        int r,c,x;
        scanf(" %d %d %d", &r, &c, &x);
        --r;
        --c;

        if(x == col[ uf.root(cc[r][c]) ]) continue;

        vector<int> tmp(uf.G[uf.root(cc[r][c])].begin(), uf.G[uf.root(cc[r][c])].end());

        for(auto &i:tmp) i=uf.root(i);
        sort(all(tmp));
        tmp.erase(unique(all(tmp)), tmp.end());

        uf.G[uf.root(cc[r][c])].clear();
        uf.G[uf.root(cc[r][c])].insert(all(tmp));

        set<int> tmpG=uf.G[uf.root(cc[r][c])];
        for(const int &nx:tmpG)
        {
            if(col[uf.root(nx)]==x)
            {
                uf.unite(uf.root(cc[r][c]),uf.root(nx));
            }
        }

        col[uf.root(cc[r][c])] = x;

        // printf(" process: %d\n",Q);
        // rep(i,cc_num)
        // {
        //     printf(" %d(col=%d) :", i,col[i]);
        //     for(const int &j:G[i]) printf(" %d", j);
        //     printf("\n");
        // }
    }

    // rep(y,h)rep(x,w) printf("%d,%d -> root: %d\n", y,x,uf.root(cc[y][x]) );

    // 出力
    rep(y,h)
    {
        rep(x,w)
        {
            if(x) printf(" ");
            printf("%d", col[uf.root(cc[y][x])]);
        }
        printf("\n");
    }
    return 0;
}
