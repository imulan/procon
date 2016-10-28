#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const double eps=1e-10;

int main()
{
    int n,m,L;
    scanf(" %d %d %d", &n, &m, &L);
    vector<int> p(n),t(n),v(n);
    rep(i,n) scanf(" %d %d %d", &p[i], &t[i], &v[i]);

    // i番目の人がj回休憩をする確率、そのときにかかる時間
    double rest[100][51];
    double total[100][51];

    double dp[51][51];
    rep(i,n)
    {
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        rep(j,m)rep(k,j+1)
        {
            dp[j+1][k]+=dp[j][k]*(100-p[i])/100;
            dp[j+1][k+1]+=dp[j][k]*p[i]/100;
        }

        rep(j,m+1)
        {
            rest[i][j]=dp[m][j];
            total[i][j]=(double)L/v[i]+j*t[i];
        }
    }

    double win[100]={0};

    // i番目の人がj回休憩をした時に勝てる確率
    rep(i,n)rep(j,m+1)
    {
        double add=1;
        double mytime=total[i][j];

        rep(k,n)
        {
            if(k==i) continue;

            if(mytime>=total[k][m])
            {
                add=0;
                break;
            }

            int idx=0;
            while(idx<m && mytime>=total[k][idx]) ++idx;

            double q=0;
            for(int l=idx; l<=m; ++l) q+=rest[k][l];

            add*=q;
        }

        win[i]+=add*rest[i][j];
    }

    rep(i,n) printf("%.10f\n", win[i]);
    return 0;
}
