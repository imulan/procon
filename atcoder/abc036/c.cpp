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
	int n;
	cin >>n;

	vector<int> a(n);
	rep(i,n) scanf(" %d", &a[i]);

	vector<int> b(a);
	sort(all(b));
	b.erase(unique(all(b)),b.end());

	rep(i,n)
	{
		int ans=lower_bound(all(b),a[i])-b.begin();
		std::cout << ans << std::endl;
	}

	return 0;
}
