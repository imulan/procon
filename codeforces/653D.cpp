#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp(x,y) make_pair((x),(y))
#define pb(x) push_back(x)
#define fi first
#define se second

int main()
{
	int n,m,x;
	cin >>n >>m >>x;

	double c[50][50]={0};
	rep(i,m)
	{
		int a,b,cap;
		cin >>a >>b >>cap;
		--a;
		--b;
		c[a][b]=cap;
	}

	//1人あたりの荷物の重さ
	double left=0, right=1000000;
	double mi=500000;
	while(fabs(right-left)>1e-11)
	{
		mi=(left+right)/2;
		


	}

	printf("%.10lf\n",mi*x);
	return 0;
}
