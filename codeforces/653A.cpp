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
	int n;
	cin >>n;

	int ct[1001]={0};
	rep(i,n)
	{
		int t;
		cin >>t;
		++ct[t];
	}

	bool valid=false;
	for(int i=1; i<=998; ++i)
	{
		if(ct[i]>0 && ct[i+1]>0 && ct[i+2]>0) valid=true;
	}


	string ans="NO";
	if(valid) ans="YES";
	std::cout << ans << std::endl;
	return 0;
}
