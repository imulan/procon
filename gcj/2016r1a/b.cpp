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

int main()
{
	int T;
	cin >>T;
	rep(t,T)
	{
		int n;
		cin >>n;
		vector< vector<int> > v(2*n-1, vector<int>(n) );
		rep(i,2*n-1)rep(j,n) scanf(" %d", &v[i][j]);

		sort(all(v));
		rep(i,2*n-1)
		{
			rep(j,n) printf(" %d",v[i][j]);
			printf("\n");
		}

		//field
		vector< vector<int> > f(n, vector<int>(n) );
		//1列目をセット
		rep(i,n) f[i][0]=v[0][i];



		vector<int> ans(n);



		printf("Case #%d:",t+1);
		rep(i,n) printf(" %d",ans[i]);
		printf("\n");
	}
	return 0;
}
