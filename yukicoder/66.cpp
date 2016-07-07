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

//強さaが強さbに勝つ確率
inline double win(double a, double b)
{
    return a*a/(a*a+b*b);
}

int main()
{
    //2のべき乗
    int pw[11];
    pw[0]=1;
    for(int i=1; i<=10; ++i) pw[i]=pw[i-1]*2;

    //優勝までの試合数
    int m;
    cin >>m;

    //参加人数
    int n=pw[m];
    //強さ
    vector<double> s(n);
    rep(i,n) scanf(" %lf", &s[i]);

    //プレイヤーiがj回戦を勝ち上がる確率
    double dp[1024][11]={0};
    //初期化
    rep(i,n) dp[i][0]=1;

    //i回戦
    for(int i=1; i<=m; ++i)
    {
        //プレイヤーj
        rep(j,n)
        {
            int b=j/pw[i];

            int l,r;
            if(j%pw[i]<pw[i]/2)
            {
                l=b*pw[i]+pw[i]/2;
                r=b*pw[i]+pw[i]-1;
            }
            else
            {
                l=b*pw[i];
                r=b*pw[i]+pw[i]/2-1;
            }

            //printf("%d, player %d : %d-%d\n", i,j,l,r);
            //対戦相手k
            for(int k=l; k<=r; ++k)
            {
                dp[j][i]+=dp[j][i-1]*dp[k][i-1]*win(s[j],s[k]);
            }

            //printf("dp[%d][%d]= %lf\n", j,i,dp[j][i]);
        }
    }

    printf("%.10lf\n", dp[0][m]);
    return 0;
}
