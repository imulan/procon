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
	int n,k;
	cin >>n >>k;

	vector<int> x(n);
	int id[100001]={0};
	rep(i,n)
	{
		scanf(" %d",&x[i]);
		id[x[i]]=i+1;
	}

	vector<int> ans;
	int now=k;
	for(int i=n-1; i>=k-1; --i)
	{
		//printf(" %d: %d\n",i, now);
		ans.pb(id[now]);
		if(x[i]<=now) ++now;

		while(id[now]>i) ++now;
	}

	reverse(all(ans));
	for(const auto &v : ans) printf("%d\n",v);

	return 0;
}
