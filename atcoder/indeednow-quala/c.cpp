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

	int ct[1000002]={0};
	rep(i,n)
	{
		int s;
		scanf(" %d", &s);
		if(s>0) ++ct[s];
	}

	for(int i=1000001; i>0; --i) ct[i-1]+=ct[i];
	rep(i,1000002) ct[i]=-ct[i];

	//query
	int q;
	cin >>q;
	rep(Q,q)
	{
		int k;
		cin >>k;
		int ans=lower_bound(ct,ct+1000002,-k)-ct;
		std::cout << ans << std::endl;
	}
	return 0;
}
