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

const int N=10000;

int main()
{
    int k;
    cin >>k;

    double ans=0;
    double dp[201]={0};
    dp[0]=1;

    for(int i=1; i<N; ++i)
    {
        double newdp[201]={0};
        rep(j,k)
        {
            for(int x=1; x<=6; ++x)
            {
                if(j+x<=k) newdp[j+x]+=dp[j]/6;
                else newdp[0]+=dp[j]/6;
            }
        }
        ans+=i*newdp[k];
        //printf("%d : %lf\n", i,newdp[k]);
        rep(j,k+1) dp[j]=newdp[j];
    }

    printf("%.10lf\n", ans);
    return 0;
}
