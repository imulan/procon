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

const int INF=10000000;
const int N=100000;

int n;

int p[N];
bool loop[N];
int f[N];

int dp[N];

int main()
{
    cin >>n;
    rep(i,n) scanf(" %d", &p[i]);

    fill(loop,loop+n,false);
    fill(f,f+n,INF);

    rep(i,n)
    {
        if(f[i]!=INF || loop[i]) continue;

        if(p[i]==0)
        {
            f[i]=i;
            continue;
        }

        if(f[i]==INF)
        {
            bool ok=true;
            set<int> vis;
            vis.insert(i);
            int nx=i+p[i];
            while(p[nx]!=0)
            {
                if(vis.find(nx)!=vis.end())
                {
                    ok=false;
                    break;
                }

                if(f[nx]!=INF)
                {
                    nx=f[nx];
                    break;
                }

                vis.insert(nx);
                nx+=p[nx];
            }

            if(!ok) for(const auto &x :vis) loop[x]=true;
            else
            {
                //printf("i=%d, nx=%d\n", i,nx);
                f[i]=nx;
                for(const auto &x: vis) f[x]=nx;
            }
        }
    }

    //rep(i,n) printf("f[%d]=%d\n",i,f[i]);

    fill(dp,dp+n,INF);

    dp[0]=0;
    queue<int> que;
    que.push(0);
    while(!que.empty())
    {
        int v=que.front();
        que.pop();
        for(int i=1; i<=6; ++i)
        {
            int nx=min(n-1,v+i);
            if(f[nx]==INF) continue;
            nx=f[nx];
            if(dp[nx]>dp[v]+1)
            {
                dp[nx]=dp[v]+1;
                que.push(nx);
            }
        }
    }

    printf("%d\n", dp[n-1]);
    return 0;
}
