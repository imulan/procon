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

int n,k;
double p[200];

double dp[201][201][401]={0};
//x人目まで決定，y人選んだ，投票状態z(200がイーブン)
double rec(int x, int y, int z)
{
    if(dp[x][y][z]>0) return dp[x][y][z];

    printf("x=%d, y=%d, z=%d\n", x,y,z);

    if(x==n)
    {
        if(y==k && z==200) return 1.0;
        else return 0.0;
    }

    //選ばない
    double ret=rec(x+1,y,z);
    //選ぶ
    double tmp=0;
    if(y<k) tmp=rec(x+1,y+1,z+1)*p[x]+rec(x+1,y+1,z-1)*(1.0-p[x]);
    ret=max(ret,tmp);

    return dp[x][y][z]=ret;
}

int main()
{
    int T;
    cin >>T;
    rep(t,T)
    {
        cin >>n >>k;
        rep(i,n) scanf(" %lf", &p[i]);

        memset(dp,0,sizeof(dp));
        double ans=rec(0,0,200);

        printf("Case #%d: ", t+1);
        printf("%.10lf\n", ans);
    }
    return 0;
}
