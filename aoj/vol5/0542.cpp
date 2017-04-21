#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<int,pi> edge;

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

const int INF=123456789;
const int N=250000;
int dp[2][N+1];

int main()
{
    int R;
    while(scanf(" %d", &R),R)
    {
        fill(dp[0],dp[2],INF);

        rep(room,2)
        {
            int W,H,X,Y;
            scanf(" %d %d %d %d", &W, &H, &X, &Y);
            --X;
            --Y;

            vector<vi> f(H,vi(W));
            rep(i,H)rep(j,W) scanf(" %d", &f[i][j]);

            #define NUM(x,y) (y*W+x)
            #define IN(x,y) (0<=x && x<W && 0<=y && y<H)
            int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
            vector<edge> e;
            rep(i,H)rep(j,W)
            {
                int u = NUM(j,i);
                rep(k,4)
                {
                    int nx=j+dx[k], ny=i+dy[k];
                    if(IN(nx,ny))
                    {
                        int v = NUM(nx,ny);
                        int cost = max(f[i][j], f[ny][nx]);
                        e.pb(edge(cost,pi(u,v)));
                    }
                }
            }
            sort(all(e));

            dp[room][0] = 0;
            dp[room][1] = 1;
            UF uf(H*W);
            rep(i,e.size())
            {
                int cost = e[i].fi;
                int u = e[i].se.fi, v = e[i].se.se;
                uf.unite(u,v);

                int SZ = uf.size(NUM(X,Y));
                dp[room][SZ] = min(dp[room][SZ],cost);
            }

            for(int i=N; i>0; --i) dp[room][i-1] = min(dp[room][i-1], dp[room][i]);
        }

        int ans = 2*INF;
        rep(i,R+1) ans = min(ans, dp[0][i]+dp[1][R-i]);
        printf("%d\n", ans);
    }
    return 0;
}
