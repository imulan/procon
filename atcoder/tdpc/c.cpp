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

inline double win(int me, int enemy)
{
    return 1.0/(1.0+pow(10,(enemy-me)/400.0));
}

int main()
{
    int pw[11];
    pw[0]=1;
    for(int i=1; i<=10; ++i) pw[i]=pw[i-1]*2;

    int k;
    cin >>k;
    vector<int> rate(pw[k]);
    rep(i,pw[k]) scanf(" %d", &rate[i]);

    //人iがラウンドjを勝つ確率
    double dp[1024][11];

    rep(i,pw[k]) dp[i][0]=1;

    //ラウンドi
    for(int i=1; i<=k; ++i)
    {
        //人jについて
        rep(j,pw[k])
        {
            int block=j/pw[i];
            int id=j%pw[i];

            int l,r;
            if(id<pw[i]/2)
            {
                l=block*pw[i]+pw[i]/2;
                r=(block+1)*pw[i]-1;
            }
            else
            {
                l=block*pw[i];
                r=block*pw[i]+pw[i]/2-1;
            }
            //printf("round %d, man %d: l=%d, r=%d\n", i,j,l,r);

            dp[j][i]=0;
            //ラウンドiで対戦候補になる人x
            for(int x=l; x<=r; ++x)
            {
                dp[j][i]+=dp[j][i-1]*dp[x][i-1]*win(rate[j],rate[x]);
            }
        }
    }

    rep(i,pw[k]) printf("%.10lf\n", dp[i][k]);

    return 0;
}
