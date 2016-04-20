#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

//(現在注目している人,とにかく座りたい人だけ座れる席の数,誰でも座れる席の区間開始位置)
double dp[101][205][205]={0};

int main()
{
	int i,j,k;

	int n,K;
	cin >>n>>K;
	vector<int> p(n);
	rep(i,n) cin >>p[i];

	//最初の人は絶対に席1に座る
	if(K==1) printf("0\n");
	else
	{
		dp[0][1][3]=1.0;
		for(i=1; i<n; ++i)
		{//i番目の人に注目

			//j=1のときにとにかく座りたい場合、kの1つ左に座ることになるのでkが1つ進む
			for(k=3; k<=K+1; ++k)
				dp[i][1][k] += dp[i-1][1][k-1]*p[i]/100;

			for(j=1; j<=K; ++j)
			{//とにかく座りたい人だけ座れる席j個
				for(k=3; k<=K+1; ++k)
				{//誰でも座れる席の区間開始位置
					//とにかく座りたい
					dp[i][j][k] += dp[i-1][j+1][k]*p[i]/100;
					//余裕なら座りたい
					dp[i][j][k] += dp[i-1][j-1][k-2]*(100-p[i])/100;
				}

				//余裕なら座りたい
				dp[i][j][K+1] += dp[i-1][j][K]*(100-p[i])/100;
				//でも座れない
				dp[i][j][K+1] += dp[i-1][j][K+1]*(100-p[i])/100;
			}
		}

		double ans=0.0;

		rep(i,K)rep(j,K+2)
			ans+=(i+(K+1-j))*dp[n-1][i][j];

		printf("%.10lf\n",ans);
	}

}
