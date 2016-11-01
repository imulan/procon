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

int dp[5][4][101];
int nx[5][4][101];
int b[50500];

inline void init()
{
    memset(b,-1,sizeof(b));
    rep(i,5)rep(j,4)rep(k,101) dp[i][j][k]=INF;
}

int main()
{
    int n;
    while(cin >>n,n)
    {
        init();

        map<int,int> num;
        vector<int> P(n), T(n);
        rep(i,n)
        {
            scanf(" %d %d", &P[i], &T[i]);
            b[T[i]]=P[i];
            num[T[i]]=i;
        }

        int ans=-1;
        bool fail=false;
        dp[1][0][0]=0;
        for(int t=1; t<50500; ++t)
        {
            rep(w,4)
            {
                if(b[t]==-1)
                {
                    bool ok=(t-(w+1)>=0);
                    if(ok)
                    {
                        for(int i=t; i>t-(w+1); --i) if(b[i]!=-1) ok=false;
                    }

                    if(ok) dp[0][0][0]=min(dp[0][0][0],dp[w+1][w][1]+1);

                    for(int pos=1; pos<=100; ++pos)
                    {
                        dp[0][w][pos]=min(dp[0][w][pos],dp[1][w][pos]);
                        if(ok)
                        {
                            dp[0][w][pos]=min(dp[0][w][pos],dp[w+1][w][pos-1]+1);
                            if(pos+1<=100) dp[0][w][pos]=min(dp[0][w][pos],dp[w+1][w][pos+1]+1);
                        }
                    }
                }
                else
                {
                    int b_idx=num[t];
                    int pos=b[t];
                    if(w<3)
                    {
                        dp[0][w+1][pos]=min(dp[0][w+1][pos],dp[1][w][pos]);

                        if( t-(w+1)>=0 && (b_idx==0 ||(b_idx>0 && t-(w+1)>=T[b_idx-1])) )
                        {
                            if(pos-1>=0) dp[0][w+1][pos]=min(dp[0][w+1][pos],dp[w+1][w][pos-1]+1);
                            if(pos+1<=100) dp[0][w+1][pos]=min(dp[0][w+1][pos],dp[w+1][w][pos+1]+1);
                        }
                    }
                }
            }

            if(b[t]!=-1)
            {
                // printf("  %d th balloon, (%d,%d)\n", num[t],P[num[t]],T[num[t]]);
                bool c=false;
                rep(j,4)
                {
                    // printf(" %d, %d\n",j,dp[0][j][b[t]] );
                    if(dp[0][j][b[t]]<INF) c=true;
                }
                if(!c)
                {
                    fail=true;
                    ans=num[t]+1;
                    break;
                }
            }

            for(int i=4; i>0; --i)rep(j,4)rep(k,101) dp[i][j][k]=dp[i-1][j][k];
            rep(i,4)rep(j,101) dp[0][i][j]=INF;
        }

        if(fail) printf("NG %d\n", ans);
        else printf("OK %d\n", dp[1][0][0]);
    }
    return 0;
}
