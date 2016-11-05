#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct Magic{ int cost,damage; };
vector<Magic> s,a;

const int N=200000;

const int INF=123456789;
int dp[2][N+1];
void calc(const vector<Magic> &v, int dst[])
{
    int V=v.size();

    fill(dp[0],dp[2],INF);
    dp[0][0]=0;
    rep(i,V)rep(j,N+2)
    {
        if(j-v[i].damage<0) dp[(i+1)&1][j]=dp[i&1][j];
        else dp[(i+1)&1][j]=min(dp[i&1][j],dp[(i+1)&1][j-v[i].damage]+v[i].cost);
    }

    rep(i,N+1) dst[i]=dp[V&1][i];

    int min_cost=INF;
    for(int i=N; i>=0; --i)
    {
        min_cost=min(min_cost,dst[i]);
        dst[i]=min_cost;
    }
}

int main()
{
    int ds[N+1],da[N+1];

    int n;
    while(cin >>n,n)
    {
        s.clear();
        a.clear();

        vector<int> hp(n);
        rep(i,n) cin >>hp[i];

        int m;
        cin >>m;
        rep(i,m)
        {
            string M,sa;
            int mp,d;
            cin >>M >>mp >>sa >>d;

            if(d==0) continue;
            if(d>=N) d=N;

            if(sa=="All") a.pb(Magic{mp,d});
            else s.pb(Magic{mp,d});
        }

        calc(s,ds);
        calc(a,da);

        int ans=INF;

        rep(i,100001)
        {
            bool valid=true;
            int tmp=da[i];
            rep(j,n)
            {
                int rem=hp[j]-i;
                if(rem<=0) continue;
                if(ds[rem]==INF)
                {
                    valid=false;
                    break;
                }
                tmp+=ds[rem];
            }

            if(!valid) continue;
            ans=min(ans,tmp);
        }

        printf("%d\n", ans);
    }
    return 0;
}
