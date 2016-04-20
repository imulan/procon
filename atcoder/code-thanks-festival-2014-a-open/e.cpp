#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(i=0;i<n;++i)
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define mp make_pair
#define pb push_back
#define fi first
#define sc second

struct process{ int ra,rb,ca,cb; };

int main()
{
	int i,j,k;

	int r,c,m,n;
	cin >>r >>c >>m >>n;

	//回転数をカウント
	int f[51][51]={0};

	vector<process> v(n);
	rep(i,n)
	{
		scanf(" %d %d %d %d",&v[i].ra,&v[i].rb,&v[i].ca,&v[i].cb);

		for(j=v[i].ra;j<=v[i].rb;++j)
		for(k=v[i].ca;k<=v[i].cb;++k)
			f[j][k]=(f[j][k]+1)%4;
	}

	vector<int> ans;
	//i番目の手順を忘れたとすると
	rep(i,n)
	{
		int tf[51][51];
		rep(j,r+1)rep(k,c+1) tf[j][k]=f[j][k];

		for(j=v[i].ra;j<=v[i].rb;++j)
		for(k=v[i].ca;k<=v[i].cb;++k)
			tf[j][k]=(tf[j][k]+3)%4;

		int ct=0;
		for(j=1;j<=r;++j)
		for(k=1;k<=c;++k)
			if(tf[j][k]==0) ++ct;

		if(ct==m) ans.pb(i+1);
	}

	for(const auto &x :ans) cout << x << endl;
}
