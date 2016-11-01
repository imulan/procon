#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=123456789;

int n,m;
int R;
int z[1001];

int ld[200][200],sd[200][200];

vector<int> island[200];
int island_id[200];

ll dp[1001][200];

void init()
{
    fill(ld[0],ld[200],INF);
    fill(sd[0],sd[200],INF);
    rep(i,200) island[i].clear();
    fill(island_id,island_id+200,-1);
    fill(dp[0],dp[1001],10000LL*INF);
}

void Warshall_Floyd()
{
    rep(i,n)
    {
        ld[i][i]=0;
        sd[i][i]=0;
    }
    rep(k,n)rep(i,n)rep(j,n)
    {
        ld[i][j]=min(ld[i][j],ld[i][k]+ld[k][j]);
        sd[i][j]=min(sd[i][j],sd[i][k]+sd[k][j]);
    }
}

void divide()
{
    int island_idx=0;
    rep(i,n)
    {
        if(island_id[i]!=-1) continue;

        island_id[i]=island_idx;
        rep(j,n) if(ld[i][j]<INF) island_id[j]=island_idx;

        ++island_idx;
    }
    rep(i,n) island[island_id[i]].pb(i);
}

int main()
{
    while(scanf(" %d %d",&n,&m),n)
    {
        init();

        // input
        rep(i,m)
        {
            int x,y,t;
            char sl;
            scanf(" %d %d %d %c",&x,&y,&t,&sl);
            --x;
            --y;
            if(sl=='L') ld[x][y]=ld[y][x]=min(ld[x][y],t);
            else sd[x][y]=sd[y][x]=min(sd[x][y],t);
        }
        scanf(" %d",&R);
        rep(i,R)
        {
            scanf(" %d",&z[i]);
            --z[i];
        }

        Warshall_Floyd();

        // determine the island i-th town belongs
        divide();

        // calc ans
        dp[0][z[0]]=0;
        for(int i=1; i<R; ++i)
        {
            int p_id=island_id[z[i-1]], c_id=island_id[z[i]];
            if(p_id==c_id)
            {
                rep(j,island[p_id].size())
                {
                    int boat=island[p_id][j];
                    dp[i][boat] = min(dp[i][boat], dp[i-1][boat]+ld[z[i-1]][z[i]]);
                }
            }
            rep(j,island[p_id].size())rep(k,island[c_id].size())
            {
                int now_b=island[p_id][j], nx_b=island[c_id][k];
                dp[i][nx_b] = min(dp[i][nx_b], dp[i-1][now_b]+ld[z[i-1]][now_b]+sd[now_b][nx_b]+ld[nx_b][z[i]]);
            }
        }

        ll ans=10000LL*INF;
        rep(i,n) ans=min(ans,dp[R-1][i]);
        printf("%lld\n", ans);
    }
    return 0;
}
