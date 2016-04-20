#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

ll a[1000][1000];
ll b[1000][1000];
ll c[1000][1000];

const double EPS=1e-4;

int main()
{
	int i,j;

	int n;
	cin >>n;

	rep(i,n)rep(j,n) scanf(" %lld",&a[i][j]);
	rep(i,n)rep(j,n) scanf(" %lld",&b[i][j]);
	rep(i,n)rep(j,n) scanf(" %lld",&c[i][j]);

	string ans="NO";
	if(n==1)
	{
		if(a[0][0]*b[0][0]==c[0][0]) ans="YES";
	}
	else
	{
		bool valid=true;
		for(int Q=0; Q<100; ++Q)
		{
			ll r[1000];
			rep(i,n) r[i]=rand()%10000;

			ll r1[1000]={0};
			ll r2[1000]={0};
			ll r3[1000]={0};
			//B*r
			rep(i,n)rep(j,n) r1[i]+=b[i][j]*r[j];
			//A*r1
			rep(i,n)rep(j,n) r2[i]+=a[i][j]*r1[j];
			//C*r
			rep(i,n)rep(j,n) r3[i]+=c[i][j]*r[j];

			rep(i,n)
			{
				if(r2[i]!=r3[i]) valid=false;
			}

			if(!valid) break;
		}

		if(valid) ans="YES";
	}

	std::cout << ans << std::endl;
}
