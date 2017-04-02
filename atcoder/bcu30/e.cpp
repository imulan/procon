#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

char s[1010][1010];
int dp[1001][1001]={};

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

int count(int lx, int ly, int rx, int ry)
{
    return dp[ry][rx] - dp[ry][lx-1] - dp[ly-1][rx] + dp[ly-1][lx-1];
}

int convert(int x, int y)
{
    return y*1001+x;
}

int main()
{
    int N,K,Q;
    scanf(" %d %d %d", &N, &K, &Q);
    rep(i,N)rep(j,N) scanf(" %c", &s[i+1][j+1]);

    dp[1][1] = (s[1][1]=='#');
    for(int i=2; i<=N; ++i) dp[1][i] = dp[1][i-1] + (s[1][i]=='#');
    for(int i=2; i<=N; ++i) dp[i][1] = dp[i-1][1] + (s[i][1]=='#');

    for(int i=2; i<=N; ++i)for(int j=2; j<=N; ++j) dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + (s[i][j]=='#');

    UF uf(1001*1001);
    int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};
    #define IN(x,y) (1<=x && x<=N && 1<=y && y<=N)
    for(int i=1; i<=N-K+1; ++i)for(int j=1; j<=N-K+1; ++j)
    {
        if(count(j,i,j+K-1,i+K-1)>0) continue;

        rep(d,4)
        {
            int nx=j+dx[d], ny=i+dy[d];
            if(IN(nx,ny) && IN(nx+K-1,ny+K-1) && count(nx,ny,nx+K-1,ny+K-1)==0)
            {
                uf.unite(convert(j,i),convert(nx,ny));
            }
        }
    }

    while(Q--)
    {
        int r1,c1,r2,c2;
        scanf(" %d %d %d %d", &r1, &c1, &r2, &c2);
        int start = convert(c1,r1), goal = convert(c2,r2);
        if(uf.same(start,goal)) printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}
