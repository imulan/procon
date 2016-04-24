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
	int n,m,t;
	cin >>n >>m >>t;
	vector<int> a(n);
	rep(i,n) cin >>a[i];

	int b[10001]={0};
	rep(i,n)
	{
		++b[a[i]-m];
		--b[min(t,a[i]+m)];
	}

	rep(i,t) b[i+1]+=b[i];
	//rep(i,t) printf("%d, %d\n",i,b[i]);

	int ans=0;
	rep(i,t) ans+=(b[i]==0);
	std::cout << ans << std::endl;

	return 0;
}
