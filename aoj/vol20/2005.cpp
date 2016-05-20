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

typedef vector<int> vi;

int main()
{
    const int INF=12345678;
    int n,m,s,g1,g2;
    while(scanf(" %d %d %d %d %d",&n,&m,&s,&g1,&g2),n)
    {
        //Graph
        vector<vi> G(n,vi(n,INF));
        rep(i,n) G[i][i]=0;

        rep(i,m)
        {
            int a,b,c;
            scanf(" %d %d %d",&a,&b,&c);
            --a;
            --b;
            G[a][b]=c;
        }

        //Warshall-Floyd
        rep(k,n)rep(i,n)rep(j,n) G[i][j]=min(G[i][j],G[i][k]+G[k][j]);

        int ans=INF;
        rep(i,n) ans=min(ans,G[s-1][i]+G[i][g1-1]+G[i][g2-1]);
        printf("%d\n", ans);
    }
    return 0;
}
