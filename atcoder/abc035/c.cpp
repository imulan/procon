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
	int n,q;
	cin >>n >>q;
	int ct[200002]={0};

	rep(Q,q)
	{
		int l,r;
		scanf(" %d %d",&l,&r);
		++ct[l];
		--ct[r+1];
	}

	rep(i,n+1) ct[i+1]+=ct[i];

	for(int i=1; i<=n; ++i) printf("%d",ct[i]%2);
	printf("\n");

	return 0;
}
