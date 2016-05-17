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

typedef pair<int,int> pi;

int main()
{
    int x,y,z;
    while(scanf(" %d %d %d",&x,&y,&z),x|y|z)
    {
        //ルーレットの目
        vector<int> v(x);
        rep(i,x) scanf(" %d", &v[i]);

        //iマス目で起こるイベント
        vector<pi> event(y+1,pi(0,0));
        rep(i,z)
        {
            int n,e,a;
            scanf(" %d %d %d",&n,&e,&a);
            event[n]=pi(e,a);
        }

        //iマスに所持金j円でいる確率
        double dp[51][5000]={0};
        dp[0][0]=1;

        rep(i,y)
        {
            rep(j,x)
            {
                int next=i+v[j];
                if(next>y)
                {
                    //goal
                    rep(k,5000) dp[y][k]+=dp[i][k]/x;
                }
                else
                {
                    if(event[next].fi==0)
                    {
                        //no event
                        rep(k,5000) dp[next][k]+=dp[i][k]/x;
                    }
                    else if(event[next].fi==1)
                    {
                        //go ahead
                        next+=event[next].se;
                        next=min(next,y);
                        rep(k,5000) dp[next][k]+=dp[i][k]/x;
                    }
                    else if(event[next].fi==2)
                    {
                        //earn money
                        for(int k=0; k+event[next].se<5000; ++k)
                        dp[next][k+event[next].se]+=dp[i][k]/x;
                    }
                    else if(event[next].fi==3)
                    {
                        //lose money
                        rep(k,event[next].se) dp[next][0]+=dp[i][k]/x;
                        for(int k=event[next].se; k<5000; ++k)
                        dp[next][k-event[next].se]+=dp[i][k]/x;
                    }
                }
            }
        }

        double ans=0;
        rep(i,5000) ans+=i*dp[y][i];
        printf("%d\n", (int)ans);
    }
    return 0;
}
