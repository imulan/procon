#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

int n;
int x[24],y[24],r[24],c[24];

inline bool intersect(int p, int q)
{
    double dist=sqrt((x[p]-x[q])*(x[p]-x[q])+(y[p]-y[q])*(y[p]-y[q]));
    return dist<(r[p]+r[q]);
}

inline bool available(int p, int state)
{
    rep(i,p)
    {
        if(state>>i&1 && intersect(p,i)) return false;
    }
    return true;
}

char dp[1<<24];
char dfs(int state)
{
    if(dp[state]>=0) return dp[state];
    if(__builtin_popcount(state)<2) return 0;

    char ret=(char)0;
    rep(i,n)
    {
        if(state>>i&1)
        {
            if(!available(i,state)) continue;

            rep(j,n)
            {
                if(i==j) continue;
                if(c[i]!=c[j]) continue;

                if(state>>j&1)
                {
                    if(!available(j,state)) continue;
                    ret = max(ret,(char)(dfs(state-(1<<i)-(1<<j))+2));
                }
            }
        }
    }

    return dp[state]=ret;
}

int main()
{
    while(cin >>n,n)
    {
        rep(i,n) scanf(" %d %d %d %d", &x[i], &y[i], &r[i], &c[i]);
        memset(dp,(char)-1,sizeof(dp));
        cout << (int)dfs((1<<n)-1) << endl;
    }
    return 0;
}
